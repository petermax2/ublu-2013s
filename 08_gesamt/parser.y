/*
* Attribuierte Grammatik
* -- Beispiel aus 185.A48 Uebersetzerbau
* -- Author: Peter Nirschl (#1025647)
* -- E-Mail: e1025647@student.tuwien.ac.at
*/

%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "semantic.h"
#include "y.tab.h"
#include "tree.h"
#include "ast.h" 
#include "memtab.h"

int yyerror(const char*); 

#define BURM_CALL(p) { burm_label((p)); burm_reduce((p), 1);}
#define DEF_IF_NR (-1)
int codeIfCounter = 0;

void printFunctionEpilog() {
	printf("\n\n\tmovq $0, \%rax\n\tleave\n\tret\n\t.cfi_endproc\n"); 
}

void labelIfStart(int number) {
	printf(".L%dS:\n", number);
}

void labelWhileCond(int number) {
	printf(".L%dC:\n", number); 
}

void labelWhileStart(int number) {
	printf("\tjmp .L%dE\n", number);
	printf(".L%dS:\n", number);
}

void labelWhileEnd(int number) {
	printf("\tjmp .L%dC\n.L%dE:\n", number, number);
}

void labelElse(int number) {
	printf("\tjmp .L%dE\n.L%dA:\n", number, number);
}

void labelIfEnd(int number) {
	printf(".L%dE:\n", number);
}
%}

%token END ARRAY OF INT RETURN IF THEN ELSE WHILE DO VAR NOT OR SEMICOLON 
%token LPAREN RPAREN COMMA COLON ASSIGN LESS HASH LBRACK RBRACK
%token MINUS PLUS STAR ID NUM

@attributes {char *name;} ID
@attributes {long val;} NUM
@attributes {char *name; long type;} vardef pardef
@attributes {char *name; Tree ast;} funcdef
@attributes {MemTab memt;} stats 
@attributes {MemTab memt; int ifnr;} elsecode
@attributes {Tree ast; MemTab memvar; MemTab memt; int ifnr;} stat
@attributes {MemTab memp;} params parlist 
@attributes {Tree ast; MemTab memt;} bool bterm 
@attributes {Tree ast; MemTab memt;} minus_term plus_term star_term
@attributes {long depth;} type arraylist
@attributes {long type; Tree ast; MemTab memt;} expr lexpr term

@traversal @preorder    mem2                    /* build memory symbol table / mem1 was removed */
@traversal @preorder	varcheck		/* builds the symbol table and sets the types */
@traversal @postorder 	typcheck		/* all checks related to the type-system go here */
@traversal @postorder	astgen			/* prepare AST */ 
@traversal @preorder	codegen			/* propagate AST to BURG */ 

%%

program:	/* epsilon */
		| funcdefs
		@{ @codegen printf("\t.text\n\n"); @}
		;

funcdefs:	funcdef SEMICOLON
		| funcdefs funcdef SEMICOLON 
		; 

funcdef:	ID LPAREN params RPAREN stats END
		@{ 
		  @i @funcdef.name@ = @ID.name@;
		  @i @funcdef.ast@ = NULL;
		  @i @stats.memt@ = NULL; 
		  @mem2 @stats.memt@ = @params.memp@;
		  @varcheck checkDuplicates(@params.memp@);
		  @astgen @funcdef.ast@ = astFuncdef(@funcdef.name@, @params.memp@);
		  @codegen BURM_CALL(@funcdef.ast@);
		  @codegen @revorder (1) printFunctionEpilog();
		@}
		;

params:		/* epsilon */
		@{ @i @params.memp@ = NULL; @}
		| parlist 
		@{ 
		  @i @params.memp@ = @parlist.memp@;
		@}
		;

parlist:	pardef
		@{ 
		  @i @parlist.memp@ = appendMemParam(NULL, @pardef.name@, @pardef.type@); 
		@}
		| parlist COMMA pardef
		@{ 
		  @i @parlist.0.memp@ = appendMemParam(@parlist.1.memp@, @pardef.name@, @pardef.type@);
		@}
		;

pardef:		ID COLON type
		@{
		  @i @pardef.name@ = @ID.name@;
		  @i @pardef.type@ = @type.depth@;
		@}
		;

vardef:         ID COLON type
		@{
		  @i @vardef.name@ = @ID.name@;
		  @i @vardef.type@ = @type.depth@;
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
		  @i @stats.1.memt@ = NULL; 
		  @i @stat.memt@ = NULL; 
		  @mem2 @stat.memt@ = @stats.0.memt@;
		  @mem2 @stats.1.memt@ = memTransferStats(@stats.0.memt@, @stat.memvar@);
		@}
		;

stat:		RETURN expr
		@{
		  @i @expr.memt@ = NULL; 
		  @i @stat.ast@ = NULL;
		  @i @stat.memvar@ = NULL; 
		  @i @stat.ifnr@ = DEF_IF_NR;
		  @mem2 @expr.memt@ = @stat.memt@;
		  @astgen @stat.ast@ = astReturn(@expr.ast@); 
		  @codegen BURM_CALL(@stat.ast@)
		@}
		| IF bool THEN stats ELSE elsecode END
		@{
		  @i @bool.memt@ = NULL; 
		  @i @stats.memt@ = NULL; 
	 	  @i @elsecode.memt@ = NULL; 
		  @i @stat.ast@ = NULL;
		  @i @stat.memvar@ = NULL;
		  @i @stat.ifnr@ = ++codeIfCounter;
		  @i @elsecode.ifnr@ = @stat.ifnr@;
		  @mem2 @bool.memt@ = @stat.memt@;
		  @mem2 @stats.memt@ = memDeepCopy(@stat.memt@); 
		  @mem2 @elsecode.memt@ = memDeepCopy(@stat.memt@);
		  @astgen passIfNrToChildren(@bool.ast@, @stat.ifnr@, AST_TRUE);
		  @codegen BURM_CALL(@bool.ast@);
		  @codegen labelIfStart(@stat.ifnr@); 
		  @codegen @revorder (1) labelIfEnd(@stat.ifnr@); 
		@}
		| IF bool THEN stats END
		@{ 
		  @i @bool.memt@ = NULL; 
		  @i @stats.memt@ = NULL; 
		  @i @stat.ast@ = NULL;
		  @i @stat.memvar@ = NULL; 
		  @i @stat.ifnr@ = ++codeIfCounter;
		  @mem2 @bool.memt@ = @stat.memt@; 
		  @mem2 @stats.memt@ = memDeepCopy(@stat.memt@); 
		  @astgen passIfNrToChildren(@bool.ast@, @stat.ifnr@, AST_FALSE);
		  @codegen BURM_CALL(@bool.ast@);
		  @codegen labelIfStart(@stat.ifnr@);
		  @codegen @revorder (1) labelIfEnd(@stat.ifnr@);
		@}
		| WHILE bool DO stats END
		@{ 
		  @i @bool.memt@ = NULL; 
		  @i @stats.memt@ = NULL; 
		  @i @stat.ast@ = NULL;
		  @i @stat.memvar@ = NULL; 
		  @i @stat.ifnr@ = ++codeIfCounter;
		  @mem2 @bool.memt@ = @stat.memt@; 
		  @mem2 @stats.memt@ = memDeepCopy(@stat.memt@);
		  @astgen passIfNrToChildren(@bool.ast@, @stat.ifnr@, AST_FALSE);
		  @codegen labelWhileCond(@stat.ifnr@); 
		  @codegen BURM_CALL(@bool.ast@);
		  @codegen labelWhileStart(@stat.ifnr@); 
		  @codegen @revorder (1) labelWhileEnd(@stat.ifnr@); 
		@}
		| VAR vardef ASSIGN expr
		@{
		  @i @expr.memt@ = NULL; 
		  @i @stat.ast@ = NULL;
		  @i @stat.memvar@ = allocMem(@vardef.name@, MEM_VAR, @vardef.type@);
		  @i @stat.ifnr@ = DEF_IF_NR;
		  @typcheck assertEqual(@vardef.type@, @expr.type@);
		  @mem2 @expr.memt@ = @stat.memt@;
		  @astgen @stat.ast@ = astVardef(@expr.ast@, @expr.memt@);
		  @codegen BURM_CALL(@stat.ast@)
		@}
		| lexpr ASSIGN expr
		@{
		  @i @expr.memt@ = NULL; 
		  @i @lexpr.memt@ = NULL;
		  @i @stat.ast@ = NULL;
		  @i @stat.memvar@ = NULL;
		  @i @stat.ifnr@ = DEF_IF_NR;
		  @typcheck assertEqual(@lexpr.type@, @expr.type@);
		  @mem2 @lexpr.memt@ = @stat.memt@;
		  @mem2 @expr.memt@ = @stat.memt@;
		  @astgen @stat.ast@ = astAssign(@lexpr.ast@, @expr.ast@);
		  @codegen BURM_CALL(@stat.ast@)
		@}
		| term
		@{
		  @i @term.memt@ = NULL;
		  @i @stat.ast@ = NULL;
		  @i @stat.memvar@ = NULL;
		  @i @stat.ifnr@ = DEF_IF_NR;
		  @mem2 @term.memt@ = @stat.memt@;
		@}
		;

elsecode:	stats
		@{  
		  @i @stats.memt@ = NULL;
		  @mem2 @stats.memt@ = @elsecode.memt@;
		  @codegen labelElse(@elsecode.ifnr@);
		@}

bool:		bterm
		@{
		  @i @bool.ast@ = NULL;
		  @i @bterm.memt@ = NULL;
		  @mem2 @bterm.memt@ = @bool.memt@;
		  @astgen @bool.ast@ = @bterm.ast@; 
		@}
		| bool OR bterm
		@{
		  @i @bool.0.ast@ = NULL;
		  @i @bool.1.memt@ = NULL; 
		  @i @bterm.memt@ = NULL; 
		  @mem2 @bool.1.memt@ = @bool.0.memt@;
		  @mem2 @bterm.memt@ = @bool.0.memt@;
		  @astgen @bool.0.ast@ = astBoolOp(LOR, @bool.1.ast@, @bterm.ast@); 
		  @astgen PARENT(@bool.1.ast@) = @bool.0.ast@;
		  @astgen PARENT(@bterm.ast@) = @bool.0.ast@; 
		@}
		;

bterm:		LPAREN bool RPAREN
		@{
		  @i @bterm.ast@ = NULL; 
		  @i @bool.memt@ = NULL; 
		  @mem2 @bool.memt@ = @bterm.memt@;
		  @astgen @bterm.0.ast@ = @bool.ast@;
		@}
		| NOT bterm
		@{
		  @i @bterm.0.ast@ = NULL;
		  @i @bterm.1.memt@ = NULL; 
		  @mem2 @bterm.1.memt@ = @bterm.0.memt@;
		  @astgen @bterm.0.ast@ = astBoolNot(@bterm.1.ast@);
		@}
		| expr LESS expr
		@{
		  @i @bterm.0.ast@ = NULL; 
		  @i @expr.0.memt@ = NULL; 
		  @i @expr.1.memt@ = NULL;
		  @mem2 @expr.0.memt@ = @bterm.memt@;
		  @mem2 @expr.1.memt@ = @bterm.memt@; 
		  @typcheck assertInt(@expr.0.type@);
		  @typcheck assertInt(@expr.1.type@);
		  @astgen @bterm.ast@ = astBoolOp(LLESS, @expr.0.ast@, @expr.1.ast@);
		@}
		| expr HASH expr
		@{
		  @i @bterm.0.ast@ = NULL; 
		  @i @expr.0.memt@ = NULL; 
		  @i @expr.1.memt@ = NULL; 
		  @mem2 @expr.0.memt@ = @bterm.memt@; 
		  @mem2 @expr.1.memt@ = @bterm.memt@; 
		  @typcheck assertInt(@expr.0.type@);
		  @typcheck assertInt(@expr.1.type@);
		  @astgen @bterm.ast@ = astBoolOp(LNEQ, @expr.0.ast@, @expr.1.ast@);
		@}
		;

lexpr:		ID				/* variable access writing */
		@{
		  @i @lexpr.type@ = SEM_UNDEFINED;
		  @i @lexpr.ast@ = NULL;
		  @typcheck @lexpr.type@ = getType(@lexpr.memt@, @ID.name@);
		  @astgen @lexpr.ast@ = astVar(@ID.name@, getType(@lexpr.memt@, @ID.name@), @lexpr.memt@);
		@}
		| term LBRACK expr RBRACK	/* array access writing  */
		@{
		  @i @lexpr.type@ = SEM_UNDEFINED;
		  @i @lexpr.ast@ = NULL;
		  @i @term.memt@ = NULL; 
		  @i @expr.memt@ = NULL; 
		  @typcheck assertInt(@expr.type@);
		  @typcheck assertArray(@term.type@);
		  @typcheck @lexpr.type@ = @term.type@ - 1;
		  @mem2 @term.memt@ = @lexpr.memt@;
		  @mem2 @expr.memt@ = @lexpr.memt@;
		  @astgen @lexpr.ast@ = astArrayDeref(@term.ast@, @expr.ast@); 
		@}
		;

expr:		term
		@{
		  @i @expr.type@ = SEM_UNDEFINED;
		  @i @expr.ast@ = NULL;
		  @i @term.memt@ = NULL; 
		  @typcheck @expr.type@ = @term.type@;
		  @mem2 @term.memt@ = @expr.memt@;
		  @astgen @expr.ast@ = @term.ast@; 
		@}
		| minus_term MINUS term
		@{
		  @i @expr.type@ = SEM_UNDEFINED;
		  @i @expr.ast@ = NULL;
		  @i @term.memt@ = NULL; 
		  @i @minus_term.memt@ = NULL; 
		  @typcheck assertInt(@term.type@);
		  @typcheck @expr.type@ = @term.type@;
		  @mem2 @minus_term.memt@ = @expr.memt@;
		  @mem2 @term.memt@ = @expr.memt@; 
		  @astgen @expr.ast@ = astArithmetic(SUB, @minus_term.ast@, @term.ast@); 
		@}
		| term PLUS plus_term
		@{
		  @i @expr.type@ = SEM_UNDEFINED;
		  @i @expr.ast@ = NULL;
		  @i @term.memt@ = NULL; 
		  @i @plus_term.memt@ = NULL; 
		  @typcheck assertInt(@term.type@);
		  @typcheck @expr.type@ = @term.type@;
		  @mem2 @term.memt@ = @expr.memt@; 
		  @mem2 @plus_term.memt@ = @expr.memt@; 
		  @astgen @expr.ast@ = astArithmetic(ADD, @term.ast@, @plus_term.ast@); 
		@}
		| term STAR star_term
		@{
		  @i @expr.type@ = SEM_UNDEFINED;
		  @i @expr.ast@ = NULL;
		  @i @term.memt@ = NULL; 
		  @i @star_term.memt@ = NULL; 
		  @typcheck assertInt(@term.type@);
		  @typcheck @expr.type@ = @term.type@;
		  @mem2 @term.memt@ = @expr.memt@; 
		  @mem2 @star_term.memt@ = @expr.memt@; 
		  @astgen @expr.ast@ = astArithmetic(MUL, @term.ast@, @star_term.ast@); 
		@}
		;

minus_term:	term
		@{ 
		  @i @minus_term.ast@ = NULL;
		  @i @term.memt@ = NULL; 
		  @typcheck assertInt(@term.type@);
		  @mem2 @term.memt@ = @minus_term.memt@;
		  @astgen @minus_term.ast@ = @term.ast@; 
		@}
		| minus_term MINUS term
		@{
		  @i @minus_term.0.ast@ = NULL;
		  @i @term.memt@ = NULL; 
		  @i @minus_term.1.memt@ = NULL; 
		  @typcheck assertInt(@term.type@);
		  @mem2 @minus_term.1.memt@ = @minus_term.0.memt@;
		  @mem2 @term.memt@ = @minus_term.0.memt@; 
		  @astgen @minus_term.0.ast@ = astArithmetic(SUB, @minus_term.1.ast@, @term.ast@); 
		@}
		;

plus_term:	term
		@{ 
		  @i @plus_term.ast@ = NULL;
		  @i @term.memt@ = NULL; 
		  @typcheck assertInt(@term.type@);
		  @mem2 @term.memt@ = @plus_term.memt@; 
		  @astgen @plus_term.ast@ = @term.ast@; 
		@} 
		| term PLUS plus_term
		@{
		  @i @plus_term.0.ast@ = NULL;
		  @i @term.memt@ = NULL; 
	 	  @i @plus_term.1.memt@ = NULL; 
		  @typcheck assertInt(@term.type@);
		  @mem2 @term.memt@ = @plus_term.0.memt@; 
		  @mem2 @plus_term.1.memt@ = @plus_term.0.memt@; 
		  @astgen @plus_term.0.ast@ = astArithmetic(ADD, @term.ast@, @plus_term.1.ast@); 
		@}
		;

star_term:	term
		@{ 
		  @i @star_term.0.ast@ = NULL;
		  @i @term.memt@ = NULL; 
		  @typcheck assertInt(@term.type@);
		  @mem2 @term.memt@ = @star_term.memt@; 
		  @astgen @star_term.0.ast@ = @term.ast@;
		@}
		| term STAR star_term
		@{
		  @i @star_term.0.ast@ = NULL;
		  @i @term.memt@ = NULL; 
		  @i @star_term.1.memt@ = NULL; 
		  @typcheck assertInt(@term.type@);
		  @mem2 @term.memt@ = @star_term.0.memt@; 
		  @mem2 @star_term.1.memt@ = @star_term.0.memt@; 
		  @astgen @star_term.0.ast@ = astArithmetic(MUL, @term.ast@, @star_term.1.ast@);
		@}
		;

term:		LPAREN expr RPAREN
		@{
		  @i @term.type@ = SEM_UNDEFINED;
		  @i @term.ast@ = NULL;
		  @i @expr.memt@ = NULL; 
		  @typcheck @term.type@ = @expr.type@;
		  @mem2 @expr.memt@ = @term.memt@; 
		  @astgen @term.ast@ = @expr.ast@;
		@}
		| NUM				/* numeric literal */
		@{ 
		  @i @term.type@ = SEM_INT; 
		  @i @term.ast@ = NULL; 
		  @astgen @term.ast@ = astLiteral(@NUM.val@);
		@}
		| term LBRACK expr RBRACK	/* array access reading */
		@{
		  @i @term.0.type@ = SEM_UNDEFINED;
		  @i @term.0.ast@ = NULL; 
		  @i @term.1.memt@ = NULL; 
		  @i @expr.memt@ = NULL; 
		  @typcheck assertInt(@expr.type@);
		  @typcheck assertArray(@term.1.type@);
		  @typcheck @term.0.type@ = @term.1.type@ - 1;
		  @mem2 @term.1.memt@ = @term.0.memt@; 
		  @mem2 @expr.memt@ = @term.0.memt@; 
		  @astgen @term.0.ast@ = astArrayDeref(@term.1.ast@, @expr.ast@); 
		@}
		| ID				/* variable access reading */
		@{
		  @i @term.ast@ = NULL; 
		  @i @term.type@ = SEM_UNDEFINED;
		  @typcheck @term.type@ = getType(@term.memt@, @ID.name@);
		  @astgen @term.ast@ = astVar(@ID.name@, getType(@term.memt@, @ID.name@), @term.memt@);
		@}
		| ID LPAREN exprlist RPAREN COLON type	/* function call */
		@{
		  @i @term.ast@ = NULL; 
		  @i @term.type@ = @type.depth@;
		@}
		;

exprlist:	/* epsilon */
		| exprlist1
		;

exprlist1:	expr
		@{ 
		  @i @expr.memt@ = NULL; 
		@}
		| expr COMMA exprlist1
		@{
		  @i @expr.memt@ = NULL; 
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
