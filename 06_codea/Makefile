# Author: Peter Nirschl
# e1025647@student.tuwien.ac.at
CC = gcc
LEX = lex
YACC = yacc
OX = ox

OBJ = codea

default: $(OBJ)

codea: parser.y scanner.l semantic.c matcher.bfe ast.c
	bfe matcher.bfe > matcher.brg
	iburg matcher.brg > matcher.c
	$(OX) parser.y scanner.l
	$(YACC) -d oxout.y
	$(LEX) oxout.l
	$(CC) -g -o codea y.tab.c lex.yy.c semantic.c ast.c matcher.c -ly -ll

clean:
	rm -f matcher.brg
	rm -f matcher.c
	rm -f oxout.*
	rm -f y.tab.*
	rm -f lex.yy.c
	rm -f codea
