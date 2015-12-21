# Author: Peter Nirschl
# e1025647@student.tuwien.ac.at
CC = gcc
CFLAGS = -Wall

OBJ = asma.o

default: $(OBJ)

asma.o: asma.s
	$(CC) $(CFLAGS) -c $<

clean:
	rm asma.o
