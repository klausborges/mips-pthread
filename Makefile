GCC=gcc
CFLAGS_LAZY=-Wall
CFLAGS_HARD=-Wall -pedantic -ansi
CFLAGS=-Wall -ansi
BIN=bin
INC=include
OBJ=obj
SRC=src

all: main

registers:
	$(GCC) $(CFLAGS) -c $(SRC)/registers.c -o $(OBJ)/registers.o

instructions:
	$(GCC) $(CFLAGS) -c $(SRC)/instructions.c -o $(OBJ)/instructions.o

cpu:
	$(GCC) $(CFLAGS) -c $(SRC)/cpu.c -o $(OBJ)/cpu.o

main:
	$(GCC) $(CFLAGS) -c $(SRC)/test.c -o $(OBJ)/test.o

test: main instructions
	gcc $(OBJ)/instructions.o $(OBJ)/test.o -o $(BIN)/test

clean:
	rm -v $(OBJ)/*.o
	rm -v $(BIN)/test
