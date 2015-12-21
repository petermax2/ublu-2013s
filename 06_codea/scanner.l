/*
* Attribuierte Grammatik
* -- Beispiel aus 185.A48 Uebersetzerbau
* -- Author: Peter Nirschl (#1025647)
* -- E-Mail: e1025647@student.tuwien.ac.at
*/

%{
#include <string.h>
#include "y.tab.h" 
#include "tree.h"
#include "ast.h"
%}

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

{hex_number}	{ return NUM; @{ @NUM.val@ = strtol(yytext+1, NULL, 16); @} }
{number}	{ return NUM; @{ @NUM.val@ = strtol(yytext, NULL, 10);  @} }
{identifier}	{ return ID;  @{ @ID.name@ = strdup(yytext); @} }
{whitespace}+	;
{comment}	;
.		{ printf("Lexical error! Invalid token: %s\n", yytext); exit(1); }

