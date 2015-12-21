
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

extern YYSTYPE yylval;


