/*
* Attribuierte Grammatik
* -- Beispiel aus 185.A48 Uebersetzerbau
* -- Author: Peter Nirschl (#1025647)
* -- E-Mail: e1025647@student.tuwien.ac.at
*/

%{

#include <string.h>
#include "semantic.h"
#include "y.tab.h"

int yyerror(const char*); 

%}

%token END ARRAY OF INT RETURN IF THEN ELSE WHILE DO VAR NOT OR SEMICOLON 
%token LPAREN RPAREN COMMA COLON ASSIGN LESS HASH LBRACK RBRACK
%token MINUS PLUS STAR ID NUM

@attributes {char *name;} ID
@attributes {char *name; long type; struct symT **sym;} vardef pardef
@attributes {char *name; struct symT *sym;} funcdef
@attributes {struct symT *sym;} stats
@attributes {struct symT *sym; struct symT **sym2;} stat
@attributes {struct symT **sym;} params parlist bool btermorlist bterm minus_term plus_term star_term exprlist exprlist1
@attributes {long depth;} type arraylist
@attributes {long type; struct symT **sym;} expr lexpr term

@traversal @preorder varcheck			/* builds the symbol table and sets the types */
@traversal @preorder announceTypeCheck		/* this is just for printing an info message since typcheck is post-order */
@traversal @postorder typcheck			/* all checks related to the type-system go here */

%%

program:	/* epsilon */ 
		| program funcdef SEMICOLON
		@{
		  @varcheck fprintf(stdout, "INFO ----- Starting varcheck traversal for function %s\n", @funcdef.name@);
		  @announceTypeCheck fprintf(stdout, "INFO ----- Starting type check traversal for function %s\n", @funcdef.name@);
		@}
		;

funcdef:	ID LPAREN params RPAREN stats END
		@{ 
		  @i @funcdef.name@ = @ID.name@;
		  @i initSymTab(&@funcdef.sym@);
		  @i @params.sym@ = &@stats.sym@;
		  @i @stats.sym@ = @funcdef.sym@;
		@}
		;

params:		/* epsilon */
		| parlist 
		@{ @i @parlist.sym@ = @params.sym@; @}
		;

parlist:	pardef
		@{ @i @pardef.sym@ = @parlist.sym@; @}
		| parlist COMMA pardef
		@{ 
		  @i @parlist.1.sym@ = @parlist.0.sym@;
		  @i @pardef.sym@ = @parlist.0.sym@;
		@}
		;

pardef:		ID COLON type
		@{
		  @i @pardef.name@ = @ID.name@;
		  @i @pardef.type@ = @type.depth@;
		  @varcheck addSym(@pardef.sym@, @pardef.name@, @pardef.type@);
		  @varcheck checkDuplicate(@pardef.sym@, @pardef.name@);
		@}
		;

vardef:         ID COLON type
		@{
		  @i @vardef.name@ = @ID.name@;
		  @i @vardef.type@ = @type.depth@;
		  @varcheck addSym(@vardef.sym@, @vardef.name@, @vardef.type@);
		@}
		;

type:		INT
		@{ @i @type.depth@ = 0; @}
		| arraylist INT
		@{ @i @type.depth@ = @arraylist.depth@; @}
		;

arraylist:	ARRAY OF
		@{ @i @arraylist.0.depth@ = 1; @}
		| arraylist ARRAY OF
		@{ @i @arraylist.0.depth@ = @arraylist.1.depth@ + 1; @}
		;
	
stats:		/*epsilon */
		| stat SEMICOLON stats
		@{
		  @i @stats.1.sym@ = NULL;
		  @i @stat.sym@ = NULL; 
		  @i @stat.sym2@ = &@stats.1.sym@;
		  @varcheck @stats.1.sym@ = @stats.0.sym@;
		  @varcheck @stat.sym@ = @stats.0.sym@;
		@}
		;

stat:		RETURN expr
		@{
		  @i @expr.sym@ = &@stat.sym@;
		@}
		| IF bool THEN stats ELSE stats END
		@{
		  @i @stats.0.sym@ = NULL;
		  @i @stats.1.sym@ = NULL;
		  @i @bool.sym@ = &@stat.sym@;
		  @varcheck @stats.0.sym@ = @stat.sym@;
		  @varcheck @stats.1.sym@ = @stat.sym@;
		@}
		| IF bool THEN stats END
		@{ 
		  @i @stats.sym@ = NULL; 
		  @i @bool.sym@ = &@stat.sym@;
		  @varcheck @stats.sym@ = @stat.sym@;
		@}
		| WHILE bool DO stats END
		@{ 
		  @i @stats.sym@ = NULL; 
		  @i @bool.sym@ = &@stat.sym@;
		  @varcheck @stats.sym@ = @stat.sym@;
		@}
		| VAR vardef ASSIGN expr
		@{
		  @i @vardef.sym@ = @stat.sym2@;
		  @i @expr.sym@ = &@stat.sym@;
		  @typcheck assertEqual(@vardef.type@, @expr.type@);
		@}
		| lexpr ASSIGN expr
		@{
		  @i @expr.sym@ = &@stat.sym@;
		  @i @lexpr.sym@ = &@stat.sym@;
		  @typcheck assertEqual(@lexpr.type@, @expr.type@);
		@}
		| term
		@{
		  @i @term.sym@ = &@stat.sym@;
		@}
		;

bool:		bterm btermorlist
		@{
		  @i @bterm.sym@ = @bool.sym@;
		  @i @btermorlist.sym@ = @bool.sym@;
		@}
		;

btermorlist:	/* epsilon */
		| btermorlist OR bterm
		@{
		  @i @btermorlist.1.sym@ = @btermorlist.0.sym@;
		  @i @bterm.sym@ = @btermorlist.0.sym@;
		@}
		;

bterm:		LPAREN bool RPAREN
		@{
		  @i @bool.sym@ = @bterm.sym@;
		@}
		| NOT bterm
		@{
		  @i @bterm.1.sym@ = @bterm.0.sym@;
		@}
		| expr LESS expr
		@{
		  @i @expr.0.sym@ = @bterm.sym@;
		  @i @expr.1.sym@ = @bterm.sym@;
		  @typcheck assertInt(@expr.0.type@);
		  @typcheck assertInt(@expr.1.type@);
		@}
		| expr HASH expr
		@{
		  @i @expr.0.sym@ = @bterm.sym@;
		  @i @expr.1.sym@ = @bterm.sym@;
		  @typcheck assertInt(@expr.0.type@);
		  @typcheck assertInt(@expr.1.type@);
		@}
		;

lexpr:		ID				/* variable access writing */
		@{
		  @i @lexpr.type@ = SEM_UNDEFINED;
		  @varcheck @lexpr.type@ = getType(@lexpr.sym@, @ID.name@);
		@}
		| term LBRACK expr RBRACK	/* array access writing  */
		@{
		  @i @lexpr.type@ = SEM_UNDEFINED;
		  @i @term.sym@ = @lexpr.sym@;
		  @i @expr.sym@ = @lexpr.sym@;
		  @typcheck assertInt(@expr.type@);
		  @typcheck assertArray(@term.type@);
		  @typcheck @lexpr.type@ = @term.type@ - 1;
		@}
		;

expr:		term
		@{
		  @i @expr.type@ = SEM_UNDEFINED;
		  @i @term.sym@ = @expr.sym@;
		  @typcheck @expr.type@ = @term.type@;
		@}
		| term MINUS minus_term
		@{
		  @i @expr.type@ = SEM_UNDEFINED;
		  @i @term.sym@ = @expr.sym@;
		  @i @minus_term.sym@ = @expr.sym@;
		  @typcheck assertInt(@term.type@);
		  @typcheck @expr.type@ = @term.type@;
		@}
		| term PLUS plus_term
		@{
		  @i @expr.type@ = SEM_UNDEFINED;
		  @i @term.sym@ = @expr.sym@;
		  @i @plus_term.sym@ = @expr.sym@;
		  @typcheck assertInt(@term.type@);
		  @typcheck @expr.type@ = @term.type@;
		@}
		| term STAR star_term
		@{
		  @i @expr.type@ = SEM_UNDEFINED;
		  @i @term.sym@ = @expr.sym@;
		  @i @star_term.sym@ = @expr.sym@;
		  @typcheck assertInt(@term.type@);
		  @typcheck @expr.type@ = @term.type@;
		@}
		;

minus_term:	term
		@{ 
		  @i @term.sym@ = @minus_term.sym@; 
		  @typcheck assertInt(@term.type@);
		@}
		| term MINUS minus_term
		@{
		  @i @term.sym@ = @minus_term.0.sym@;
		  @i @minus_term.1.sym@ = @minus_term.0.sym@;
		  @typcheck assertInt(@term.type@);
		@}
		;

plus_term:	term
		@{ 
		  @i @term.sym@ = @plus_term.sym@; 
		  @typcheck assertInt(@term.type@);
		@} 
		| term PLUS plus_term
		@{
		  @i @term.sym@ = @plus_term.0.sym@;
		  @i @plus_term.1.sym@ = @plus_term.0.sym@;
		  @typcheck assertInt(@term.type@);
		@}
		;

star_term:	term
		@{ 
		  @i @term.sym@ = @star_term.sym@; 
		  @typcheck assertInt(@term.type@);
		@}
		| term STAR star_term
		@{
		  @i @term.sym@ = @star_term.0.sym@;
		  @i @star_term.1.sym@ = @star_term.0.sym@;
		  @typcheck assertInt(@term.type@);
		@}
		;

term:		LPAREN expr RPAREN
		@{
		  @i @term.type@ = SEM_UNDEFINED;
		  @i @expr.sym@ = @term.sym@;
		  @typcheck @term.type@ = @expr.type@;
		@}
		| NUM				/* numeric literal */
		@{ @i @term.type@ = SEM_INT; @}
		| term LBRACK expr RBRACK	/* array access reading */
		@{
		  @i @term.0.type@ = SEM_UNDEFINED;
		  @i @term.1.sym@ = @term.0.sym@;
		  @i @expr.sym@ = @term.0.sym@;
		  @typcheck assertInt(@expr.type@);
		  @typcheck assertArray(@term.1.type@);
		  @typcheck @term.0.type@ = @term.1.type@ - 1;
		@}
		| ID				/* variable access reading */
		@{
		  @i @term.type@ = SEM_UNDEFINED;
		  @varcheck @term.type@ = getType(@term.sym@, @ID.name@);
		@}
		| ID LPAREN exprlist RPAREN COLON type	/* function call */
		@{
		  @i @term.type@ = @type.depth@;
		  @i @exprlist.sym@ = @term.sym@;
		@}
		;

exprlist:	/* epsilon */
		| exprlist1
		@{
		  @i @exprlist1.sym@ = @exprlist.sym@;
		@}
		;

exprlist1:	expr
		@{ @i @expr.sym@ = @exprlist1.sym@; @}
		| expr COMMA exprlist1
		@{
		  @i @exprlist1.1.sym@ = @exprlist1.0.sym@;
		  @i @expr.sym@ = @exprlist1.0.sym@;
		@}
		;

%%

#include <stdlib.h>
#include <stdio.h>
#include "y.tab.h"

int yyerror(const char *msg) {
	printf("Syntax error\n");
	exit(2);
	return 0;
}

int main() {
	return yyparse();
}
