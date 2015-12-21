# Author: Peter Nirschl
# e1025647@student.tuwien.ac.at
CC = gcc
CFLAGS = -Wall

OBJ = asmb.o

default: $(OBJ)

asmb.o: asmb.s
	$(CC) $(CFLAGS) -c $<

clean:
	rm asmb.o

