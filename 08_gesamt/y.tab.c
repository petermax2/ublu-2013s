
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 2 "oxout.y"


/* Line 189 of yacc.c  */
#line 11 "oxout.y"

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

/* Line 189 of yacc.c  */
#line 81 "oxout.y"



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



/* Line 189 of yacc.c  */
#line 175 "oxout.y"

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


/* Line 189 of yacc.c  */
#line 251 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     END = 258,
     ARRAY = 259,
     OF = 260,
     INT = 261,
     RETURN = 262,
     IF = 263,
     THEN = 264,
     ELSE = 265,
     WHILE = 266,
     DO = 267,
     VAR = 268,
     NOT = 269,
     OR = 270,
     SEMICOLON = 271,
     LPAREN = 272,
     RPAREN = 273,
     COMMA = 274,
     COLON = 275,
     ASSIGN = 276,
     LESS = 277,
     HASH = 278,
     LBRACK = 279,
     RBRACK = 280,
     MINUS = 281,
     PLUS = 282,
     STAR = 283,
     ID = 284,
     NUM = 285
   };
#endif
/* Tokens.  */
#define END 258
#define ARRAY 259
#define OF 260
#define INT 261
#define RETURN 262
#define IF 263
#define THEN 264
#define ELSE 265
#define WHILE 266
#define DO 267
#define VAR 268
#define NOT 269
#define OR 270
#define SEMICOLON 271
#define LPAREN 272
#define RPAREN 273
#define COMMA 274
#define COLON 275
#define ASSIGN 276
#define LESS 277
#define HASH 278
#define LBRACK 279
#define RBRACK 280
#define MINUS 281
#define PLUS 282
#define STAR 283
#define ID 284
#define NUM 285




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 353 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   107

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  55
/* YYNRULES -- Number of states.  */
#define YYNSTATES  109

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     7,     8,    10,    13,    17,    24,
      25,    27,    29,    33,    37,    41,    43,    46,    49,    53,
      54,    58,    61,    69,    75,    81,    86,    90,    92,    94,
      96,   100,   104,   107,   111,   115,   117,   122,   124,   128,
     132,   136,   138,   142,   144,   148,   150,   154,   158,   160,
     165,   167,   174,   175,   177,   179
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      32,     0,    -1,    -1,    33,    34,    -1,    -1,    35,    -1,
      36,    16,    -1,    35,    36,    16,    -1,    29,    17,    37,
      18,    43,     3,    -1,    -1,    38,    -1,    39,    -1,    38,
      19,    39,    -1,    29,    20,    41,    -1,    29,    20,    41,
      -1,     6,    -1,    42,     6,    -1,     4,     5,    -1,    42,
       4,     5,    -1,    -1,    44,    16,    43,    -1,     7,    49,
      -1,     8,    46,     9,    43,    10,    45,     3,    -1,     8,
      46,     9,    43,     3,    -1,    11,    46,    12,    43,     3,
      -1,    13,    40,    21,    49,    -1,    48,    21,    49,    -1,
      53,    -1,    43,    -1,    47,    -1,    46,    15,    47,    -1,
      17,    46,    18,    -1,    14,    47,    -1,    49,    22,    49,
      -1,    49,    23,    49,    -1,    29,    -1,    53,    24,    49,
      25,    -1,    53,    -1,    50,    26,    53,    -1,    53,    27,
      51,    -1,    53,    28,    52,    -1,    53,    -1,    50,    26,
      53,    -1,    53,    -1,    53,    27,    51,    -1,    53,    -1,
      53,    28,    52,    -1,    17,    49,    18,    -1,    30,    -1,
      53,    24,    49,    25,    -1,    29,    -1,    29,    17,    54,
      18,    20,    41,    -1,    -1,    55,    -1,    49,    -1,    49,
      19,    55,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   210,   210,   210,   222,   225,   232,   236,   242,   253,
     257,   264,   269,   276,   284,   292,   297,   304,   309,   317,
     320,   329,   338,   350,   360,   370,   378,   388,   399,   406,
     413,   423,   430,   437,   445,   455,   462,   473,   481,   490,
     499,   510,   517,   527,   534,   544,   551,   561,   569,   576,
     585,   592,   601,   604,   610,   616
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "END", "ARRAY", "OF", "INT", "RETURN",
  "IF", "THEN", "ELSE", "WHILE", "DO", "VAR", "NOT", "OR", "SEMICOLON",
  "LPAREN", "RPAREN", "COMMA", "COLON", "ASSIGN", "LESS", "HASH", "LBRACK",
  "RBRACK", "MINUS", "PLUS", "STAR", "ID", "NUM", "$accept",
  "yyyAugNonterm", "$@1", "program", "funcdefs", "funcdef", "params",
  "parlist", "pardef", "vardef", "type", "arraylist", "stats", "stat",
  "elsecode", "bool", "bterm", "lexpr", "expr", "minus_term", "plus_term",
  "star_term", "term", "exprlist", "exprlist1", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    31,    33,    32,    34,    34,    35,    35,    36,    37,
      37,    38,    38,    39,    40,    41,    41,    42,    42,    43,
      43,    44,    44,    44,    44,    44,    44,    44,    45,    46,
      46,    47,    47,    47,    47,    48,    48,    49,    49,    49,
      49,    50,    50,    51,    51,    52,    52,    53,    53,    53,
      53,    53,    54,    54,    55,    55
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     0,     1,     2,     3,     6,     0,
       1,     1,     3,     3,     3,     1,     2,     2,     3,     0,
       3,     2,     7,     5,     5,     4,     3,     1,     1,     1,
       3,     3,     2,     3,     3,     1,     4,     1,     3,     3,
       3,     1,     3,     1,     3,     1,     3,     3,     1,     4,
       1,     6,     0,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     4,     1,     0,     3,     5,     0,     9,     0,
       6,     0,     0,    10,    11,     7,     0,    19,     0,     0,
      15,    13,     0,     0,     0,     0,     0,     0,    50,    48,
       0,     0,     0,    27,    12,    17,     0,    16,    50,    21,
       0,    37,     0,     0,     0,    29,     0,     0,     0,     0,
       0,    52,     8,    19,     0,     0,    18,     0,     0,     0,
       0,    32,     0,     0,    19,     0,     0,     0,    19,     0,
       0,    47,    54,     0,    53,    20,    26,     0,    38,     0,
      39,    43,    40,    45,    31,     0,    30,    33,    34,     0,
      14,    25,     0,     0,    49,    49,     0,     0,    23,    19,
      24,    55,     0,    44,    46,    28,     0,    51,    22
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     5,     6,     7,    12,    13,    14,    49,
      21,    22,    30,    31,   106,    44,    45,    32,    46,    40,
      80,    82,    41,    73,    74
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -65
static const yytype_int8 yypact[] =
{
     -65,    18,   -20,   -65,    31,   -65,   -20,    48,    40,    56,
     -65,    53,    59,    62,   -65,   -65,    61,    45,    40,    78,
     -65,   -65,    64,    -1,    -4,    -4,    55,    -1,    -9,   -65,
      82,    70,    66,    65,   -65,   -65,    83,   -65,    73,   -65,
      67,    33,    -4,    -4,     2,   -65,    32,     8,    71,    74,
      76,    -1,   -65,    45,    -1,    -1,   -65,    -1,    -1,    -1,
      -1,   -65,    26,     9,    45,    -4,    -1,    -1,    45,    61,
      -1,   -65,    77,    79,   -65,   -65,   -65,    75,    52,    80,
     -65,    39,   -65,    11,   -65,     4,   -65,   -65,   -65,    89,
     -65,   -65,    -1,    81,    85,   -65,    -1,    -1,   -65,    45,
     -65,   -65,    61,   -65,   -65,   -65,    95,   -65,   -65
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -65,   -65,   -65,   -65,   -65,    93,   -65,   -65,    84,   -65,
     -64,   -65,   -49,   -65,   -65,   -22,   -41,   -65,   -21,   -65,
       7,    10,   -17,   -65,    12
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -43
static const yytype_int8 yytable[] =
{
      33,    61,    39,    47,    75,    90,    50,    98,    51,     4,
      42,    64,   -35,    43,    99,    85,    27,    65,     3,    89,
      68,    62,    63,    65,    86,    38,    29,    71,    38,    29,
      72,    66,    67,    76,    77,    58,    33,    79,   107,    97,
      78,    65,    81,    83,    84,    87,    88,    33,     8,    91,
     105,    33,    23,    24,    66,    67,    25,    58,    26,   -41,
      59,    60,    27,    58,    10,    19,    96,    20,    36,    11,
      37,    72,    15,    16,    28,    29,    58,    17,   -42,    81,
      83,    18,    33,    35,    48,    52,    53,    54,    56,    55,
      51,    69,   100,    57,    71,    70,    92,    93,   108,     9,
      94,   102,    34,   103,   101,    95,   -36,   104
};

static const yytype_uint8 yycheck[] =
{
      17,    42,    23,    25,    53,    69,    27,     3,    17,    29,
      14,     9,    21,    17,    10,    64,    17,    15,     0,    68,
      12,    43,    43,    15,    65,    29,    30,    18,    29,    30,
      51,    22,    23,    54,    55,    24,    53,    58,   102,    28,
      57,    15,    59,    60,    18,    66,    67,    64,    17,    70,
      99,    68,     7,     8,    22,    23,    11,    24,    13,    26,
      27,    28,    17,    24,    16,     4,    27,     6,     4,    29,
       6,    92,    16,    20,    29,    30,    24,    18,    26,    96,
      97,    19,    99,     5,    29,     3,    16,    21,     5,    24,
      17,    20,     3,    26,    18,    21,    19,    18,     3,     6,
      25,    20,    18,    96,    92,    25,    21,    97
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,    33,     0,    29,    34,    35,    36,    17,    36,
      16,    29,    37,    38,    39,    16,    20,    18,    19,     4,
       6,    41,    42,     7,     8,    11,    13,    17,    29,    30,
      43,    44,    48,    53,    39,     5,     4,     6,    29,    49,
      50,    53,    14,    17,    46,    47,    49,    46,    29,    40,
      49,    17,     3,    16,    21,    24,     5,    26,    24,    27,
      28,    47,    46,    49,     9,    15,    22,    23,    12,    20,
      21,    18,    49,    54,    55,    43,    49,    49,    53,    49,
      51,    53,    52,    53,    18,    43,    47,    49,    49,    43,
      41,    49,    19,    18,    25,    25,    27,    28,     3,    10,
       3,    55,    20,    51,    52,    43,    45,    41,     3
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 210 "oxout.y"
    {if (!yyyInitDone) 
		    {yyyYoxInit(); 
		     yyyInitDone = 1;
		    }
		 yyyYoxReset();
		}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 217 "oxout.y"
    {
		 yyyDecorate(); yyyExecuteRRsection();
		}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 222 "oxout.y"
    {if(yyyYok){
yyyRSU(1,0,0,0);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+0,yyyRCIL+0);}}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 226 "oxout.y"
    {if(yyyYok){
yyyRSU(2,1,0,0);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+0,yyyRCIL+0);/*yyyPrune(2);*/}}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 233 "oxout.y"
    {if(yyyYok){
yyyRSU(3,2,0,0);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+0,yyyRCIL+0);/*yyyPrune(3);*/}}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 237 "oxout.y"
    {if(yyyYok){
yyyRSU(4,3,0,0);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+0,yyyRCIL+0);/*yyyPrune(4);*/}}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 243 "oxout.y"
    {if(yyyYok){
yyyRSU(5,6,2,4);
yyyGenIntNode();
 (((yyyP4)yyySTsn)->ast) = NULL;
		   (((yyyP5)(((char *)((yyySTN->cL)[4]))+yyyGNSz))->memt) = NULL; 
		   (((yyyP4)yyySTsn)->name) = (((yyyP1)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->name);
		  yyyAdjustINRC(yyyRCIL+0,yyyRCIL+9);/*yyyPrune(5);*/}}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 253 "oxout.y"
    {if(yyyYok){
yyyRSU(6,0,1,8);
yyyGenIntNode();
 (((yyyP8)yyySTsn)->memp) = NULL; yyyAdjustINRC(yyyRCIL+9,yyyRCIL+12);}}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 258 "oxout.y"
    {if(yyyYok){
yyyRSU(7,1,1,8);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+12,yyyRCIL+15);/*yyyPrune(7);*/}}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 265 "oxout.y"
    {if(yyyYok){
yyyRSU(8,1,1,8);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+15,yyyRCIL+18);/*yyyPrune(8);*/}}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 270 "oxout.y"
    {if(yyyYok){
yyyRSU(9,3,1,8);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+18,yyyRCIL+21);/*yyyPrune(9);*/}}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 277 "oxout.y"
    {if(yyyYok){
yyyRSU(10,3,2,3);
yyyGenIntNode();
 (((yyyP3)yyySTsn)->name) = (((yyyP1)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->name);
		  yyyAdjustINRC(yyyRCIL+21,yyyRCIL+27);/*yyyPrune(10);*/}}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 285 "oxout.y"
    {if(yyyYok){
yyyRSU(11,3,2,3);
yyyGenIntNode();
 (((yyyP3)yyySTsn)->name) = (((yyyP1)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->name);
		  yyyAdjustINRC(yyyRCIL+27,yyyRCIL+33);/*yyyPrune(11);*/}}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 293 "oxout.y"
    {if(yyyYok){
yyyRSU(12,1,1,11);
yyyGenIntNode();
 (((yyyP11)yyySTsn)->depth) = 0; yyyAdjustINRC(yyyRCIL+33,yyyRCIL+36);/*yyyPrune(12);*/}}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 298 "oxout.y"
    {if(yyyYok){
yyyRSU(13,2,1,11);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+36,yyyRCIL+39);/*yyyPrune(13);*/}}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 305 "oxout.y"
    {if(yyyYok){
yyyRSU(14,2,1,11);
yyyGenIntNode();
 (((yyyP11)yyySTsn)->depth) = 1; yyyAdjustINRC(yyyRCIL+39,yyyRCIL+42);/*yyyPrune(14);*/}}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 310 "oxout.y"
    {if(yyyYok){
yyyRSU(15,3,1,11);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+42,yyyRCIL+45);/*yyyPrune(15);*/}}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 317 "oxout.y"
    {if(yyyYok){
yyyRSU(16,0,1,5);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+45,yyyRCIL+45);}}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 321 "oxout.y"
    {if(yyyYok){
yyyRSU(17,3,1,5);
yyyGenIntNode();
 (((yyyP5)(((char *)((yyySTN->cL)[2]))+yyyGNSz))->memt) = NULL; 
		   (((yyyP7)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL; 
		  yyyAdjustINRC(yyyRCIL+45,yyyRCIL+51);/*yyyPrune(17);*/}}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 330 "oxout.y"
    {if(yyyYok){
yyyRSU(18,2,4,7);
yyyGenIntNode();
 (((yyyP12)(((char *)((yyySTN->cL)[1]))+yyyGNSz))->memt) = NULL; 
		   (((yyyP7)yyySTsn)->ast) = NULL;
		   (((yyyP7)yyySTsn)->memvar) = NULL; 
		   (((yyyP7)yyySTsn)->ifnr) = DEF_IF_NR;
		  yyyAdjustINRC(yyyRCIL+51,yyyRCIL+63);/*yyyPrune(18);*/}}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 339 "oxout.y"
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
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 351 "oxout.y"
    {if(yyyYok){
yyyRSU(20,5,4,7);
yyyGenIntNode();
 (((yyyP9)(((char *)((yyySTN->cL)[1]))+yyyGNSz))->memt) = NULL; 
		   (((yyyP5)(((char *)((yyySTN->cL)[3]))+yyyGNSz))->memt) = NULL; 
		   (((yyyP7)yyySTsn)->ast) = NULL;
		   (((yyyP7)yyySTsn)->memvar) = NULL; 
		   (((yyyP7)yyySTsn)->ifnr) = ++codeIfCounter;
		  yyyAdjustINRC(yyyRCIL+84,yyyRCIL+99);/*yyyPrune(20);*/}}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 361 "oxout.y"
    {if(yyyYok){
yyyRSU(21,5,4,7);
yyyGenIntNode();
 (((yyyP9)(((char *)((yyySTN->cL)[1]))+yyyGNSz))->memt) = NULL; 
		   (((yyyP5)(((char *)((yyySTN->cL)[3]))+yyyGNSz))->memt) = NULL; 
		   (((yyyP7)yyySTsn)->ast) = NULL;
		   (((yyyP7)yyySTsn)->memvar) = NULL; 
		   (((yyyP7)yyySTsn)->ifnr) = ++codeIfCounter;
		  yyyAdjustINRC(yyyRCIL+99,yyyRCIL+114);/*yyyPrune(21);*/}}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 371 "oxout.y"
    {if(yyyYok){
yyyRSU(22,4,4,7);
yyyGenIntNode();
 (((yyyP12)(((char *)((yyySTN->cL)[3]))+yyyGNSz))->memt) = NULL; 
		   (((yyyP7)yyySTsn)->ast) = NULL;
		   (((yyyP7)yyySTsn)->ifnr) = DEF_IF_NR;
		  yyyAdjustINRC(yyyRCIL+114,yyyRCIL+126);/*yyyPrune(22);*/}}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 379 "oxout.y"
    {if(yyyYok){
yyyRSU(23,3,4,7);
yyyGenIntNode();
 (((yyyP12)(((char *)((yyySTN->cL)[2]))+yyyGNSz))->memt) = NULL; 
		   (((yyyP12)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL;
		   (((yyyP7)yyySTsn)->ast) = NULL;
		   (((yyyP7)yyySTsn)->memvar) = NULL;
		   (((yyyP7)yyySTsn)->ifnr) = DEF_IF_NR;
		  yyyAdjustINRC(yyyRCIL+126,yyyRCIL+141);/*yyyPrune(23);*/}}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 389 "oxout.y"
    {if(yyyYok){
yyyRSU(24,1,4,7);
yyyGenIntNode();
 (((yyyP12)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL;
		   (((yyyP7)yyySTsn)->ast) = NULL;
		   (((yyyP7)yyySTsn)->memvar) = NULL;
		   (((yyyP7)yyySTsn)->ifnr) = DEF_IF_NR;
		  yyyAdjustINRC(yyyRCIL+141,yyyRCIL+153);/*yyyPrune(24);*/}}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 400 "oxout.y"
    {if(yyyYok){
yyyRSU(25,1,2,6);
yyyGenIntNode();
 (((yyyP5)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL;
		  yyyAdjustINRC(yyyRCIL+153,yyyRCIL+156);/*yyyPrune(25);*/}}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 407 "oxout.y"
    {if(yyyYok){
yyyRSU(26,1,2,9);
yyyGenIntNode();
 (((yyyP9)yyySTsn)->ast) = NULL;
		   (((yyyP9)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL;
		  yyyAdjustINRC(yyyRCIL+156,yyyRCIL+162);/*yyyPrune(26);*/}}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 414 "oxout.y"
    {if(yyyYok){
yyyRSU(27,3,2,9);
yyyGenIntNode();
 (((yyyP9)yyySTsn)->ast) = NULL;
		   (((yyyP9)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL; 
		   (((yyyP9)(((char *)((yyySTN->cL)[2]))+yyyGNSz))->memt) = NULL; 
		  yyyAdjustINRC(yyyRCIL+162,yyyRCIL+171);/*yyyPrune(27);*/}}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 424 "oxout.y"
    {if(yyyYok){
yyyRSU(28,3,2,9);
yyyGenIntNode();
 (((yyyP9)yyySTsn)->ast) = NULL; 
		   (((yyyP9)(((char *)((yyySTN->cL)[1]))+yyyGNSz))->memt) = NULL; 
		  yyyAdjustINRC(yyyRCIL+171,yyyRCIL+177);/*yyyPrune(28);*/}}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 431 "oxout.y"
    {if(yyyYok){
yyyRSU(29,2,2,9);
yyyGenIntNode();
 (((yyyP9)yyySTsn)->ast) = NULL;
		   (((yyyP9)(((char *)((yyySTN->cL)[1]))+yyyGNSz))->memt) = NULL; 
		  yyyAdjustINRC(yyyRCIL+177,yyyRCIL+183);/*yyyPrune(29);*/}}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 438 "oxout.y"
    {if(yyyYok){
yyyRSU(30,3,2,9);
yyyGenIntNode();
 (((yyyP9)yyySTsn)->ast) = NULL; 
		   (((yyyP12)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL; 
		   (((yyyP12)(((char *)((yyySTN->cL)[2]))+yyyGNSz))->memt) = NULL;
		  yyyAdjustINRC(yyyRCIL+183,yyyRCIL+192);/*yyyPrune(30);*/}}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 446 "oxout.y"
    {if(yyyYok){
yyyRSU(31,3,2,9);
yyyGenIntNode();
 (((yyyP9)yyySTsn)->ast) = NULL; 
		   (((yyyP12)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL; 
		   (((yyyP12)(((char *)((yyySTN->cL)[2]))+yyyGNSz))->memt) = NULL; 
		  yyyAdjustINRC(yyyRCIL+192,yyyRCIL+201);/*yyyPrune(31);*/}}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 456 "oxout.y"
    {if(yyyYok){
yyyRSU(32,1,3,12);
yyyGenIntNode();
 (((yyyP12)yyySTsn)->type) = SEM_UNDEFINED;
		   (((yyyP12)yyySTsn)->ast) = NULL;
		  yyyAdjustINRC(yyyRCIL+201,yyyRCIL+207);/*yyyPrune(32);*/}}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 463 "oxout.y"
    {if(yyyYok){
yyyRSU(33,4,3,12);
yyyGenIntNode();
 (((yyyP12)yyySTsn)->type) = SEM_UNDEFINED;
		   (((yyyP12)yyySTsn)->ast) = NULL;
		   (((yyyP12)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL; 
		   (((yyyP12)(((char *)((yyySTN->cL)[2]))+yyyGNSz))->memt) = NULL; 
		  yyyAdjustINRC(yyyRCIL+207,yyyRCIL+219);/*yyyPrune(33);*/}}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 474 "oxout.y"
    {if(yyyYok){
yyyRSU(34,1,3,12);
yyyGenIntNode();
 (((yyyP12)yyySTsn)->type) = SEM_UNDEFINED;
		   (((yyyP12)yyySTsn)->ast) = NULL;
		   (((yyyP12)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL; 
		  yyyAdjustINRC(yyyRCIL+219,yyyRCIL+228);/*yyyPrune(34);*/}}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 482 "oxout.y"
    {if(yyyYok){
yyyRSU(35,3,3,12);
yyyGenIntNode();
 (((yyyP12)yyySTsn)->type) = SEM_UNDEFINED;
		   (((yyyP12)yyySTsn)->ast) = NULL;
		   (((yyyP12)(((char *)((yyySTN->cL)[2]))+yyyGNSz))->memt) = NULL; 
		   (((yyyP10)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL; 
		  yyyAdjustINRC(yyyRCIL+228,yyyRCIL+240);/*yyyPrune(35);*/}}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 491 "oxout.y"
    {if(yyyYok){
yyyRSU(36,3,3,12);
yyyGenIntNode();
 (((yyyP12)yyySTsn)->type) = SEM_UNDEFINED;
		   (((yyyP12)yyySTsn)->ast) = NULL;
		   (((yyyP12)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL; 
		   (((yyyP10)(((char *)((yyySTN->cL)[2]))+yyyGNSz))->memt) = NULL; 
		  yyyAdjustINRC(yyyRCIL+240,yyyRCIL+252);/*yyyPrune(36);*/}}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 500 "oxout.y"
    {if(yyyYok){
yyyRSU(37,3,3,12);
yyyGenIntNode();
 (((yyyP12)yyySTsn)->type) = SEM_UNDEFINED;
		   (((yyyP12)yyySTsn)->ast) = NULL;
		   (((yyyP12)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL; 
		   (((yyyP10)(((char *)((yyySTN->cL)[2]))+yyyGNSz))->memt) = NULL; 
		  yyyAdjustINRC(yyyRCIL+252,yyyRCIL+264);/*yyyPrune(37);*/}}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 511 "oxout.y"
    {if(yyyYok){
yyyRSU(38,1,2,10);
yyyGenIntNode();
 (((yyyP10)yyySTsn)->ast) = NULL;
		   (((yyyP12)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL; 
		  yyyAdjustINRC(yyyRCIL+264,yyyRCIL+270);/*yyyPrune(38);*/}}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 518 "oxout.y"
    {if(yyyYok){
yyyRSU(39,3,2,10);
yyyGenIntNode();
 (((yyyP10)yyySTsn)->ast) = NULL;
		   (((yyyP12)(((char *)((yyySTN->cL)[2]))+yyyGNSz))->memt) = NULL; 
		   (((yyyP10)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL; 
		  yyyAdjustINRC(yyyRCIL+270,yyyRCIL+279);/*yyyPrune(39);*/}}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 528 "oxout.y"
    {if(yyyYok){
yyyRSU(40,1,2,10);
yyyGenIntNode();
 (((yyyP10)yyySTsn)->ast) = NULL;
		   (((yyyP12)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL; 
		  yyyAdjustINRC(yyyRCIL+279,yyyRCIL+285);/*yyyPrune(40);*/}}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 535 "oxout.y"
    {if(yyyYok){
yyyRSU(41,3,2,10);
yyyGenIntNode();
 (((yyyP10)yyySTsn)->ast) = NULL;
		   (((yyyP12)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL; 
	 	   (((yyyP10)(((char *)((yyySTN->cL)[2]))+yyyGNSz))->memt) = NULL; 
		  yyyAdjustINRC(yyyRCIL+285,yyyRCIL+294);/*yyyPrune(41);*/}}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 545 "oxout.y"
    {if(yyyYok){
yyyRSU(42,1,2,10);
yyyGenIntNode();
 (((yyyP10)yyySTsn)->ast) = NULL;
		   (((yyyP12)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL; 
		  yyyAdjustINRC(yyyRCIL+294,yyyRCIL+300);/*yyyPrune(42);*/}}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 552 "oxout.y"
    {if(yyyYok){
yyyRSU(43,3,2,10);
yyyGenIntNode();
 (((yyyP10)yyySTsn)->ast) = NULL;
		   (((yyyP12)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL; 
		   (((yyyP10)(((char *)((yyySTN->cL)[2]))+yyyGNSz))->memt) = NULL; 
		  yyyAdjustINRC(yyyRCIL+300,yyyRCIL+309);/*yyyPrune(43);*/}}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 562 "oxout.y"
    {if(yyyYok){
yyyRSU(44,3,3,12);
yyyGenIntNode();
 (((yyyP12)yyySTsn)->type) = SEM_UNDEFINED;
		   (((yyyP12)yyySTsn)->ast) = NULL;
		   (((yyyP12)(((char *)((yyySTN->cL)[1]))+yyyGNSz))->memt) = NULL; 
		  yyyAdjustINRC(yyyRCIL+309,yyyRCIL+318);/*yyyPrune(44);*/}}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 570 "oxout.y"
    {if(yyyYok){
yyyRSU(45,1,3,12);
yyyGenIntNode();
 (((yyyP12)yyySTsn)->type) = SEM_INT; 
		   (((yyyP12)yyySTsn)->ast) = NULL; 
		  yyyAdjustINRC(yyyRCIL+318,yyyRCIL+324);/*yyyPrune(45);*/}}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 577 "oxout.y"
    {if(yyyYok){
yyyRSU(46,4,3,12);
yyyGenIntNode();
 (((yyyP12)yyySTsn)->type) = SEM_UNDEFINED;
		   (((yyyP12)yyySTsn)->ast) = NULL; 
		   (((yyyP12)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL; 
		   (((yyyP12)(((char *)((yyySTN->cL)[2]))+yyyGNSz))->memt) = NULL; 
		  yyyAdjustINRC(yyyRCIL+324,yyyRCIL+336);/*yyyPrune(46);*/}}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 586 "oxout.y"
    {if(yyyYok){
yyyRSU(47,1,3,12);
yyyGenIntNode();
 (((yyyP12)yyySTsn)->ast) = NULL; 
		   (((yyyP12)yyySTsn)->type) = SEM_UNDEFINED;
		  yyyAdjustINRC(yyyRCIL+336,yyyRCIL+342);/*yyyPrune(47);*/}}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 593 "oxout.y"
    {if(yyyYok){
yyyRSU(48,6,3,12);
yyyGenIntNode();
 (((yyyP12)yyySTsn)->ast) = NULL; 
		  yyyAdjustINRC(yyyRCIL+342,yyyRCIL+348);/*yyyPrune(48);*/}}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 601 "oxout.y"
    {if(yyyYok){
yyyRSU(49,0,0,0);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+348,yyyRCIL+348);}}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 605 "oxout.y"
    {if(yyyYok){
yyyRSU(50,1,0,0);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+348,yyyRCIL+348);/*yyyPrune(50);*/}}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 611 "oxout.y"
    {if(yyyYok){
yyyRSU(51,1,0,0);
yyyGenIntNode();
 (((yyyP12)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL; 
		yyyAdjustINRC(yyyRCIL+348,yyyRCIL+351);/*yyyPrune(51);*/}}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 617 "oxout.y"
    {if(yyyYok){
yyyRSU(52,3,0,0);
yyyGenIntNode();
 (((yyyP12)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->memt) = NULL; 
		yyyAdjustINRC(yyyRCIL+351,yyyRCIL+354);/*yyyPrune(52);*/}}
    break;



/* Line 1455 of yacc.c  */
#line 2281 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 625 "oxout.y"


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




