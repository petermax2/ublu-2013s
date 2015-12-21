/*
* Parser
* -- Beispiel aus 185.A48 Uebersetzerbau
* -- Author: Peter Nirschl (#1025647)
* -- E-Mail: e1025647@student.tuwien.ac.at
*/

%{
 
#include "parser.h"
#include "scanner.h"

int yyerror (yyscan_t scanner, char const *);
 
%}

%code requires {
 
#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
typedef void* yyscan_t;
#endif
 
}
 
%output  "parser.c"
%defines "parser.h"

%define api.pure
%lex-param   { yyscan_t scanner }
%parse-param { yyscan_t scanner }
 
/* 
  this is just a preparation for the following tasks.
  I do not use the yyscan_t struct in this task.
  However, I guess we are going to need sematic values for code generation.
*/
%union {
    int value;
}

%token END
%token ARRAY
%token OF
%token INT
%token RETURN
%token IF
%token THEN
%token ELSE
%token WHILE
%token DO
%token VAR
%token NOT
%token OR
%token SEMICOLON
%token LPAREN
%token RPAREN
%token COMMA
%token COLON
%token ASSIGN
%token LESS
%token HASH
%token LBRACK
%token RBRACK
%token MINUS
%token PLUS
%token STAR
%token ID
%token NUM

%%

program:	/* epsilon */ 
		| program funcdef SEMICOLON
		;

funcdef:	ID LPAREN pars RPAREN stats END
		;

pars:		/* epsilon */
		| varlist vardef
		;

varlist:	/* epsilon */
		| varlist vardef COMMA
		;

vardef:		ID COLON type
		;

type:		arraylist INT
		;

arraylist:	/* epsilon */
		| arraylist ARRAY OF

stats:		/*epsilon */
		| stats stat SEMICOLON
		;

stat:		RETURN expr
		| IF bool THEN stats ELSE stats END
		| IF bool THEN stats END
		| WHILE bool DO stats END
		| VAR vardef ASSIGN expr
		| lexpr ASSIGN expr
		| term
		;

bool:		bterm btermorlist
		;

btermorlist:	/* epsilon */
		| btermorlist OR bterm
		;

bterm:		LPAREN bool RPAREN
		| NOT bterm
		| expr LESS expr
		| expr HASH expr
		;

lexpr:		ID				/* variable access writing */
		| term LBRACK expr RBRACK	/* array access writing  */
		;

expr:		term
		| term MINUS minus_term
		| term PLUS plus_term
		| term STAR star_term
		;

minus_term:	term
		| term MINUS minus_term
		;

plus_term:	term
		| term PLUS plus_term
		;

star_term:	term
		| term STAR star_term
		;

term:		LPAREN expr RPAREN
		| NUM				/* numeric literal */
		| term LBRACK expr RBRACK	/* array access reading */
		| ID				/* variable access reading */
		| ID LPAREN exprlist RPAREN COLON type	/* function call */
		;

exprlist:	/* epsilon */
		| exprlist1 expr
		;

exprlist1:	/* epsilon */
		| exprlist1 expr COMMA
		;

%%

#include <stdlib.h>
#include <stdio.h>
#include "parser.h"
#include "scanner.h"
#include "readstd.h"

int yyerror(yyscan_t scanner, char const *msg) {
        printf("Syntax error\n");
        return 2;
}

int main() {
	int parserState = 0;
	char *content;
	yyscan_t scanner;
	YY_BUFFER_STATE state;

	if (yylex_init(&scanner))
	{
		fprintf(stderr, "Could not initialize the lexer.\n");
		exit(-1);
	}
	content = readFromStdin(); 
	state = yy_scan_string(content, scanner);
	if(yyparse(scanner))
	{
		parserState = 2;
	}
	yy_delete_buffer(state, scanner);
	yylex_destroy(scanner);
	if(parserState == 0)
	{
		printf("Syntax accepted. Oorah!\n");
	}
	return parserState; 
}
