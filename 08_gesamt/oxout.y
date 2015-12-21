/* output from Ox version G1.04 */
%{
%}
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

 
 
  
 
  
 
 
   
   
   
  
   

                       /* build memory symbol table / mem1 was removed */
		/* builds the symbol table and sets the types */
			/* all checks related to the type-system go here */
			/* prepare AST */ 
			/* propagate AST to BURG */ 


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

%{
#include <stdio.h>

int yyyYok = 1;
int yyyInitDone = 0;
char *yyySTsn;
yyyGNT *yyySTN;
int yyyGNSz = sizeof(yyyGNT);
int yyyProdNum,yyyRHSlength,yyyNattrbs,yyyTypeNum; 

extern yyyFT yyyRCIL[];

void yyyExecuteRRsection();
void yyyYoxInit();
void yyyYoxReset();
void yyyDecorate();
void yyyGenIntNode();
void yyyAdjustINRC();
void yyyPrune();
void yyyUnsolvedInstSearchTrav();
void yyyUnsolvedInstSearchTravAux();
void yyyerror();
void yyyShift();



#define yyyRSU(NUM1,NUM2,NUM3,NUM4) \
   yyyProdNum=NUM1;yyyRHSlength=NUM2;yyyNattrbs=NUM3;yyyTypeNum=NUM4;\
   if ((yychar <= 0) && (!yyyTermBuffer.isEmpty)) yyyShift(); 
%}


%%

yyyAugNonterm 
	:	{if (!yyyInitDone) 
		    {yyyYoxInit(); 
		     yyyInitDone = 1;
		    }
		 yyyYoxReset();
		}
		program
		{
		 yyyDecorate(); yyyExecuteRRsection();
		}
	;
program:	/* epsilon */
		{if(yyyYok){
yyyRSU(1,0,0,0);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+0,yyyRCIL+0);}}| funcdefs
		{if(yyyYok){
yyyRSU(2,1,0,0);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+0,yyyRCIL+0);/*yyyPrune(2);*/}}
		;

funcdefs:	funcdef SEMICOLON
		{if(yyyYok){
yyyRSU(3,2,0,0);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+0,yyyRCIL+0);/*yyyPrune(3);*/}}| funcdefs funcdef SEMICOLON 
		{if(yyyYok){
yyyRSU(4,3,0,0);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+0,yyyRCIL+0);/*yyyPrune(4);*/}}; 

funcdef:	ID LPAREN params RPAREN stats END
		{if(yyyYok){
yyyRSU(5,6,2,4);
yyyGenIntNode();
 (((yyyP4)yyySTsn)->ast) = NULL;
		   (((yyyP5)(((char *)((yyySTN->cL)[4]))+yyyGNSz))->memt) = NULL; 
		   (((yyyP4)yyySTsn)->name) = (((yyyP1)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->name);
		  yyyAdjustINRC(yyyRCIL+0,yyyRCIL+9);/*yyyPrune(5);*/}}
		;

params:		/* epsilon */
		{if(yyyYok){
yyyRSU(6,0,1,8);
yyyGenIntNode();
 (((yyyP8)yyySTsn)->memp) = NULL; yyyAdjustINRC(yyyRCIL+9,yyyRCIL+12);}}
		| parlist 
		{if(yyyYok){
yyyRSU(7,1,1,8);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+12,yyyRCIL+15);/*yyyPrune(7);*/}}
		;

parlist:	pardef
		{if(yyyYok){
yyyRSU(8,1,1,8);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+15,yyyRCIL+18);/*yyyPrune(8);*/}}
		| parlist COMMA pardef
		{if(yyyYok){
yyyRSU(9,3,1,8);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+18,yyyRCIL+21);/*yyyPrune(9);*/}}
		;

pardef:		ID COLON type
		{if(yyyYok){
yyyRSU(10,3,2,3);
yyyGenIntNode();
 (((yyyP3)yyySTsn)->name) = (((yyyP1)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->name);
		  yyyAdjustINRC(yyyRCIL+21,yyyRCIL+27);/*yyyPrune(10);*/}}
		;

vardef:         ID COLON type
		{if(yyyYok){
yyyRSU(11,3,2,3);
yyyGenIntNode();
 (((yyyP3)yyySTsn)->name) = (((yyyP1)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->name);
		  yyyAdjustINRC(yyyRCIL+27,yyyRCIL+33);/*yyyPrune(11);*/}}
		;

type:		INT
		{if(yyyYok){
yyyRSU(12,1,1,11);
yyyGenIntNode();
 (((yyyP11)yyySTsn)->depth) = 0; yyyAdjustINRC(yyyRCIL+33,yyyRCIL+36);/*yyyPrune(12);*/}}
		| arraylist INT
		{if(yyyYok){
yyyRSU(13,2,1,11);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+36,yyyRCIL+39);/*yyyPrune(13);*/}}
		;

arraylist:	ARRAY OF
		{if(yyyYok){
yyyRSU(14,2,1,11);
yyyGenIntNode();
 (((yyyP11)yyySTsn)->depth) = 1; yyyAdjustINRC(yyyRCIL+39,yyyRCIL+42);/*yyyPrune(14);*/}}
		| arraylist ARRAY OF
		{if(yyyYok){
yyyRSU(15,3,1,11);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+42,yyyRCIL+45);/*yyyPrune(15);*/}}
		;
	
stats:		/*epsilon */
		{if(yyyYok){
yyyRSU(16,0,1,5);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+45,yyyRCIL+45);}}| stat SEMICOLON stats
		{if(yyyYok){
yyyRSU(17,3,1,5);
yyyGenIntNode();
 (((yyyP5)(((char *)((yyySTN->cL)[2]))+yyyGNSz))->memt) = NULL; 
		   (((yyyP7)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL; 
		  yyyAdjustINRC(yyyRCIL+45,yyyRCIL+51);/*yyyPrune(17);*/}}
		;

stat:		RETURN expr
		{if(yyyYok){
yyyRSU(18,2,4,7);
yyyGenIntNode();
 (((yyyP12)(((char *)((yyySTN->cL)[1]))+yyyGNSz))->memt) = NULL; 
		   (((yyyP7)yyySTsn)->ast) = NULL;
		   (((yyyP7)yyySTsn)->memvar) = NULL; 
		   (((yyyP7)yyySTsn)->ifnr) = DEF_IF_NR;
		  yyyAdjustINRC(yyyRCIL+51,yyyRCIL+63);/*yyyPrune(18);*/}}
		| IF bool THEN stats ELSE elsecode END
		{if(yyyYok){
yyyRSU(19,7,4,7);
yyyGenIntNode();
 (((yyyP9)(((char *)((yyySTN->cL)[1]))+yyyGNSz))->memt) = NULL; 
		   (((yyyP5)(((char *)((yyySTN->cL)[3]))+yyyGNSz))->memt) = NULL; 
	 	   (((yyyP6)(((char *)((yyySTN->cL)[5]))+yyyGNSz))->memt) = NULL; 
		   (((yyyP7)yyySTsn)->ast) = NULL;
		   (((yyyP7)yyySTsn)->memvar) = NULL;
		   (((yyyP7)yyySTsn)->ifnr) = ++codeIfCounter;
		   (((yyyP6)(((char *)((yyySTN->cL)[5]))+yyyGNSz))->ifnr) = (((yyyP7)yyySTsn)->ifnr);
		  yyyAdjustINRC(yyyRCIL+63,yyyRCIL+84);/*yyyPrune(19);*/}}
		| IF bool THEN stats END
		{if(yyyYok){
yyyRSU(20,5,4,7);
yyyGenIntNode();
 (((yyyP9)(((char *)((yyySTN->cL)[1]))+yyyGNSz))->memt) = NULL; 
		   (((yyyP5)(((char *)((yyySTN->cL)[3]))+yyyGNSz))->memt) = NULL; 
		   (((yyyP7)yyySTsn)->ast) = NULL;
		   (((yyyP7)yyySTsn)->memvar) = NULL; 
		   (((yyyP7)yyySTsn)->ifnr) = ++codeIfCounter;
		  yyyAdjustINRC(yyyRCIL+84,yyyRCIL+99);/*yyyPrune(20);*/}}
		| WHILE bool DO stats END
		{if(yyyYok){
yyyRSU(21,5,4,7);
yyyGenIntNode();
 (((yyyP9)(((char *)((yyySTN->cL)[1]))+yyyGNSz))->memt) = NULL; 
		   (((yyyP5)(((char *)((yyySTN->cL)[3]))+yyyGNSz))->memt) = NULL; 
		   (((yyyP7)yyySTsn)->ast) = NULL;
		   (((yyyP7)yyySTsn)->memvar) = NULL; 
		   (((yyyP7)yyySTsn)->ifnr) = ++codeIfCounter;
		  yyyAdjustINRC(yyyRCIL+99,yyyRCIL+114);/*yyyPrune(21);*/}}
		| VAR vardef ASSIGN expr
		{if(yyyYok){
yyyRSU(22,4,4,7);
yyyGenIntNode();
 (((yyyP12)(((char *)((yyySTN->cL)[3]))+yyyGNSz))->memt) = NULL; 
		   (((yyyP7)yyySTsn)->ast) = NULL;
		   (((yyyP7)yyySTsn)->ifnr) = DEF_IF_NR;
		  yyyAdjustINRC(yyyRCIL+114,yyyRCIL+126);/*yyyPrune(22);*/}}
		| lexpr ASSIGN expr
		{if(yyyYok){
yyyRSU(23,3,4,7);
yyyGenIntNode();
 (((yyyP12)(((char *)((yyySTN->cL)[2]))+yyyGNSz))->memt) = NULL; 
		   (((yyyP12)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL;
		   (((yyyP7)yyySTsn)->ast) = NULL;
		   (((yyyP7)yyySTsn)->memvar) = NULL;
		   (((yyyP7)yyySTsn)->ifnr) = DEF_IF_NR;
		  yyyAdjustINRC(yyyRCIL+126,yyyRCIL+141);/*yyyPrune(23);*/}}
		| term
		{if(yyyYok){
yyyRSU(24,1,4,7);
yyyGenIntNode();
 (((yyyP12)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL;
		   (((yyyP7)yyySTsn)->ast) = NULL;
		   (((yyyP7)yyySTsn)->memvar) = NULL;
		   (((yyyP7)yyySTsn)->ifnr) = DEF_IF_NR;
		  yyyAdjustINRC(yyyRCIL+141,yyyRCIL+153);/*yyyPrune(24);*/}}
		;

elsecode:	stats
		{if(yyyYok){
yyyRSU(25,1,2,6);
yyyGenIntNode();
 (((yyyP5)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL;
		  yyyAdjustINRC(yyyRCIL+153,yyyRCIL+156);/*yyyPrune(25);*/}}

bool:		bterm
		{if(yyyYok){
yyyRSU(26,1,2,9);
yyyGenIntNode();
 (((yyyP9)yyySTsn)->ast) = NULL;
		   (((yyyP9)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL;
		  yyyAdjustINRC(yyyRCIL+156,yyyRCIL+162);/*yyyPrune(26);*/}}
		| bool OR bterm
		{if(yyyYok){
yyyRSU(27,3,2,9);
yyyGenIntNode();
 (((yyyP9)yyySTsn)->ast) = NULL;
		   (((yyyP9)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL; 
		   (((yyyP9)(((char *)((yyySTN->cL)[2]))+yyyGNSz))->memt) = NULL; 
		  yyyAdjustINRC(yyyRCIL+162,yyyRCIL+171);/*yyyPrune(27);*/}}
		;

bterm:		LPAREN bool RPAREN
		{if(yyyYok){
yyyRSU(28,3,2,9);
yyyGenIntNode();
 (((yyyP9)yyySTsn)->ast) = NULL; 
		   (((yyyP9)(((char *)((yyySTN->cL)[1]))+yyyGNSz))->memt) = NULL; 
		  yyyAdjustINRC(yyyRCIL+171,yyyRCIL+177);/*yyyPrune(28);*/}}
		| NOT bterm
		{if(yyyYok){
yyyRSU(29,2,2,9);
yyyGenIntNode();
 (((yyyP9)yyySTsn)->ast) = NULL;
		   (((yyyP9)(((char *)((yyySTN->cL)[1]))+yyyGNSz))->memt) = NULL; 
		  yyyAdjustINRC(yyyRCIL+177,yyyRCIL+183);/*yyyPrune(29);*/}}
		| expr LESS expr
		{if(yyyYok){
yyyRSU(30,3,2,9);
yyyGenIntNode();
 (((yyyP9)yyySTsn)->ast) = NULL; 
		   (((yyyP12)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL; 
		   (((yyyP12)(((char *)((yyySTN->cL)[2]))+yyyGNSz))->memt) = NULL;
		  yyyAdjustINRC(yyyRCIL+183,yyyRCIL+192);/*yyyPrune(30);*/}}
		| expr HASH expr
		{if(yyyYok){
yyyRSU(31,3,2,9);
yyyGenIntNode();
 (((yyyP9)yyySTsn)->ast) = NULL; 
		   (((yyyP12)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL; 
		   (((yyyP12)(((char *)((yyySTN->cL)[2]))+yyyGNSz))->memt) = NULL; 
		  yyyAdjustINRC(yyyRCIL+192,yyyRCIL+201);/*yyyPrune(31);*/}}
		;

lexpr:		ID				/* variable access writing */
		{if(yyyYok){
yyyRSU(32,1,3,12);
yyyGenIntNode();
 (((yyyP12)yyySTsn)->type) = SEM_UNDEFINED;
		   (((yyyP12)yyySTsn)->ast) = NULL;
		  yyyAdjustINRC(yyyRCIL+201,yyyRCIL+207);/*yyyPrune(32);*/}}
		| term LBRACK expr RBRACK	/* array access writing  */
		{if(yyyYok){
yyyRSU(33,4,3,12);
yyyGenIntNode();
 (((yyyP12)yyySTsn)->type) = SEM_UNDEFINED;
		   (((yyyP12)yyySTsn)->ast) = NULL;
		   (((yyyP12)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL; 
		   (((yyyP12)(((char *)((yyySTN->cL)[2]))+yyyGNSz))->memt) = NULL; 
		  yyyAdjustINRC(yyyRCIL+207,yyyRCIL+219);/*yyyPrune(33);*/}}
		;

expr:		term
		{if(yyyYok){
yyyRSU(34,1,3,12);
yyyGenIntNode();
 (((yyyP12)yyySTsn)->type) = SEM_UNDEFINED;
		   (((yyyP12)yyySTsn)->ast) = NULL;
		   (((yyyP12)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL; 
		  yyyAdjustINRC(yyyRCIL+219,yyyRCIL+228);/*yyyPrune(34);*/}}
		| minus_term MINUS term
		{if(yyyYok){
yyyRSU(35,3,3,12);
yyyGenIntNode();
 (((yyyP12)yyySTsn)->type) = SEM_UNDEFINED;
		   (((yyyP12)yyySTsn)->ast) = NULL;
		   (((yyyP12)(((char *)((yyySTN->cL)[2]))+yyyGNSz))->memt) = NULL; 
		   (((yyyP10)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL; 
		  yyyAdjustINRC(yyyRCIL+228,yyyRCIL+240);/*yyyPrune(35);*/}}
		| term PLUS plus_term
		{if(yyyYok){
yyyRSU(36,3,3,12);
yyyGenIntNode();
 (((yyyP12)yyySTsn)->type) = SEM_UNDEFINED;
		   (((yyyP12)yyySTsn)->ast) = NULL;
		   (((yyyP12)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL; 
		   (((yyyP10)(((char *)((yyySTN->cL)[2]))+yyyGNSz))->memt) = NULL; 
		  yyyAdjustINRC(yyyRCIL+240,yyyRCIL+252);/*yyyPrune(36);*/}}
		| term STAR star_term
		{if(yyyYok){
yyyRSU(37,3,3,12);
yyyGenIntNode();
 (((yyyP12)yyySTsn)->type) = SEM_UNDEFINED;
		   (((yyyP12)yyySTsn)->ast) = NULL;
		   (((yyyP12)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL; 
		   (((yyyP10)(((char *)((yyySTN->cL)[2]))+yyyGNSz))->memt) = NULL; 
		  yyyAdjustINRC(yyyRCIL+252,yyyRCIL+264);/*yyyPrune(37);*/}}
		;

minus_term:	term
		{if(yyyYok){
yyyRSU(38,1,2,10);
yyyGenIntNode();
 (((yyyP10)yyySTsn)->ast) = NULL;
		   (((yyyP12)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL; 
		  yyyAdjustINRC(yyyRCIL+264,yyyRCIL+270);/*yyyPrune(38);*/}}
		| minus_term MINUS term
		{if(yyyYok){
yyyRSU(39,3,2,10);
yyyGenIntNode();
 (((yyyP10)yyySTsn)->ast) = NULL;
		   (((yyyP12)(((char *)((yyySTN->cL)[2]))+yyyGNSz))->memt) = NULL; 
		   (((yyyP10)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL; 
		  yyyAdjustINRC(yyyRCIL+270,yyyRCIL+279);/*yyyPrune(39);*/}}
		;

plus_term:	term
		{if(yyyYok){
yyyRSU(40,1,2,10);
yyyGenIntNode();
 (((yyyP10)yyySTsn)->ast) = NULL;
		   (((yyyP12)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL; 
		  yyyAdjustINRC(yyyRCIL+279,yyyRCIL+285);/*yyyPrune(40);*/}} 
		| term PLUS plus_term
		{if(yyyYok){
yyyRSU(41,3,2,10);
yyyGenIntNode();
 (((yyyP10)yyySTsn)->ast) = NULL;
		   (((yyyP12)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL; 
	 	   (((yyyP10)(((char *)((yyySTN->cL)[2]))+yyyGNSz))->memt) = NULL; 
		  yyyAdjustINRC(yyyRCIL+285,yyyRCIL+294);/*yyyPrune(41);*/}}
		;

star_term:	term
		{if(yyyYok){
yyyRSU(42,1,2,10);
yyyGenIntNode();
 (((yyyP10)yyySTsn)->ast) = NULL;
		   (((yyyP12)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL; 
		  yyyAdjustINRC(yyyRCIL+294,yyyRCIL+300);/*yyyPrune(42);*/}}
		| term STAR star_term
		{if(yyyYok){
yyyRSU(43,3,2,10);
yyyGenIntNode();
 (((yyyP10)yyySTsn)->ast) = NULL;
		   (((yyyP12)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL; 
		   (((yyyP10)(((char *)((yyySTN->cL)[2]))+yyyGNSz))->memt) = NULL; 
		  yyyAdjustINRC(yyyRCIL+300,yyyRCIL+309);/*yyyPrune(43);*/}}
		;

term:		LPAREN expr RPAREN
		{if(yyyYok){
yyyRSU(44,3,3,12);
yyyGenIntNode();
 (((yyyP12)yyySTsn)->type) = SEM_UNDEFINED;
		   (((yyyP12)yyySTsn)->ast) = NULL;
		   (((yyyP12)(((char *)((yyySTN->cL)[1]))+yyyGNSz))->memt) = NULL; 
		  yyyAdjustINRC(yyyRCIL+309,yyyRCIL+318);/*yyyPrune(44);*/}}
		| NUM				/* numeric literal */
		{if(yyyYok){
yyyRSU(45,1,3,12);
yyyGenIntNode();
 (((yyyP12)yyySTsn)->type) = SEM_INT; 
		   (((yyyP12)yyySTsn)->ast) = NULL; 
		  yyyAdjustINRC(yyyRCIL+318,yyyRCIL+324);/*yyyPrune(45);*/}}
		| term LBRACK expr RBRACK	/* array access reading */
		{if(yyyYok){
yyyRSU(46,4,3,12);
yyyGenIntNode();
 (((yyyP12)yyySTsn)->type) = SEM_UNDEFINED;
		   (((yyyP12)yyySTsn)->ast) = NULL; 
		   (((yyyP12)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL; 
		   (((yyyP12)(((char *)((yyySTN->cL)[2]))+yyyGNSz))->memt) = NULL; 
		  yyyAdjustINRC(yyyRCIL+324,yyyRCIL+336);/*yyyPrune(46);*/}}
		| ID				/* variable access reading */
		{if(yyyYok){
yyyRSU(47,1,3,12);
yyyGenIntNode();
 (((yyyP12)yyySTsn)->ast) = NULL; 
		   (((yyyP12)yyySTsn)->type) = SEM_UNDEFINED;
		  yyyAdjustINRC(yyyRCIL+336,yyyRCIL+342);/*yyyPrune(47);*/}}
		| ID LPAREN exprlist RPAREN COLON type	/* function call */
		{if(yyyYok){
yyyRSU(48,6,3,12);
yyyGenIntNode();
 (((yyyP12)yyySTsn)->ast) = NULL; 
		  yyyAdjustINRC(yyyRCIL+342,yyyRCIL+348);/*yyyPrune(48);*/}}
		;

exprlist:	/* epsilon */
		{if(yyyYok){
yyyRSU(49,0,0,0);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+348,yyyRCIL+348);}}| exprlist1
		{if(yyyYok){
yyyRSU(50,1,0,0);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+348,yyyRCIL+348);/*yyyPrune(50);*/}};

exprlist1:	expr
		{if(yyyYok){
yyyRSU(51,1,0,0);
yyyGenIntNode();
 (((yyyP12)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL; 
		yyyAdjustINRC(yyyRCIL+348,yyyRCIL+351);/*yyyPrune(51);*/}}
		| expr COMMA exprlist1
		{if(yyyYok){
yyyRSU(52,3,0,0);
yyyGenIntNode();
 (((yyyP12)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL; 
		yyyAdjustINRC(yyyRCIL+351,yyyRCIL+354);/*yyyPrune(52);*/}}
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
                                                      /*custom*/  
long yyyMaxNbytesNodeStg = 2000000; 
long yyyMaxNrefCounts =    500000; 
long yyyMaxNchildren =     60000; 
long yyyMaxStackSize =     2000; 
long yyySSALspaceSize =    20000; 
long yyyRSmaxSize =        1000; 
long yyyTravStackMaxSize = 2000; 


struct yyyTB yyyTermBuffer; 

char *yyyNodeAndStackSpace; 

char *yyyNodeSpace;
char *yyyNextNodeSpace; 
char *yyyAfterNodeSpace; 


 
struct yyyGenNode **yyyChildListSpace;  
struct yyyGenNode **yyyNextCLspace; 
struct yyyGenNode **yyyAfterChildListSpace; 



yyyRCT *yyyRefCountListSpace;
yyyRCT *yyyNextRCLspace;  
yyyRCT *yyyAfterRefCountListSpace;   



struct yyySolvedSAlistCell {yyyWAT attrbNum; 
                            long next; 
                           }; 
#define yyyLambdaSSAL 0 
long yyySSALCfreeList = yyyLambdaSSAL; 
long yyyNewSSALC = 1; 
 
struct yyySolvedSAlistCell *yyySSALspace; 


 
struct yyyStackItem {struct yyyGenNode *node; 
                     long solvedSAlist; 
                     struct yyyGenNode *oldestNode; 
                    };  

long yyyNbytesStackStg; 
struct yyyStackItem *yyyStack; 
struct yyyStackItem *yyyAfterStack; 
struct yyyStackItem *yyyStackTop; 



struct yyyRSitem {yyyGNT *node; 
                  yyyWST whichSym; 
                  yyyWAT wa;  
                 };  

struct yyyRSitem *yyyRS;  
struct yyyRSitem *yyyRSTop;  
struct yyyRSitem *yyyAfterRS;  
 





yyyFT yyyRCIL[] = {
yyyR,0,0, yyyR,1,0, 4,0,0, yyyR,0,0, yyyR,0,1, yyyR,0,2, 
yyyR,0,3, yyyR,0,0, yyyR,1,1, yyyR,0,0, yyyR,1,1, yyyR,0,0, 
yyyR,0,1, yyyR,0,0, yyyR,0,1, 0,2,0, 2,0,0, yyyR,0,0, 
yyyR,1,0, yyyR,3,0, 1,2,0, yyyR,0,0, yyyR,1,0, yyyR,3,0, 
1,1,0, 3,0,0, 5,0,0, 5,1,0, yyyR,0,0, yyyR,1,0, 
yyyR,3,0, 1,1,0, 3,0,0, yyyR,0,0, yyyR,1,0, yyyR,3,0, 
1,1,0, 3,0,0, yyyR,0,0, yyyR,1,2, yyyR,3,0, 3,2,0, 
yyyR,0,0, yyyR,1,0, yyyR,3,0, 0,2,0, 2,2,0, yyyR,0,0, 
yyyR,1,0, yyyR,3,0, 0,2,0, 0,0,0, yyyR,0,0, 0,1,0, 
yyyR,0,0, 0,1,0, 2,1,0, yyyR,0,0, 1,1,0, yyyR,0,0, 
1,1,0, yyyR,0,0, 0,2,0, 2,2,0, yyyR,0,0, 0,2,0, 
2,2,0, yyyR,0,0, yyyR,1,0, yyyR,0,0, yyyR,1,0, 0,2,0, 
2,2,0, yyyR,0,0, yyyR,1,0, 0,2,0, yyyR,0,0, yyyR,1,0, 
0,1,0, 2,2,0, yyyR,0,0, yyyR,1,0, 0,2,0, 2,1,0, 
yyyR,0,0, yyyR,1,0, 0,2,0, 2,1,0, yyyR,0,0, 0,2,0, 
yyyR,0,0, 0,1,0, 2,2,0, yyyR,0,0, 0,2,0, yyyR,0,0, 
0,2,0, 2,1,0, yyyR,0,0, 0,2,0, yyyR,0,0, 0,2,0, 
2,1,0, yyyR,0,0, yyyR,1,0, 1,2,0, yyyR,0,0, yyyR,1,0, 
yyyR,0,0, yyyR,1,0, 0,2,0, 2,2,0, yyyR,0,0, yyyR,1,0, 
yyyR,0,1, yyyR,1,0, 0,2,0, 0,2,0, 
};

short yyyIIIEL[] = {0,
0,1,3,6,10,17,18,20,22,26,
30,34,36,39,42,46,47,51,54,62,
68,74,79,83,85,87,89,93,97,100,
104,108,110,115,117,121,125,129,131,135,
137,141,143,147,151,153,158,160,167,168,
170,172,
};

long yyyIIEL[] = {
0,0,0,0,0,2,2,2,2,4,4,6,
7,7,8,8,9,9,10,11,12,13,15,16,
17,17,19,21,22,22,23,25,26,26,27,28,
28,29,30,30,31,31,31,32,33,33,33,34,
35,39,39,40,44,44,47,51,51,53,53,54,
54,56,56,60,60,62,62,63,63,67,67,69,
69,70,70,74,74,76,76,79,83,86,86,89,
93,96,98,99,101,103,105,107,107,109,111,111,
113,113,115,115,117,119,122,122,125,127,130,130,
133,136,137,140,143,143,146,146,149,152,155,157,
157,160,163,166,166,168,171,174,174,176,178,181,
183,185,185,188,190,193,195,198,198,200,202,205,
207,210,210,212,215,215,218,218,221,222,225,228,
228,231,231,234,235,238,239,239,239,239,239,240,
240,240,240,240,243,243,246,246,
};

long yyyIEL[] = {
0,0,0,0,0,0,0,2,
2,2,2,2,4,4,6,8,
8,10,12,14,14,14,16,18,
18,18,20,22,22,22,24,24,
24,26,26,26,26,26,26,26,
26,26,26,26,26,26,26,26,
26,26,26,26,26,26,26,26,
26,26,26,26,26,26,26,26,
26,26,26,26,26,26,26,26,
26,26,26,28,30,30,30,30,
30,30,30,30,30,30,30,30,
30,30,30,30,30,30,30,30,
30,30,30,30,30,30,30,30,
30,30,30,30,30,30,30,30,
30,30,30,30,30,30,30,30,
30,30,30,30,30,30,30,30,
30,30,30,30,30,30,30,30,
30,30,30,30,30,30,30,30,
30,30,30,30,30,30,30,30,
30,30,30,30,30,30,30,30,
30,30,30,30,30,30,30,30,
30,30,30,30,30,30,30,30,
30,30,30,30,30,30,30,30,
30,30,30,30,30,30,30,30,
30,30,30,30,30,30,30,30,
30,30,30,30,30,30,30,30,
30,30,30,30,30,30,30,30,
30,30,30,30,30,30,30,30,
30,30,30,30,30,30,30,30,
30,30,30,30,30,30,30,30,
32,32,32,32,32,32,32,
};

yyyFT yyyEntL[] = {
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,

};

#define yyyPermitUserAlloc  0 


void yyyfatal(msg)
  char *msg; 
{fprintf(stderr,msg);exit(-1);} 



#define yyyNSof   'n' 
#define yyyRCof   'r' 
#define yyyCLof   'c' 
#define yyySof    's' 
#define yyySSALof 'S' 
#define yyyRSof   'q' 
#define yyyTSof   't' 



void yyyHandleOverflow(which) 
  char which; 
  {char *msg1,*msg2; 
   long  oldSize,newSize; 
   switch(which) 
     {
      case yyyNSof   : 
           msg1 = "node storage overflow: ";
           oldSize = yyyMaxNbytesNodeStg; 
           break; 
      case yyyRCof   : 
           msg1 = "dependee count overflow: ";
           oldSize = yyyMaxNrefCounts; 
           break; 
      case yyyCLof   : 
           msg1 = "child list overflow: ";
           oldSize = yyyMaxNchildren; 
           break; 
      case yyySof    : 
           msg1 = "parse-tree stack overflow: ";
           oldSize = yyyMaxStackSize; 
           break; 
      case yyySSALof : 
           msg1 = "SSAL overflow: ";
           oldSize = yyySSALspaceSize; 
           break; 
      case yyyRSof   : 
           msg1 = "ready set overflow: ";
           oldSize = yyyRSmaxSize; 
           break; 
      case yyyTSof   : 
           msg1 = "traversal stack overflow: ";
           oldSize = yyyTravStackMaxSize; 
           break; 
      default        :;  
     }
   newSize = (3*oldSize)/2; 
   if (newSize < 100) newSize = 100; 
   fprintf(stderr,msg1); 
   fprintf(stderr,"size was %d.\n",oldSize); 
   if (yyyPermitUserAlloc) 
      msg2 = "     Try -Y%c%d option.\n"; 
      else 
      msg2 = "     Have to modify evaluator:  -Y%c%d.\n"; 
   fprintf(stderr,msg2,which,newSize); 
   exit(-1); 
  }



void yyySignalEnts(node,startP,stopP) 
  register yyyGNT *node; 
  register yyyFT *startP,*stopP;  
  {register yyyGNT *dumNode; 

   while (startP < stopP)  
     {
      if (!(*startP)) dumNode = node;  
         else dumNode = (node->cL)[(*startP)-1];   
      if (!(--((dumNode->refCountList)[*(startP+1)]
              ) 
           )
         ) 
         { 
          if (++yyyRSTop == yyyAfterRS) 
             {yyyHandleOverflow(yyyRSof); 
              break; 
             }
          yyyRSTop->node = dumNode; 
          yyyRSTop->whichSym = *startP;  
          yyyRSTop->wa = *(startP+1);  
         }  
      startP += 2;  
     }  
  } 




#define yyyCeiling(num,inc) (((inc) * ((num)/(inc))) + (((num)%(inc))?(inc):0)) 



int yyyAlignSize = 8;
int yyyNdSz[13];

int yyyNdPrSz[13];

typedef int yyyCopyType;

int yyyNdCopySz[13];
long yyyBiggestNodeSize = 0;

void yyyNodeSizeCalc()
  {int i;
   yyyGNSz = yyyCeiling(yyyGNSz,yyyAlignSize); 
   yyyNdSz[0] = 0;
   yyyNdSz[1] = sizeof(struct yyyT1);
   yyyNdSz[2] = sizeof(struct yyyT2);
   yyyNdSz[3] = sizeof(struct yyyT3);
   yyyNdSz[4] = sizeof(struct yyyT4);
   yyyNdSz[5] = sizeof(struct yyyT5);
   yyyNdSz[6] = sizeof(struct yyyT6);
   yyyNdSz[7] = sizeof(struct yyyT7);
   yyyNdSz[8] = sizeof(struct yyyT8);
   yyyNdSz[9] = sizeof(struct yyyT9);
   yyyNdSz[10] = sizeof(struct yyyT10);
   yyyNdSz[11] = sizeof(struct yyyT11);
   yyyNdSz[12] = sizeof(struct yyyT12);
   for (i=0;i<13;i++) 
       {yyyNdSz[i] = yyyCeiling(yyyNdSz[i],yyyAlignSize); 
        yyyNdPrSz[i] = yyyNdSz[i] + yyyGNSz;
        if (yyyBiggestNodeSize < yyyNdSz[i])
           yyyBiggestNodeSize = yyyNdSz[i];
        yyyNdCopySz[i] = yyyCeiling(yyyNdSz[i],sizeof(yyyCopyType)) / 
                         sizeof(yyyCopyType); 
       }
  }




void yyySolveAndSignal() {
register long yyyiDum,*yyypL;
register int yyyws,yyywa;
register yyyGNT *yyyRSTopN,*yyyRefN; 
register void *yyyRSTopNp; 


yyyRSTopNp = (yyyRSTopN = yyyRSTop->node)->parent;
yyyRefN= (yyyws = (yyyRSTop->whichSym))?((yyyGNT *)yyyRSTopNp):yyyRSTopN;
yyywa = yyyRSTop->wa; 
yyyRSTop--;
switch(yyyRefN->prodNum) {
case 1:  /***yacc rule 1***/
  switch (yyyws) {
  }
break;
case 2:  /***yacc rule 2***/
  switch (yyyws) {
  }
break;
case 3:  /***yacc rule 3***/
  switch (yyyws) {
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 4:  /***yacc rule 4***/
  switch (yyyws) {
  case 2:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 5:  /***yacc rule 5***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    }
  break;
  case 5:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 6:  /***yacc rule 6***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 7:  /***yacc rule 7***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 0:
 (((yyyP8)(((char *)yyyRSTopN)+yyyGNSz))->memp) = (((yyyP8)(((char *)((yyyRefN->cL)[0]))+yyyGNSz))->memp);
		    break;
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 8:  /***yacc rule 8***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 0:
 (((yyyP8)(((char *)yyyRSTopN)+yyyGNSz))->memp) = appendMemParam(NULL, (((yyyP3)(((char *)((yyyRefN->cL)[0]))+yyyGNSz))->name), (((yyyP3)(((char *)((yyyRefN->cL)[0]))+yyyGNSz))->type)); 
		    break;
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 9:  /***yacc rule 9***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 0:
 (((yyyP8)(((char *)yyyRSTopN)+yyyGNSz))->memp) = appendMemParam((((yyyP8)(((char *)((yyyRefN->cL)[0]))+yyyGNSz))->memp), (((yyyP3)(((char *)((yyyRefN->cL)[2]))+yyyGNSz))->name), (((yyyP3)(((char *)((yyyRefN->cL)[2]))+yyyGNSz))->type));
		    break;
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 10:  /***yacc rule 10***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 1:
 (((yyyP3)(((char *)yyyRSTopN)+yyyGNSz))->type) = (((yyyP11)(((char *)((yyyRefN->cL)[2]))+yyyGNSz))->depth);
		    break;
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 11:  /***yacc rule 11***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 1:
 (((yyyP3)(((char *)yyyRSTopN)+yyyGNSz))->type) = (((yyyP11)(((char *)((yyyRefN->cL)[2]))+yyyGNSz))->depth);
		    break;
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 12:  /***yacc rule 12***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 13:  /***yacc rule 13***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 0:
 (((yyyP11)(((char *)yyyRSTopN)+yyyGNSz))->depth) = (((yyyP11)(((char *)((yyyRefN->cL)[0]))+yyyGNSz))->depth);     break;
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 14:  /***yacc rule 14***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 15:  /***yacc rule 15***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 0:
 (((yyyP11)(((char *)yyyRSTopN)+yyyGNSz))->depth) = (((yyyP11)(((char *)((yyyRefN->cL)[0]))+yyyGNSz))->depth) + 1;     break;
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 16:  /***yacc rule 16***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 17:  /***yacc rule 17***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 18:  /***yacc rule 18***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 19:  /***yacc rule 19***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    }
  break;
  case 4:  /**/
    switch (yyywa) {
    }
  break;
  case 6:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 20:  /***yacc rule 20***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    }
  break;
  case 4:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 21:  /***yacc rule 21***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    }
  break;
  case 4:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 22:  /***yacc rule 22***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 1:
 (((yyyP7)(((char *)yyyRSTopN)+yyyGNSz))->memvar) = allocMem((((yyyP3)(((char *)((yyyRefN->cL)[1]))+yyyGNSz))->name), MEM_VAR, (((yyyP3)(((char *)((yyyRefN->cL)[1]))+yyyGNSz))->type));
		      break;
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    }
  break;
  case 4:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 23:  /***yacc rule 23***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 24:  /***yacc rule 24***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 25:  /***yacc rule 25***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 26:  /***yacc rule 26***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 27:  /***yacc rule 27***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 28:  /***yacc rule 28***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 29:  /***yacc rule 29***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 30:  /***yacc rule 30***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 31:  /***yacc rule 31***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 32:  /***yacc rule 32***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 33:  /***yacc rule 33***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 34:  /***yacc rule 34***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 35:  /***yacc rule 35***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 36:  /***yacc rule 36***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 37:  /***yacc rule 37***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 38:  /***yacc rule 38***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 39:  /***yacc rule 39***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 40:  /***yacc rule 40***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 41:  /***yacc rule 41***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 42:  /***yacc rule 42***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 43:  /***yacc rule 43***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 44:  /***yacc rule 44***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 45:  /***yacc rule 45***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 46:  /***yacc rule 46***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 47:  /***yacc rule 47***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 48:  /***yacc rule 48***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 0:
 (((yyyP12)(((char *)yyyRSTopN)+yyyGNSz))->type) = (((yyyP11)(((char *)((yyyRefN->cL)[5]))+yyyGNSz))->depth);
		    break;
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  case 6:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 49:  /***yacc rule 49***/
  switch (yyyws) {
  }
break;
case 50:  /***yacc rule 50***/
  switch (yyyws) {
  }
break;
case 51:  /***yacc rule 51***/
  switch (yyyws) {
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 52:  /***yacc rule 52***/
  switch (yyyws) {
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
} /* switch */ 

if (yyyws)  /* the just-solved instance was inherited. */ 
   {if (yyyRSTopN->prodNum) 
       {yyyiDum = yyyIIEL[yyyIIIEL[yyyRSTopN->prodNum]] + yyywa;
        yyySignalEnts(yyyRSTopN,yyyEntL + yyyIEL[yyyiDum],
                                yyyEntL + yyyIEL[yyyiDum+1]
                     );
       }
   } 
   else     /* the just-solved instance was synthesized. */ 
   {if ((char *)yyyRSTopNp >= yyyNodeSpace) /* node has a parent. */ 
       {yyyiDum = yyyIIEL[yyyIIIEL[((yyyGNT *)yyyRSTopNp)->prodNum] + 
                          yyyRSTopN->whichSym 
                         ] + 
                  yyywa;
        yyySignalEnts((yyyGNT *)yyyRSTopNp,
                      yyyEntL + yyyIEL[yyyiDum],
                      yyyEntL + yyyIEL[yyyiDum+1] 
                     );
       } 
       else   /* node is still on the stack--it has no parent yet. */ 
       {yyypL = &(((struct yyyStackItem *)yyyRSTopNp)->solvedSAlist); 
        if (yyySSALCfreeList == yyyLambdaSSAL) 
           {yyySSALspace[yyyNewSSALC].next = *yyypL; 
            if ((*yyypL = yyyNewSSALC++) == yyySSALspaceSize) 
               yyyHandleOverflow(yyySSALof); 
           }  
           else
           {yyyiDum = yyySSALCfreeList; 
            yyySSALCfreeList = yyySSALspace[yyySSALCfreeList].next; 
            yyySSALspace[yyyiDum].next = *yyypL; 
            *yyypL = yyyiDum;  
           } 
        yyySSALspace[*yyypL].attrbNum = yyywa; 
       } 
   }

} /* yyySolveAndSignal */ 






#define condStg unsigned int conds;
#define yyyClearConds {yyyTST->conds = 0;}
#define yyySetCond(n) {yyyTST->conds += (1<<(n));}
#define yyyCond(n) ((yyyTST->conds & (1<<(n)))?1:0)



struct yyyTravStackItem {yyyGNT *node; 
                         char isReady;
                         condStg
                        };



void yyyDoTraversals()
{struct yyyTravStackItem *yyyTravStack,*yyyTST,*yyyAfterTravStack;
 register yyyGNT *yyyTSTn,**yyyCLptr1,**yyyCLptr2; 
 register int yyyi,yyyRL,yyyPass;

 if (!yyyYok) return;
 if ((yyyTravStack = 
                 ((struct yyyTravStackItem *) 
                  malloc((yyyTravStackMaxSize * 
                                  sizeof(struct yyyTravStackItem)
                                 )
                        )
                 )
     )
     == 
     (struct yyyTravStackItem *)NULL
    ) 
    {fprintf(stderr,"malloc error in traversal stack allocation\n"); 
     exit(-1); 
    } 

yyyAfterTravStack = yyyTravStack + yyyTravStackMaxSize; 
yyyTravStack++; 


for (yyyi=0; yyyi<5; yyyi++) {
yyyTST = yyyTravStack; 
yyyTST->node = yyyStack->node;
yyyTST->isReady = 0;
yyyClearConds

while(yyyTST >= yyyTravStack)
  {yyyTSTn = yyyTST->node;
   if (yyyTST->isReady)  
      {yyyPass = 1;
       goto yyyTravSwitch;
yyyTpop:
       yyyTST--;
      } 
      else 
      {yyyPass = 0;
       goto yyyTravSwitch;
yyyTpush:
       yyyTST->isReady = 1;  
       if (yyyTSTn->prodNum)
          if (yyyRL)
             {yyyCLptr2 = yyyTSTn->cL; 
              while 
                ((yyyCLptr2 != yyyNextCLspace)
                 &&
                 ((*yyyCLptr2)->parent == yyyTSTn) 
                )  
                {if (++yyyTST == yyyAfterTravStack)
                    yyyHandleOverflow(yyyTSof);
                    else
                    {yyyTST->node = *yyyCLptr2; 
                     yyyTST->isReady = 0; 
                     yyyClearConds
                    }
                 yyyCLptr2++; 
                } 
             } /* right to left */
             else  /* left to right */
             {yyyCLptr1 = yyyCLptr2 = yyyTSTn->cL; 
              while 
                ((yyyCLptr2 != yyyNextCLspace)
                 &&
                 ((*yyyCLptr2)->parent == yyyTSTn) 
                )  
                yyyCLptr2++; 
              while (yyyCLptr2-- > yyyCLptr1)
                if (++yyyTST == yyyAfterTravStack)
                   yyyHandleOverflow(yyyTSof);
                   else
                   {yyyTST->node = *yyyCLptr2; 
                    yyyTST->isReady = 0; 
                    yyyClearConds
                   }
             } /* left to right */
      } /* else */
   continue;
yyyTravSwitch:
				switch(yyyTSTn->prodNum)	{
case 1:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 2:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)

				case 1:

if (yyyCond(0) != yyyPass) { printf("\t.text\n\n"); }
				break;
					}
		break;
			}

break;
case 3:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 4:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 5:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)

				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP5)(((char *)((yyyTSTn->cL)[4]))+yyyGNSz))->memt) = (((yyyP8)(((char *)((yyyTSTn->cL)[2]))+yyyGNSz))->memp);
		  }
				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)

				case 1:

if (yyyCond(0) != yyyPass) { checkDuplicates((((yyyP8)(((char *)((yyyTSTn->cL)[2]))+yyyGNSz))->memp));
		  }
				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP4)(((char *)yyyTSTn)+yyyGNSz))->ast) = astFuncdef((((yyyP4)(((char *)yyyTSTn)+yyyGNSz))->name), (((yyyP8)(((char *)((yyyTSTn->cL)[2]))+yyyGNSz))->memp));
		  }
				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)
yyySetCond(1)

if (!  (1)) yyySetCond(2)

				case 1:

if (yyyCond(0) != yyyPass) { BURM_CALL((((yyyP4)(((char *)yyyTSTn)+yyyGNSz))->ast));
		  }
if (yyyCond(1) != yyyPass) { }
if (yyyCond(2) != yyyPass) { printFunctionEpilog();
		}
				break;
					}
		break;
			}

break;
case 6:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 7:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 8:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 9:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 10:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 11:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 12:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 13:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 14:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 15:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 16:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 17:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)
yyySetCond(1)

				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP7)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->memt) = (((yyyP5)(((char *)yyyTSTn)+yyyGNSz))->memt);
		  }
if (yyyCond(1) != yyyPass) { (((yyyP5)(((char *)((yyyTSTn->cL)[2]))+yyyGNSz))->memt) = memTransferStats((((yyyP5)(((char *)yyyTSTn)+yyyGNSz))->memt), (((yyyP7)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->memvar));
		}
				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 18:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)

				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP12)(((char *)((yyyTSTn->cL)[1]))+yyyGNSz))->memt) = (((yyyP7)(((char *)yyyTSTn)+yyyGNSz))->memt);
		  }
				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP7)(((char *)yyyTSTn)+yyyGNSz))->ast) = astReturn((((yyyP12)(((char *)((yyyTSTn->cL)[1]))+yyyGNSz))->ast)); 
		  }
				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)

				case 1:

if (yyyCond(0) != yyyPass) { BURM_CALL((((yyyP7)(((char *)yyyTSTn)+yyyGNSz))->ast))
		}
				break;
					}
		break;
			}

break;
case 19:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)
yyySetCond(1)
yyySetCond(2)

				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP9)(((char *)((yyyTSTn->cL)[1]))+yyyGNSz))->memt) = (((yyyP7)(((char *)yyyTSTn)+yyyGNSz))->memt);
		  }
if (yyyCond(1) != yyyPass) { (((yyyP5)(((char *)((yyyTSTn->cL)[3]))+yyyGNSz))->memt) = memDeepCopy((((yyyP7)(((char *)yyyTSTn)+yyyGNSz))->memt)); 
		  }
if (yyyCond(2) != yyyPass) { (((yyyP6)(((char *)((yyyTSTn->cL)[5]))+yyyGNSz))->memt) = memDeepCopy((((yyyP7)(((char *)yyyTSTn)+yyyGNSz))->memt));
		  }
				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { passIfNrToChildren((((yyyP9)(((char *)((yyyTSTn->cL)[1]))+yyyGNSz))->ast), (((yyyP7)(((char *)yyyTSTn)+yyyGNSz))->ifnr), AST_TRUE);
		  }
				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)
yyySetCond(1)
yyySetCond(2)

if (!  (1)) yyySetCond(3)

				case 1:

if (yyyCond(0) != yyyPass) { BURM_CALL((((yyyP9)(((char *)((yyyTSTn->cL)[1]))+yyyGNSz))->ast));
		  }
if (yyyCond(1) != yyyPass) { labelIfStart((((yyyP7)(((char *)yyyTSTn)+yyyGNSz))->ifnr)); 
		  }
if (yyyCond(2) != yyyPass) { }
if (yyyCond(3) != yyyPass) { labelIfEnd((((yyyP7)(((char *)yyyTSTn)+yyyGNSz))->ifnr)); 
		}
				break;
					}
		break;
			}

break;
case 20:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)
yyySetCond(1)

				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP9)(((char *)((yyyTSTn->cL)[1]))+yyyGNSz))->memt) = (((yyyP7)(((char *)yyyTSTn)+yyyGNSz))->memt); 
		  }
if (yyyCond(1) != yyyPass) { (((yyyP5)(((char *)((yyyTSTn->cL)[3]))+yyyGNSz))->memt) = memDeepCopy((((yyyP7)(((char *)yyyTSTn)+yyyGNSz))->memt)); 
		  }
				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { passIfNrToChildren((((yyyP9)(((char *)((yyyTSTn->cL)[1]))+yyyGNSz))->ast), (((yyyP7)(((char *)yyyTSTn)+yyyGNSz))->ifnr), AST_FALSE);
		  }
				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)
yyySetCond(1)
yyySetCond(2)

if (!  (1)) yyySetCond(3)

				case 1:

if (yyyCond(0) != yyyPass) { BURM_CALL((((yyyP9)(((char *)((yyyTSTn->cL)[1]))+yyyGNSz))->ast));
		  }
if (yyyCond(1) != yyyPass) { labelIfStart((((yyyP7)(((char *)yyyTSTn)+yyyGNSz))->ifnr));
		  }
if (yyyCond(2) != yyyPass) { }
if (yyyCond(3) != yyyPass) { labelIfEnd((((yyyP7)(((char *)yyyTSTn)+yyyGNSz))->ifnr));
		}
				break;
					}
		break;
			}

break;
case 21:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)
yyySetCond(1)

				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP9)(((char *)((yyyTSTn->cL)[1]))+yyyGNSz))->memt) = (((yyyP7)(((char *)yyyTSTn)+yyyGNSz))->memt); 
		  }
if (yyyCond(1) != yyyPass) { (((yyyP5)(((char *)((yyyTSTn->cL)[3]))+yyyGNSz))->memt) = memDeepCopy((((yyyP7)(((char *)yyyTSTn)+yyyGNSz))->memt));
		  }
				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { passIfNrToChildren((((yyyP9)(((char *)((yyyTSTn->cL)[1]))+yyyGNSz))->ast), (((yyyP7)(((char *)yyyTSTn)+yyyGNSz))->ifnr), AST_FALSE);
		  }
				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)
yyySetCond(1)
yyySetCond(2)
yyySetCond(3)

if (!  (1)) yyySetCond(4)

				case 1:

if (yyyCond(0) != yyyPass) { labelWhileCond((((yyyP7)(((char *)yyyTSTn)+yyyGNSz))->ifnr)); 
		  }
if (yyyCond(1) != yyyPass) { BURM_CALL((((yyyP9)(((char *)((yyyTSTn->cL)[1]))+yyyGNSz))->ast));
		  }
if (yyyCond(2) != yyyPass) { labelWhileStart((((yyyP7)(((char *)yyyTSTn)+yyyGNSz))->ifnr)); 
		  }
if (yyyCond(3) != yyyPass) { }
if (yyyCond(4) != yyyPass) { labelWhileEnd((((yyyP7)(((char *)yyyTSTn)+yyyGNSz))->ifnr)); 
		}
				break;
					}
		break;
			}

break;
case 22:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)

				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP12)(((char *)((yyyTSTn->cL)[3]))+yyyGNSz))->memt) = (((yyyP7)(((char *)yyyTSTn)+yyyGNSz))->memt);
		  }
				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { assertEqual((((yyyP3)(((char *)((yyyTSTn->cL)[1]))+yyyGNSz))->type), (((yyyP12)(((char *)((yyyTSTn->cL)[3]))+yyyGNSz))->type));
		  }
				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP7)(((char *)yyyTSTn)+yyyGNSz))->ast) = astVardef((((yyyP12)(((char *)((yyyTSTn->cL)[3]))+yyyGNSz))->ast), (((yyyP12)(((char *)((yyyTSTn->cL)[3]))+yyyGNSz))->memt));
		  }
				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)

				case 1:

if (yyyCond(0) != yyyPass) { BURM_CALL((((yyyP7)(((char *)yyyTSTn)+yyyGNSz))->ast))
		}
				break;
					}
		break;
			}

break;
case 23:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)
yyySetCond(1)

				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->memt) = (((yyyP7)(((char *)yyyTSTn)+yyyGNSz))->memt);
		  }
if (yyyCond(1) != yyyPass) { (((yyyP12)(((char *)((yyyTSTn->cL)[2]))+yyyGNSz))->memt) = (((yyyP7)(((char *)yyyTSTn)+yyyGNSz))->memt);
		  }
				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { assertEqual((((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->type), (((yyyP12)(((char *)((yyyTSTn->cL)[2]))+yyyGNSz))->type));
		  }
				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP7)(((char *)yyyTSTn)+yyyGNSz))->ast) = astAssign((((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->ast), (((yyyP12)(((char *)((yyyTSTn->cL)[2]))+yyyGNSz))->ast));
		  }
				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)

				case 1:

if (yyyCond(0) != yyyPass) { BURM_CALL((((yyyP7)(((char *)yyyTSTn)+yyyGNSz))->ast))
		}
				break;
					}
		break;
			}

break;
case 24:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)

				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->memt) = (((yyyP7)(((char *)yyyTSTn)+yyyGNSz))->memt);
		}
				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 25:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)

				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP5)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->memt) = (((yyyP6)(((char *)yyyTSTn)+yyyGNSz))->memt);
		  }
				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)

				case 1:

if (yyyCond(0) != yyyPass) { labelElse((((yyyP6)(((char *)yyyTSTn)+yyyGNSz))->ifnr));
		}
				break;
					}
		break;
			}

break;
case 26:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)

				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP9)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->memt) = (((yyyP9)(((char *)yyyTSTn)+yyyGNSz))->memt);
		  }
				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP9)(((char *)yyyTSTn)+yyyGNSz))->ast) = (((yyyP9)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->ast); 
		}
				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 27:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)
yyySetCond(1)

				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP9)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->memt) = (((yyyP9)(((char *)yyyTSTn)+yyyGNSz))->memt);
		  }
if (yyyCond(1) != yyyPass) { (((yyyP9)(((char *)((yyyTSTn->cL)[2]))+yyyGNSz))->memt) = (((yyyP9)(((char *)yyyTSTn)+yyyGNSz))->memt);
		  }
				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP9)(((char *)yyyTSTn)+yyyGNSz))->ast) = astBoolOp(LOR, (((yyyP9)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->ast), (((yyyP9)(((char *)((yyyTSTn->cL)[2]))+yyyGNSz))->ast)); 
		  }
if (yyyCond(1) != yyyPass) { PARENT((((yyyP9)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->ast)) = (((yyyP9)(((char *)yyyTSTn)+yyyGNSz))->ast);
		  }
if (yyyCond(2) != yyyPass) { PARENT((((yyyP9)(((char *)((yyyTSTn->cL)[2]))+yyyGNSz))->ast)) = (((yyyP9)(((char *)yyyTSTn)+yyyGNSz))->ast); 
		}
				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 28:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)

				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP9)(((char *)((yyyTSTn->cL)[1]))+yyyGNSz))->memt) = (((yyyP9)(((char *)yyyTSTn)+yyyGNSz))->memt);
		  }
				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP9)(((char *)yyyTSTn)+yyyGNSz))->ast) = (((yyyP9)(((char *)((yyyTSTn->cL)[1]))+yyyGNSz))->ast);
		}
				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 29:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)

				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP9)(((char *)((yyyTSTn->cL)[1]))+yyyGNSz))->memt) = (((yyyP9)(((char *)yyyTSTn)+yyyGNSz))->memt);
		  }
				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP9)(((char *)yyyTSTn)+yyyGNSz))->ast) = astBoolNot((((yyyP9)(((char *)((yyyTSTn->cL)[1]))+yyyGNSz))->ast));
		}
				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 30:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)
yyySetCond(1)

				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->memt) = (((yyyP9)(((char *)yyyTSTn)+yyyGNSz))->memt);
		  }
if (yyyCond(1) != yyyPass) { (((yyyP12)(((char *)((yyyTSTn->cL)[2]))+yyyGNSz))->memt) = (((yyyP9)(((char *)yyyTSTn)+yyyGNSz))->memt); 
		  }
				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { assertInt((((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->type));
		  }
if (yyyCond(1) != yyyPass) { assertInt((((yyyP12)(((char *)((yyyTSTn->cL)[2]))+yyyGNSz))->type));
		  }
				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP9)(((char *)yyyTSTn)+yyyGNSz))->ast) = astBoolOp(LLESS, (((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->ast), (((yyyP12)(((char *)((yyyTSTn->cL)[2]))+yyyGNSz))->ast));
		}
				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 31:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)
yyySetCond(1)

				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->memt) = (((yyyP9)(((char *)yyyTSTn)+yyyGNSz))->memt); 
		  }
if (yyyCond(1) != yyyPass) { (((yyyP12)(((char *)((yyyTSTn->cL)[2]))+yyyGNSz))->memt) = (((yyyP9)(((char *)yyyTSTn)+yyyGNSz))->memt); 
		  }
				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { assertInt((((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->type));
		  }
if (yyyCond(1) != yyyPass) { assertInt((((yyyP12)(((char *)((yyyTSTn->cL)[2]))+yyyGNSz))->type));
		  }
				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP9)(((char *)yyyTSTn)+yyyGNSz))->ast) = astBoolOp(LNEQ, (((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->ast), (((yyyP12)(((char *)((yyyTSTn->cL)[2]))+yyyGNSz))->ast));
		}
				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 32:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP12)(((char *)yyyTSTn)+yyyGNSz))->type) = getType((((yyyP12)(((char *)yyyTSTn)+yyyGNSz))->memt), (((yyyP1)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->name));
		  }
				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP12)(((char *)yyyTSTn)+yyyGNSz))->ast) = astVar((((yyyP1)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->name), getType((((yyyP12)(((char *)yyyTSTn)+yyyGNSz))->memt), (((yyyP1)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->name)), (((yyyP12)(((char *)yyyTSTn)+yyyGNSz))->memt));
		}
				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 33:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)
yyySetCond(1)

				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->memt) = (((yyyP12)(((char *)yyyTSTn)+yyyGNSz))->memt);
		  }
if (yyyCond(1) != yyyPass) { (((yyyP12)(((char *)((yyyTSTn->cL)[2]))+yyyGNSz))->memt) = (((yyyP12)(((char *)yyyTSTn)+yyyGNSz))->memt);
		  }
				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { assertInt((((yyyP12)(((char *)((yyyTSTn->cL)[2]))+yyyGNSz))->type));
		  }
if (yyyCond(1) != yyyPass) { assertArray((((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->type));
		  }
if (yyyCond(2) != yyyPass) { (((yyyP12)(((char *)yyyTSTn)+yyyGNSz))->type) = (((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->type) - 1;
		  }
				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP12)(((char *)yyyTSTn)+yyyGNSz))->ast) = astArrayDeref((((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->ast), (((yyyP12)(((char *)((yyyTSTn->cL)[2]))+yyyGNSz))->ast)); 
		}
				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 34:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)

				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->memt) = (((yyyP12)(((char *)yyyTSTn)+yyyGNSz))->memt);
		  }
				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP12)(((char *)yyyTSTn)+yyyGNSz))->type) = (((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->type);
		  }
				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP12)(((char *)yyyTSTn)+yyyGNSz))->ast) = (((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->ast); 
		}
				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 35:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)
yyySetCond(1)

				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP10)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->memt) = (((yyyP12)(((char *)yyyTSTn)+yyyGNSz))->memt);
		  }
if (yyyCond(1) != yyyPass) { (((yyyP12)(((char *)((yyyTSTn->cL)[2]))+yyyGNSz))->memt) = (((yyyP12)(((char *)yyyTSTn)+yyyGNSz))->memt); 
		  }
				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { assertInt((((yyyP12)(((char *)((yyyTSTn->cL)[2]))+yyyGNSz))->type));
		  }
if (yyyCond(1) != yyyPass) { (((yyyP12)(((char *)yyyTSTn)+yyyGNSz))->type) = (((yyyP12)(((char *)((yyyTSTn->cL)[2]))+yyyGNSz))->type);
		  }
				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP12)(((char *)yyyTSTn)+yyyGNSz))->ast) = astArithmetic(SUB, (((yyyP10)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->ast), (((yyyP12)(((char *)((yyyTSTn->cL)[2]))+yyyGNSz))->ast)); 
		}
				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 36:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)
yyySetCond(1)

				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->memt) = (((yyyP12)(((char *)yyyTSTn)+yyyGNSz))->memt); 
		  }
if (yyyCond(1) != yyyPass) { (((yyyP10)(((char *)((yyyTSTn->cL)[2]))+yyyGNSz))->memt) = (((yyyP12)(((char *)yyyTSTn)+yyyGNSz))->memt); 
		  }
				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { assertInt((((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->type));
		  }
if (yyyCond(1) != yyyPass) { (((yyyP12)(((char *)yyyTSTn)+yyyGNSz))->type) = (((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->type);
		  }
				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP12)(((char *)yyyTSTn)+yyyGNSz))->ast) = astArithmetic(ADD, (((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->ast), (((yyyP10)(((char *)((yyyTSTn->cL)[2]))+yyyGNSz))->ast)); 
		}
				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 37:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)
yyySetCond(1)

				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->memt) = (((yyyP12)(((char *)yyyTSTn)+yyyGNSz))->memt); 
		  }
if (yyyCond(1) != yyyPass) { (((yyyP10)(((char *)((yyyTSTn->cL)[2]))+yyyGNSz))->memt) = (((yyyP12)(((char *)yyyTSTn)+yyyGNSz))->memt); 
		  }
				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { assertInt((((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->type));
		  }
if (yyyCond(1) != yyyPass) { (((yyyP12)(((char *)yyyTSTn)+yyyGNSz))->type) = (((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->type);
		  }
				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP12)(((char *)yyyTSTn)+yyyGNSz))->ast) = astArithmetic(MUL, (((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->ast), (((yyyP10)(((char *)((yyyTSTn->cL)[2]))+yyyGNSz))->ast)); 
		}
				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 38:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)

				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->memt) = (((yyyP10)(((char *)yyyTSTn)+yyyGNSz))->memt);
		  }
				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { assertInt((((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->type));
		  }
				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP10)(((char *)yyyTSTn)+yyyGNSz))->ast) = (((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->ast); 
		}
				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 39:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)
yyySetCond(1)

				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP10)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->memt) = (((yyyP10)(((char *)yyyTSTn)+yyyGNSz))->memt);
		  }
if (yyyCond(1) != yyyPass) { (((yyyP12)(((char *)((yyyTSTn->cL)[2]))+yyyGNSz))->memt) = (((yyyP10)(((char *)yyyTSTn)+yyyGNSz))->memt); 
		  }
				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { assertInt((((yyyP12)(((char *)((yyyTSTn->cL)[2]))+yyyGNSz))->type));
		  }
				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP10)(((char *)yyyTSTn)+yyyGNSz))->ast) = astArithmetic(SUB, (((yyyP10)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->ast), (((yyyP12)(((char *)((yyyTSTn->cL)[2]))+yyyGNSz))->ast)); 
		}
				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 40:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)

				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->memt) = (((yyyP10)(((char *)yyyTSTn)+yyyGNSz))->memt); 
		  }
				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { assertInt((((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->type));
		  }
				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP10)(((char *)yyyTSTn)+yyyGNSz))->ast) = (((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->ast); 
		}
				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 41:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)
yyySetCond(1)

				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->memt) = (((yyyP10)(((char *)yyyTSTn)+yyyGNSz))->memt); 
		  }
if (yyyCond(1) != yyyPass) { (((yyyP10)(((char *)((yyyTSTn->cL)[2]))+yyyGNSz))->memt) = (((yyyP10)(((char *)yyyTSTn)+yyyGNSz))->memt); 
		  }
				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { assertInt((((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->type));
		  }
				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP10)(((char *)yyyTSTn)+yyyGNSz))->ast) = astArithmetic(ADD, (((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->ast), (((yyyP10)(((char *)((yyyTSTn->cL)[2]))+yyyGNSz))->ast)); 
		}
				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 42:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)

				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->memt) = (((yyyP10)(((char *)yyyTSTn)+yyyGNSz))->memt); 
		  }
				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { assertInt((((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->type));
		  }
				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP10)(((char *)yyyTSTn)+yyyGNSz))->ast) = (((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->ast);
		}
				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 43:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)
yyySetCond(1)

				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->memt) = (((yyyP10)(((char *)yyyTSTn)+yyyGNSz))->memt); 
		  }
if (yyyCond(1) != yyyPass) { (((yyyP10)(((char *)((yyyTSTn->cL)[2]))+yyyGNSz))->memt) = (((yyyP10)(((char *)yyyTSTn)+yyyGNSz))->memt); 
		  }
				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { assertInt((((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->type));
		  }
				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP10)(((char *)yyyTSTn)+yyyGNSz))->ast) = astArithmetic(MUL, (((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->ast), (((yyyP10)(((char *)((yyyTSTn->cL)[2]))+yyyGNSz))->ast));
		}
				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 44:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)

				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP12)(((char *)((yyyTSTn->cL)[1]))+yyyGNSz))->memt) = (((yyyP12)(((char *)yyyTSTn)+yyyGNSz))->memt); 
		  }
				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP12)(((char *)yyyTSTn)+yyyGNSz))->type) = (((yyyP12)(((char *)((yyyTSTn->cL)[1]))+yyyGNSz))->type);
		  }
				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP12)(((char *)yyyTSTn)+yyyGNSz))->ast) = (((yyyP12)(((char *)((yyyTSTn->cL)[1]))+yyyGNSz))->ast);
		}
				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 45:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP12)(((char *)yyyTSTn)+yyyGNSz))->ast) = astLiteral((((yyyP2)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->val));
		}
				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 46:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)
yyySetCond(1)

				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->memt) = (((yyyP12)(((char *)yyyTSTn)+yyyGNSz))->memt); 
		  }
if (yyyCond(1) != yyyPass) { (((yyyP12)(((char *)((yyyTSTn->cL)[2]))+yyyGNSz))->memt) = (((yyyP12)(((char *)yyyTSTn)+yyyGNSz))->memt); 
		  }
				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { assertInt((((yyyP12)(((char *)((yyyTSTn->cL)[2]))+yyyGNSz))->type));
		  }
if (yyyCond(1) != yyyPass) { assertArray((((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->type));
		  }
if (yyyCond(2) != yyyPass) { (((yyyP12)(((char *)yyyTSTn)+yyyGNSz))->type) = (((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->type) - 1;
		  }
				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP12)(((char *)yyyTSTn)+yyyGNSz))->ast) = astArrayDeref((((yyyP12)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->ast), (((yyyP12)(((char *)((yyyTSTn->cL)[2]))+yyyGNSz))->ast)); 
		}
				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 47:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP12)(((char *)yyyTSTn)+yyyGNSz))->type) = getType((((yyyP12)(((char *)yyyTSTn)+yyyGNSz))->memt), (((yyyP1)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->name));
		  }
				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { (((yyyP12)(((char *)yyyTSTn)+yyyGNSz))->ast) = astVar((((yyyP1)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->name), getType((((yyyP12)(((char *)yyyTSTn)+yyyGNSz))->memt), (((yyyP1)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->name)), (((yyyP12)(((char *)yyyTSTn)+yyyGNSz))->memt));
		}
				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 48:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 49:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 50:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 51:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 52:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
								} /* switch */ 
   if (yyyPass) goto yyyTpop; else goto yyyTpush; 
  } /* while */ 
 } /* for */ 
} /* yyyDoTraversals */ 

void yyyExecuteRRsection()  {
   int yyyi; 
   long yyynRefCounts; 
   long cycleSum = 0;
   long nNZrc = 0;

   if (!yyyYok) return; 
   yyynRefCounts = yyyNextRCLspace - yyyRefCountListSpace; 
   for (yyyi=0;yyyi<yyynRefCounts;yyyi++) 
     if (yyyRefCountListSpace[yyyi])
        {cycleSum += yyyRefCountListSpace[yyyi]; nNZrc++;} 
   if (nNZrc) 
      {
       fprintf(stderr,"\n\n\n**********\n");
       fprintf(stderr,
               "cycle detected in completed parse tree");
       fprintf(stderr,
               " after decoration.\n");
       fprintf(stderr,
         "searching parse tree for %d unsolved instances:\n",
               nNZrc
              );
       yyyUnsolvedInstSearchTravAux(yyyStackTop->node);
      }
   yyyDoTraversals();
} /* yyyExecuteRRsection */ 



yyyWAT yyyLRCIL[2] = {0,0,
};



void yyyYoxInit()                                  /*stock*/  
  { 

   yyyNodeSizeCalc(); 

   if ((yyyTermBuffer.snBufPtr = 
        (char *) malloc((yyyBiggestNodeSize + sizeof(yyyCopyType)))
       )  
       == 
       ((char *) NULL) 
      )   
      yyyfatal("malloc error in yyyTermBuffer allocation\n");  
  
  
   yyyNbytesStackStg = yyyMaxStackSize*sizeof(struct yyyStackItem); 
   yyyNbytesStackStg = ((yyyNbytesStackStg/yyyAlignSize)+1)*yyyAlignSize;  
   if ((yyyNodeAndStackSpace = 
        (char *) malloc((yyyNbytesStackStg + 
                                 yyyMaxNbytesNodeStg + 
                                 yyyGNSz + 
                                 yyyBiggestNodeSize + 
                                 sizeof(yyyCopyType) 
                                )
                       )
       )  
       == 
       ((char *) NULL) 
      )   
      yyyfatal("malloc error in ox node and stack space allocation\n");
   yyyStack = (struct yyyStackItem *) yyyNodeAndStackSpace; 
   yyyAfterStack = yyyStack + yyyMaxStackSize;  
   yyyNodeSpace = yyyNodeAndStackSpace + yyyNbytesStackStg;
   yyyAfterNodeSpace = yyyNodeSpace + yyyMaxNbytesNodeStg;
 
 
   if ((yyyRS = (struct yyyRSitem *) 
         malloc(((yyyRSmaxSize+1)*sizeof(struct yyyRSitem)))
       )  
       == 
       ((struct yyyRSitem *) NULL) 
      )   
      yyyfatal("malloc error in ox ready set space allocation\n");  
   yyyRS++; 
   yyyAfterRS = yyyRS + yyyRSmaxSize; 

 
   if ((yyyChildListSpace = 
        (yyyGNT **) malloc((yyyMaxNchildren*sizeof(yyyGNT *)))
       )  
       == 
       ((yyyGNT **) NULL) 
      )   
      yyyfatal("malloc error in ox child list space allocation\n");  
   yyyAfterChildListSpace = yyyChildListSpace + yyyMaxNchildren; 

 
   if ((yyyRefCountListSpace = 
        (yyyRCT *) malloc((yyyMaxNrefCounts * sizeof(yyyRCT)))
       )  
       == 
       ((yyyRCT *) NULL) 
      )   
      yyyfatal("malloc error in ox reference count list space allocation\n");  
   yyyAfterRefCountListSpace = yyyRefCountListSpace + yyyMaxNrefCounts;  
  
 
   if ((yyySSALspace = (struct yyySolvedSAlistCell *) 
          malloc(((yyySSALspaceSize+1) * 
                          sizeof(struct yyySolvedSAlistCell))
                         ) 
       ) 
       == 
       ((struct yyySolvedSAlistCell *) NULL) 
      ) 
      yyyfatal("malloc error in stack solved list space allocation\n"); 
  } /* yyyYoxInit */ 



void yyyYoxReset() 
  { 
   yyyTermBuffer.isEmpty = 1; 
   yyyStackTop = yyyStack; 
   while (yyyStackTop != yyyAfterStack) 
     (yyyStackTop++)->solvedSAlist = yyyLambdaSSAL; 
   yyyStackTop = yyyStack - 1; 
   yyyNextNodeSpace = yyyNodeSpace; 
   yyyRSTop = yyyRS - 1; 
   yyyNextCLspace = yyyChildListSpace;
   yyyNextRCLspace = yyyRefCountListSpace; 
  }  



void yyyDecorate() 
  { 
   while (yyyRSTop >= yyyRS) 
      yyySolveAndSignal();  
  } 



void yyyShift() 
  {yyyRCT *rcPdum; 
   register yyyCopyType *CTp1,*CTp2,*CTp3; 
   register yyyWAT *startP,*stopP;  

   if ((++yyyStackTop) == yyyAfterStack) 
      yyyHandleOverflow(yyySof);
   CTp2 = (yyyCopyType *)(yyyStackTop->oldestNode = 
                          yyyStackTop->node = 
                          (yyyGNT *)yyyNextNodeSpace 
                         ); 
   yyyTermBuffer.isEmpty = 1;
   ((yyyGNT *)CTp2)->parent = (void *)yyyStackTop; 
   ((yyyGNT *)CTp2)->cL = yyyNextCLspace;  
   rcPdum = ((yyyGNT *)CTp2)->refCountList = yyyNextRCLspace;  
   ((yyyGNT *)CTp2)->prodNum = 0; 
   if ((yyyNextRCLspace += yyyTermBuffer.nAttrbs) 
       > 
       yyyAfterRefCountListSpace 
      ) 
      yyyHandleOverflow(yyyRCof); 
   startP = yyyTermBuffer.startP;  
   stopP = yyyTermBuffer.stopP;  
   while (startP < stopP) rcPdum[*(startP++)] = 0; 
   if ((yyyNextNodeSpace += yyyNdPrSz[yyyTermBuffer.typeNum]) 
       > 
       yyyAfterNodeSpace 
      ) 
      yyyHandleOverflow(yyyNSof);  
   CTp1 = (yyyCopyType *)(yyyTermBuffer.snBufPtr); 
   CTp2 = (yyyCopyType *)(((char *)CTp2) + yyyGNSz); 
   CTp3 = CTp2 + yyyNdCopySz[yyyTermBuffer.typeNum]; 
   while (CTp2 < CTp3) *CTp2++ = *CTp1++; 
  } 



void yyyGenIntNode() 
  {register yyyWST i;
   register struct yyyStackItem *stDum;  
   register yyyGNT *gnpDum; 

   if ((stDum = (yyyStackTop -= (yyyRHSlength-1))) >= yyyAfterStack) 
      yyyHandleOverflow(yyySof);
   yyySTsn = ((char *)(yyySTN = (yyyGNT *)yyyNextNodeSpace)) + yyyGNSz; 
   yyySTN->parent       =  (void *)yyyStackTop;  
   yyySTN->cL           =  yyyNextCLspace; 
   yyySTN->refCountList =  yyyNextRCLspace; 
   yyySTN->prodNum      =  yyyProdNum; 
   if ((yyyNextCLspace+yyyRHSlength) > yyyAfterChildListSpace) 
      yyyHandleOverflow(yyyCLof); 
   for (i=1;i<=yyyRHSlength;i++) 
     {gnpDum = *(yyyNextCLspace++) = (stDum++)->node;  
      gnpDum->whichSym = i;  
      gnpDum->parent = (void *)yyyNextNodeSpace; 
     } 
   if ((yyyNextRCLspace += yyyNattrbs) > yyyAfterRefCountListSpace) 
      yyyHandleOverflow(yyyRCof); 
   if ((yyyNextNodeSpace += yyyNdPrSz[yyyTypeNum]) > yyyAfterNodeSpace) 
      yyyHandleOverflow(yyyNSof);  
  } 



#define yyyDECORfREQ 50 



void yyyAdjustINRC(startP,stopP) 
  register yyyFT *startP,*stopP;
  {yyyWST i;
   long SSALptr,SSALptrHead,*cPtrPtr; 
   long *pL; 
   struct yyyStackItem *stDum;  
   yyyGNT *gnpDum; 
   long iTemp;
   register yyyFT *nextP;
   static unsigned short intNodeCount = yyyDECORfREQ;

   nextP = startP;
   while (nextP < stopP) 
     {if ((*nextP) == yyyR)  
         {(yyySTN->refCountList)[*(nextP+1)] = *(nextP+2);
         } 
         else 
         {(((yyySTN->cL)[*nextP])->refCountList)[*(nextP+1)] = *(nextP+2);
         } 
      nextP += 3;  
     }
   pL = yyyIIEL + yyyIIIEL[yyyProdNum]; 
   stDum = yyyStackTop;  
   for (i=1;i<=yyyRHSlength;i++) 
     {pL++; 
      SSALptrHead = SSALptr = *(cPtrPtr = &((stDum++)->solvedSAlist)); 
      if (SSALptr != yyyLambdaSSAL) 
         {*cPtrPtr = yyyLambdaSSAL; 
          do 
            {
             iTemp = (*pL+yyySSALspace[SSALptr].attrbNum);
             yyySignalEnts(yyySTN,
                           yyyEntL + yyyIEL[iTemp],
                           yyyEntL + yyyIEL[iTemp+1]
                          );  
             SSALptr = *(cPtrPtr = &(yyySSALspace[SSALptr].next)); 
            } 
            while (SSALptr != yyyLambdaSSAL);  
          *cPtrPtr = yyySSALCfreeList;  
          yyySSALCfreeList = SSALptrHead;  
         } 
     } 
   nextP = startP + 2;
   while (nextP < stopP) 
     {if (!(*nextP))
         {if ((*(nextP-2)) == yyyR)  
             {pL = &(yyyStackTop->solvedSAlist); 
              if (yyySSALCfreeList == yyyLambdaSSAL) 
                 {yyySSALspace[yyyNewSSALC].next = *pL; 
                  if ((*pL = yyyNewSSALC++) == yyySSALspaceSize) 
                     yyyHandleOverflow(yyySSALof); 
                 }  
                 else
                 {iTemp = yyySSALCfreeList; 
                  yyySSALCfreeList = yyySSALspace[yyySSALCfreeList].next; 
                  yyySSALspace[iTemp].next = *pL; 
                  *pL = iTemp;  
                 } 
              yyySSALspace[*pL].attrbNum = *(nextP-1); 
             } 
             else 
             {if ((gnpDum = (yyySTN->cL)[*(nextP-2)])->prodNum != 0)
                 {
                  iTemp = yyyIIEL[yyyIIIEL[gnpDum->prodNum]] + *(nextP-1);
                  yyySignalEnts(gnpDum, 
                                yyyEntL + yyyIEL[iTemp],  
                                yyyEntL + yyyIEL[iTemp+1] 
                               );    
                 }  
             } 
         } 
      nextP += 3; 
     } 
   yyyStackTop->node = yyySTN;
   if (!yyyRHSlength) yyyStackTop->oldestNode = yyySTN; 
   if (!--intNodeCount) 
      {intNodeCount = yyyDECORfREQ; 
       yyyDecorate(); 
      } 
  } 



void yyyPrune(prodNum) 
  long prodNum;
  {  
   int i,n; 
   register char *cp1,*cp2;  
   register yyyRCT *rcp1,*rcp2,*rcp3;  
   long cycleSum = 0;
   long nNZrc = 0;
   yyyRCT *tempNextRCLspace;
   
   yyyDecorate();
   tempNextRCLspace = yyyNextRCLspace;
   yyyNextRCLspace = 
     (rcp1 = rcp2 = (yyyStackTop->oldestNode)->refCountList) + yyyNattrbs;
   rcp3 = (yyyStackTop->node)->refCountList; 
   while (rcp2 < rcp3) 
     if (*rcp2++) {cycleSum += *(rcp2 - 1); nNZrc++;} 
   if (nNZrc) 
      {
       fprintf(stderr,"\n\n\n----------\n");
       fprintf(stderr,
         "cycle detected during pruning of a subtree\n");
       fprintf(stderr,
         "  at whose root production %d is applied.\n",prodNum);
       yyyNextRCLspace = tempNextRCLspace; 
       fprintf(stderr,
         "prune aborted: searching subtree for %d unsolved instances:\n",
               nNZrc
              );
       yyyUnsolvedInstSearchTrav(yyyStackTop->node);
       return; 
      }
   for (i=0;i<yyyNattrbs;i++) rcp1[i] = rcp3[i]; 
   yyyNextCLspace = (yyyStackTop->oldestNode)->cL; 
   yyyNextNodeSpace = (char *)(yyyStackTop->oldestNode) + 
                      (n = yyyNdPrSz[yyyTypeNum]);
   cp1 = (char *)yyyStackTop->oldestNode; 
   cp2 = (char *)yyyStackTop->node; 
   for (i=0;i<n;i++) *cp1++ = *cp2++; 
   yyyStackTop->node = yyyStackTop->oldestNode; 
   (yyyStackTop->node)->refCountList = rcp1; 
   (yyyStackTop->node)->cL = yyyNextCLspace; 
  } 



void yyyGenLeaf(nAttrbs,typeNum,startP,stopP) 
  int nAttrbs,typeNum; 
  yyyWAT *startP,*stopP; 
  {
   if  (!(yyyTermBuffer.isEmpty)) yyyShift(); 
   yyyTermBuffer.isEmpty = 0;
   yyyTermBuffer.typeNum = typeNum; 
   yyyTermBuffer.nAttrbs = nAttrbs; 
   yyyTermBuffer.startP = startP; 
   yyyTermBuffer.stopP = stopP; 
   
  } 



void yyyerror()
  {yyyYok = 0; 
  } 



/* read the command line for changes in sizes of 
                  the evaluator's data structures */
void yyyCheckForResizes(argc,argv) 
  int argc; 
  char *argv[]; 
  {int i; 
   long dum; 
 
   if (!yyyPermitUserAlloc) return; 
   for (i=1;i<argc;i++) 
     { 
      if ((argv[i][0] != '-') || (argv[i][1] != 'Y')) continue; 
      if (strlen(argv[i]) < 4) goto yyyErrO1; 
      if (sscanf(argv[i]+3,"%d",&dum) != 1) goto yyyErrO1;
      if (dum < 2) dum = 2;
      switch (argv[i][2]) 
        {case yyyNSof:   yyyMaxNbytesNodeStg = dum; break; 
         case yyyRCof:   yyyMaxNrefCounts    = dum; break; 
         case yyyCLof:   yyyMaxNchildren     = dum; break; 
         case yyySof:    yyyMaxStackSize     = dum; break; 
         case yyySSALof: yyySSALspaceSize    = dum; break; 
         case yyyRSof:   yyyRSmaxSize        = dum; break; 
         case yyyTSof:   yyyTravStackMaxSize = dum; break; 
         default : goto yyyErrO1; 
        }
      continue;  
   yyyErrO1 : fprintf(stderr,"invalid command line option: %s\n",
                             argv[i] 
                     ); 
     } 
  } 
   
   
   


#define yyyLastProdNum 52


#define yyyNsorts 12


int yyyProdsInd[] = {
   0,
   0,   1,   3,   6,  10,  17,  18,  20,  22,  26,
  30,  34,  36,  39,  42,  46,  47,  51,  54,  62,
  68,  74,  79,  83,  85,  87,  89,  93,  97, 100,
 104, 108, 110, 115, 117, 121, 125, 129, 131, 135,
 137, 141, 143, 147, 151, 153, 158, 160, 167, 168,
 170, 172,
 176,
};


int yyyProds[][2] = {
{1045,   0},{1045,   0},{ 311,   0},{ 311,   0},{ 197,   4},
{ 537,   0},{ 311,   0},{ 311,   0},{ 197,   4},{ 537,   0},
{ 197,   4},{ 619,   1},{ 419,   0},{  50,   8},{ 425,   0},
{  95,   5},{ 124,   0},{  50,   8},{  50,   8},{ 725,   8},
{ 725,   8},{  46,   3},{ 725,   8},{ 725,   8},{1203,   0},
{  46,   3},{  46,   3},{ 619,   1},{ 597,   0},{ 884,  11},
{  52,   3},{ 619,   1},{ 597,   0},{ 884,  11},{ 884,  11},
{1152,   0},{ 884,  11},{ 848,  11},{1152,   0},{ 848,  11},
{ 310,   0},{ 641,   0},{ 848,  11},{ 848,  11},{ 310,   0},
{ 641,   0},{  95,   5},{  95,   5},{ 278,   7},{ 537,   0},
{  95,   5},{ 278,   7},{ 838,   0},{ 462,  12},{ 278,   7},
{ 635,   0},{ 722,   9},{ 361,   0},{  95,   5},{ 815,   0},
{ 780,   6},{ 124,   0},{ 278,   7},{ 635,   0},{ 722,   9},
{ 361,   0},{  95,   5},{ 124,   0},{ 278,   7},{ 911,   0},
{ 722,   9},{ 702,   0},{  95,   5},{ 124,   0},{ 278,   7},
{ 933,   0},{  52,   3},{ 225,   0},{ 462,  12},{ 278,   7},
{ 318,  12},{ 225,   0},{ 462,  12},{ 278,   7},{1029,  12},
{ 780,   6},{  95,   5},{ 722,   9},{1132,   9},{ 722,   9},
{ 722,   9},{ 737,   0},{1132,   9},{1132,   9},{ 419,   0},
{ 722,   9},{ 425,   0},{1132,   9},{1165,   0},{1132,   9},
{1132,   9},{ 462,  12},{ 431,   0},{ 462,  12},{1132,   9},
{ 462,  12},{ 922,   0},{ 462,  12},{ 318,  12},{ 619,   1},
{ 318,  12},{1029,  12},{ 322,   0},{ 462,  12},{ 328,   0},
{ 462,  12},{1029,  12},{ 462,  12},{1060,  10},{ 258,   0},
{1029,  12},{ 462,  12},{1029,  12},{ 284,   0},{1086,  10},
{ 462,  12},{1029,  12},{1126,   0},{1153,  10},{1060,  10},
{1029,  12},{1060,  10},{1060,  10},{ 258,   0},{1029,  12},
{1086,  10},{1029,  12},{1086,  10},{1029,  12},{ 284,   0},
{1086,  10},{1153,  10},{1029,  12},{1153,  10},{1029,  12},
{1126,   0},{1153,  10},{1029,  12},{ 419,   0},{ 462,  12},
{ 425,   0},{1029,  12},{ 765,   2},{1029,  12},{1029,  12},
{ 322,   0},{ 462,  12},{ 328,   0},{1029,  12},{ 619,   1},
{1029,  12},{ 619,   1},{ 419,   0},{ 899,   0},{ 425,   0},
{ 597,   0},{ 884,  11},{ 899,   0},{ 899,   0},{ 817,   0},
{ 817,   0},{ 462,  12},{ 817,   0},{ 462,  12},{1203,   0},
{ 817,   0},
};


int yyySortsInd[] = {
  0,
  0,  1,  2,  4,  6,  7,  9, 13, 14, 16,
 18, 19,
 22,
};


int yyySorts[] = {
  381,  423,  381,  884,  381, 1058,  141,  141,  529, 1058,
   26,  141,  529, 1116, 1058,  141, 1058,  141,  487,  884,
 1058,  141,
};



char *yyyStringTab[] = {
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,"memvar",0,0,0,
0,0,0,0,0,
0,0,0,0,0,
"astBoolNot","ADD",0,0,0,
0,"pardef",0,0,0,
"params","CALL","vardef",0,0,
0,0,0,0,0,
0,0,0,0,0,
0,"SUB",0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,"Tree",0,
0,0,0,0,0,
"stats",0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,"n",0,0,0,
0,0,"t",0,0,
0,0,"y",0,"END",
0,"astVar",0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,"memt",0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,"astVardef","astFuncdef",
"DEF",0,"astArrayDeref",0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,"funcdef",0,0,
0,"MemTab",0,0,0,
0,0,0,0,0,
0,0,0,0,"labelIfStart",
0,0,"labelWhileStart",0,0,
0,0,"NULL",0,0,
"ASSIGN",0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,"MINUS",0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,"stat",0,
0,0,0,0,"PLUS",
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
"ARRAY","funcdefs",0,0,0,
0,0,0,"lexpr",0,
0,0,"LBRACK",0,0,
0,0,0,"RBRACK",0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,"THEN",0,0,0,
0,0,0,0,0,
0,"PARENT",0,0,0,
0,0,0,0,0,
0,"name",0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,"strdup",0,0,"LPAREN",
0,0,0,"val",0,
"RPAREN",0,0,0,0,
0,"LESS",0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
"printFunctionEpilog",0,0,0,0,
0,0,"expr",0,0,
0,0,0,0,0,
0,0,0,0,0,
0,"printf",0,0,0,
0,0,0,"astAssign",0,
0,0,"depth","LLESS",0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,"ifnr",
0,0,0,0,0,
0,0,"SEMICOLON",0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,"allocMem",
"passIfNrToChildren",0,0,0,0,
0,0,0,0,"assertArray",
0,"varcheck",0,0,0,
0,0,0,0,0,
0,0,0,"LNEQ",0,
0,0,"COLON",0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,"ID",
0,0,0,0,0,
0,0,0,0,0,
0,0,0,"astBoolOp",0,
"IF","MEM",0,0,0,
0,"OF","SEM",0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,"codegen",0,
0,0,0,0,0,
0,0,0,0,0,
0,"TRUE",0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,"astgen",0,0,
0,0,0,0,0,
0,0,0,0,0,
"MUL",0,"DO",0,0,
0,0,0,0,0,
0,0,0,0,"getType",
0,0,0,0,0,
0,0,"bool",0,0,
"parlist",0,0,0,"FALSE",
0,0,0,0,0,
0,"NR","OR",0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,"assertInt",0,
0,0,0,0,0,
"NUM",0,0,0,0,
0,"typcheck",0,"memDeepCopy",0,
0,0,0,0,0,
"elsecode","strtol",0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,"astArithmetic",0,0,
0,0,0,0,0,
"ELSE",0,"exprlist1",0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,"labelIfEnd",0,
0,"labelWhileEnd","labelWhileCond","RETURN",0,
0,"mem2",0,0,0,
0,0,0,"arraylist",0,
0,0,0,0,0,
0,"text",0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,"type",
"BURM",0,0,0,0,
0,0,0,0,0,
0,0,0,0,"exprlist",
0,0,0,0,0,
0,0,0,0,0,
0,"WHILE",0,0,0,
0,0,0,0,0,
"codeIfCounter",0,"HASH",0,0,
0,0,0,0,0,
"checkDuplicates",0,0,"VAR",0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,"astLiteral","assertEqual",0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,"labelElse",
0,0,0,0,0,
0,0,0,0,0,
0,"UNDEFINED",0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,"appendMemParam",0,"yytext",0,
0,0,0,0,"term",
0,0,0,0,0,
"LOR",0,0,0,0,
0,0,0,0,0,
"program",0,0,0,0,
0,0,0,0,0,
0,0,0,"ast",0,
"minus_term",0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,"plus_term",0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,"memp",0,0,0,
0,0,0,0,0,
0,"STAR",0,0,0,
0,0,"bterm",0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,"INT","star_term",0,
0,0,0,0,0,
0,0,0,0,0,
"NOT",0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,"AST",
0,0,0,0,0,
0,"astReturn",0,0,0,
0,0,0,0,0,
0,0,0,"COMMA",0,
0,0,0,0,0,
0,"memTransferStats",0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,
};



#define yyySizeofProd(num) (yyyProdsInd[(num)+1] - yyyProdsInd[(num)])

#define yyyGSoccurStr(prodNum,symPos) \
   (yyyStringTab[yyyProds[yyyProdsInd[(prodNum)] + (symPos)][0]])

#define yyySizeofSort(num) (yyySortsInd[(num)+1] - yyySortsInd[(num)])

#define yyySortOf(prodNum,symPos) \
  (yyyProds[yyyProdsInd[(prodNum)] + (symPos)][1]) 

#define yyyAttrbStr(prodNum,symPos,attrbNum)                      \
  (yyyStringTab[yyySorts[yyySortsInd[yyySortOf(prodNum,symPos)] + \
                         (attrbNum)                               \
                        ]                                         \
               ]                                                  \
  )



void yyyShowProd(i)
  int i;
  {int j,nSyms;

   nSyms = yyySizeofProd(i);
   for (j=0; j<nSyms; j++)
     {
      fprintf(stderr,"%s",yyyGSoccurStr(i,j));
      if (j == 0) fprintf(stderr," : "); else fprintf(stderr," ");
     }
   fprintf(stderr,";\n");
  }



void yyyShowProds()
  {int i; for (i=1; i<=yyyLastProdNum; i++) yyyShowProd(i);}



void yyyShowSymsAndSorts()
  {int i; 

   for (i=1; i<=yyyLastProdNum; i++) 
     {int j, nSyms;

      fprintf(stderr,
              "\n\n\n---------------------------------- %3.1d\n",i);
      /* yyyShowProd(i); */ 
      nSyms = yyySizeofProd(i); 
      for (j=0; j<nSyms; j++) 
        {int k, sortSize;

         fprintf(stderr,"%s\n",yyyGSoccurStr(i,j));
         sortSize = yyySizeofSort(yyySortOf(i,j));
         for (k=0; k<sortSize; k++) 
            fprintf(stderr,"  %s\n",yyyAttrbStr(i,j,k));
         if (j == 0) fprintf(stderr,"->\n"); 
              else 
              fprintf(stderr,"\n"); 
        }
     }
  }



void yyyCheckNodeInstancesSolved(np)
  yyyGNT *np;
  {int mysort,sortSize,i,prodNum,symPos,inTerminalNode;
   int nUnsolvedInsts = 0;

   if (np->prodNum != 0)
     {inTerminalNode = 0;
      prodNum = np->prodNum;
      symPos = 0;
     }
   else
     {inTerminalNode = 1;
      prodNum = ((yyyGNT *)(np->parent))->prodNum;
      symPos = np->whichSym;
     }
   mysort = yyySortOf(prodNum,symPos);
   sortSize = yyySizeofSort(mysort);
   for (i=0; i<sortSize; i++)
     if ((np->refCountList)[i] != 0) nUnsolvedInsts += 1;
   if (nUnsolvedInsts)
     {fprintf(stderr,
      "\nFound node that has %d unsolved attribute instance(s).\n",
              nUnsolvedInsts
             );
      fprintf(stderr,"Node is labeled \"%s\".\n",
             yyyGSoccurStr(prodNum,symPos));
      if (inTerminalNode)
        {fprintf(stderr,
                 "Node is terminal.  Its parent production is:\n  ");
         yyyShowProd(prodNum);
        }
      else
        {fprintf(stderr,"Node is nonterminal.  ");
         if (((char *)(np->parent)) >= yyyNodeSpace)
           {fprintf(stderr,
                    "Node is %dth child in its parent production:\n  ",
                   np->whichSym
                  );
            yyyShowProd(((yyyGNT *)(np->parent))->prodNum);
           }
         fprintf(stderr,
                 "Node is on left hand side of this production:\n  ");
         yyyShowProd(np->prodNum);
        }
      fprintf(stderr,"The following instances are unsolved:\n");
      for (i=0; i<sortSize; i++)
        if ((np->refCountList)[i] != 0)
          fprintf(stderr,"     %-16s still has %1d dependencies.\n",
                  yyyAttrbStr(prodNum,symPos,i),(np->refCountList)[i]);
     }
  }



void yyyUnsolvedInstSearchTravAux(pNode)
  yyyGNT *pNode;
  {yyyGNT **yyyCLpdum;
   int i;
  
   yyyCheckNodeInstancesSolved(pNode); 
   yyyCLpdum = pNode->cL;
   while
     ((yyyCLpdum != yyyNextCLspace) && ((*yyyCLpdum)->parent == pNode))
     {
      yyyUnsolvedInstSearchTravAux(*yyyCLpdum);
      yyyCLpdum++;
     }
  }



void yyyUnsolvedInstSearchTrav(pNode)
  yyyGNT *pNode;
  {yyyGNT **yyyCLpdum;
   int i;
  
   yyyCLpdum = pNode->cL;
   while
     ((yyyCLpdum != yyyNextCLspace) && ((*yyyCLpdum)->parent == pNode))
     {
      yyyUnsolvedInstSearchTravAux(*yyyCLpdum);
      yyyCLpdum++;
     }
  }



