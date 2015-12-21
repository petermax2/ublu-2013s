# Author: Peter Nirschl
# e1025647@student.tuwien.ac.at
CC = gcc
LEX = lex
YACC = yacc
OX = ox

OBJ = ag

default: $(OBJ)

ag: parser.y scanner.l semantic.c
	$(OX) parser.y scanner.l
	$(YACC) -d oxout.y
	$(LEX) oxout.l
	$(CC) -g -o ag y.tab.c lex.yy.c semantic.c -ly -ll

clean:
	rm oxout.*
	rm y.tab.*
	rm lex.yy.c
	rm ag
