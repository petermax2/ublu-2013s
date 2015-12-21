# Author: Peter Nirschl
# e1025647@student.tuwien.ac.at
BFE = bfe
IBURG = iburg
CC = gcc
LEX = lex
YACC = yacc
OX = ox
TARGET = gesamt

default: $(TARGET)

$(TARGET): parser.y scanner.l semantic.c matcher.bfe ast.c
	$(BFE) matcher.bfe > matcher.brg
	$(IBURG) matcher.brg > matcher.c
	$(OX) parser.y scanner.l
	$(YACC) -d oxout.y
	$(LEX) oxout.l
	$(CC) -g -o $(TARGET) y.tab.c lex.yy.c semantic.c memtab.c ast.c matcher.c -ly -ll

clean:
	rm -f matcher.brg
	rm -f matcher.c
	rm -f oxout.*
	rm -f y.tab.*
	rm -f lex.yy.c
	rm -f $(TARGET)
