# Author: Peter Nirschl
# e1025647@student.tuwien.ac.at
CC = gcc
LEX = flex
CFLAGS = -g -lfl

OBJ = scanner

default: $(OBJ)

scanner: scanner.l
	$(LEX) scanner.l
	$(CC) $(CFLAGS) -o scanner scanner.c

clean:
	rm scanner.c
	rm scanner

