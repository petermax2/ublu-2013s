/*
* Scanner
* -- Beispiel aus 185.A48 Uebersetzerbau
* -- Author: Peter Nirschl (#1025647)
* -- E-Mail: e1025647@student.tuwien.ac.at
*/

%option noyywrap
%option outfile="scanner.c"

comment		\-\-(.)*($)?
letter		[a-zA-Z]
digit		[0-9]
number		{digit}+
hex_digit	[0-9a-fA-F]
hex_number	\${hex_digit}+
identifier	{letter}({digit}|{letter})*
whitespace	[\t\r\n ]

%%

"end"		{ printf("%s\n", yytext); }
"array"		{ printf("%s\n", yytext); }
"of"		{ printf("%s\n", yytext); }
"int"		{ printf("%s\n", yytext); }
"return"	{ printf("%s\n", yytext); }
"if"		{ printf("%s\n", yytext); }
"then"		{ printf("%s\n", yytext); }
"else"		{ printf("%s\n", yytext); }
"while"		{ printf("%s\n", yytext); }
"do"		{ printf("%s\n", yytext); }
"var"		{ printf("%s\n", yytext); }
"not"		{ printf("%s\n", yytext); }
"or"		{ printf("%s\n", yytext); }
";"		{ printf("%s\n", yytext); }
"("		{ printf("%s\n", yytext); }
")"		{ printf("%s\n", yytext); }
","		{ printf("%s\n", yytext); }
":"		{ printf("%s\n", yytext); }
":="		{ printf("%s\n", yytext); }
"<"		{ printf("%s\n", yytext); }
"#"		{ printf("%s\n", yytext); }
"["		{ printf("%s\n", yytext); }
"]"		{ printf("%s\n", yytext); }
"-"		{ printf("%s\n", yytext); }
"+"		{ printf("%s\n", yytext); }
"*"		{ printf("%s\n", yytext); }

{hex_number}	{ printf("num %x\n", strtol(yytext+1, NULL, 16)); }
{number}	{ printf("num %x\n", atoi(yytext)); }
{identifier}	{ printf("id %s\n", yytext); }
{whitespace}+	;
{comment}	;
.		{ printf("Lexical error! Invalid token: %s\n", yytext); exit(1); }

