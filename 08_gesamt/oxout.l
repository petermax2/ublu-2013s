/* output from Ox version G1.04 */
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
#include "memtab.h"
%}

comment		\-\-(.)*($)?
letter		[a-zA-Z]
digit		[0-9]
number		{digit}+
hex_digit	[0-9a-fA-F]
hex_number	\${hex_digit}+
identifier	{letter}({digit}|{letter})*
whitespace	[\t\r\n ]


%{


struct yyyT1 {char *name;}; 
typedef struct yyyT1 *yyyP1; 


struct yyyT2 {long val;}; 
typedef struct yyyT2 *yyyP2; 


struct yyyT3 {char *name; long type;}; 
typedef struct yyyT3 *yyyP3; 


struct yyyT4 {char *name; Tree ast;}; 
typedef struct yyyT4 *yyyP4; 


struct yyyT5 {MemTab memt;}; 
typedef struct yyyT5 *yyyP5; 


struct yyyT6 {MemTab memt; int ifnr;}; 
typedef struct yyyT6 *yyyP6; 


struct yyyT7 {Tree ast; MemTab memvar; MemTab memt; int ifnr;}; 
typedef struct yyyT7 *yyyP7; 


struct yyyT8 {MemTab memp;}; 
typedef struct yyyT8 *yyyP8; 


struct yyyT9 {Tree ast; MemTab memt;}; 
typedef struct yyyT9 *yyyP9; 


struct yyyT10 {Tree ast; MemTab memt;}; 
typedef struct yyyT10 *yyyP10; 


struct yyyT11 {long depth;}; 
typedef struct yyyT11 *yyyP11; 


struct yyyT12 {long type; Tree ast; MemTab memt;}; 
typedef struct yyyT12 *yyyP12; 
                                                      /*custom*/  
typedef unsigned char yyyWAT; 
typedef unsigned char yyyRCT; 
typedef unsigned short yyyPNT; 
typedef unsigned char yyyWST; 

#include <limits.h>
#define yyyR UCHAR_MAX  

 /* funny type; as wide as the widest of yyyWAT,yyyWST,yyyRCT  */ 
typedef unsigned short yyyFT;

                                                      /*stock*/  




struct yyyGenNode {void *parent;  
                   struct yyyGenNode **cL; /* child list */ 
                   yyyRCT *refCountList; 
                   yyyPNT prodNum;                      
                   yyyWST whichSym; /* which child of parent? */ 
                  }; 

typedef struct yyyGenNode yyyGNT; 



struct yyyTB {int isEmpty; 
              int typeNum; 
              int nAttrbs; 
              char *snBufPtr; 
              yyyWAT *startP,*stopP; 
             };  




extern struct yyyTB yyyTermBuffer; 
extern yyyWAT yyyLRCIL[]; 
extern void yyyGenLeaf(); 


%}
%%

"end"           { {yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return END;} }
"array"         { {yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return ARRAY;} }
"of"            { {yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return OF;} }
"int"           { {yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return INT;} }
"return"        { {yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return RETURN;} }
"if"            { {yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return IF;} }
"then"          { {yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return THEN;} }
"else"          { {yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return ELSE;} }
"while"         { {yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return WHILE;} }
"do"            { {yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return DO;} }
"var"           { {yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return VAR;} }
"not"           { {yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return NOT;} }
"or"            { {yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return OR;} }
";"             { {yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return SEMICOLON;} }
"("             { {yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return LPAREN;} }
")"             { {yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return RPAREN;} }
","             { {yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return COMMA;} }
":"             { {yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return COLON;} }
":="            { {yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return ASSIGN;} }
"<"             { {yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return LESS;} }
"#"             { {yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return HASH;} }
"["             { {yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return LBRACK;} }
"]"             { {yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return RBRACK;} }
"-"             { {yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return MINUS;} }
"+"             { {yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return PLUS;} }
"*"             { {yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return STAR;} }

{hex_number}	{ {yyyGenLeaf(1,2,yyyLRCIL+0,yyyLRCIL+1); (((yyyP2)(yyyTermBuffer.snBufPtr))->val) = strtol(yytext+1, NULL, 16); return NUM;}  }
{number}	{ {yyyGenLeaf(1,2,yyyLRCIL+0,yyyLRCIL+1); (((yyyP2)(yyyTermBuffer.snBufPtr))->val) = strtol(yytext, NULL, 10);  return NUM;}  }
{identifier}	{ {yyyGenLeaf(1,1,yyyLRCIL+1,yyyLRCIL+2); (((yyyP1)(yyyTermBuffer.snBufPtr))->name) = strdup(yytext); return ID;}   }
{whitespace}+	;
{comment}	;
.		{ printf("Lexical error! Invalid token: %s\n", yytext); exit(1); }

