/*
* Parser
* -- Beispiel aus 185.A48 Uebersetzerbau
* -- Author: Peter Nirschl (#1025647)
* -- E-Mail: e1025647@student.tuwien.ac.at
*/

%{

#include <stdlib.h>
#include "parser.h" 
 
%}

%option outfile="scanner.c" header-file="scanner.h"
%option warn nodefault
 
%option reentrant noyywrap never-interactive nounistd
%option bison-bridge

comment		\-\-(.)*($)?
letter		[a-zA-Z]
digit		[0-9]
number		{digit}+
hex_digit	[0-9a-fA-F]
hex_number	\${hex_digit}+
identifier	{letter}({digit}|{letter})*
whitespace	[\t\r\n ]

%%

"end"           { return END; }
"array"         { return ARRAY; }
"of"            { return OF; }
"int"           { return INT; }
"return"        { return RETURN; }
"if"            { return IF; }
"then"          { return THEN; }
"else"          { return ELSE; }
"while"         { return WHILE; }
"do"            { return DO; }
"var"           { return VAR; }
"not"           { return NOT; }
"or"            { return OR; }
";"             { return SEMICOLON; }
"("             { return LPAREN; }
")"             { return RPAREN; }
","             { return COMMA; }
":"             { return COLON; }
":="            { return ASSIGN; }
"<"             { return LESS; }
"#"             { return HASH; }
"["             { return LBRACK; }
"]"             { return RBRACK; }
"-"             { return MINUS; }
"+"             { return PLUS; }
"*"             { return STAR; }

{hex_number}	{ /* yylval->value = strtol(yytext+1, NULL, 16); */ return NUM; }
{number}	{ /* yylval->value = atoi(yytext); */ return NUM; }
{identifier}	{ /* TODO save semantic value */ return ID; }
{whitespace}+	;
{comment}	;
.		{ printf("Lexical error! Invalid token: %s\n", yytext); exit(1); }

