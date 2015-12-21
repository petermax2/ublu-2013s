# Author: Peter Nirschl
# e1025647@student.tuwien.ac.at
CC = gcc
LEX = flex
YACC = bison
CFLAGS = -g 

OBJ = parser

default: $(OBJ)

parser: parser.y scanner.l readstd.c
	$(YACC) parser.y
	$(LEX) scanner.l
	$(CC) $(CFLAGS) -o parser parser.c scanner.c readstd.c

clean:
	rm scanner.c || true
	rm scanner.h || true
	rm parser.c || true
	rm parser.h || true
	rm parser || true

