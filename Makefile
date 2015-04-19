GCC=gcc
CFLAGS_LAZY=-Wall
CFLAGS_HARD=-Wall -pedantic -ansi
CFLAGS=-Wall -ansi
BIN=bin
INC=include
OBJ=obj
SRC=src

all: main

registers.o:
	$(GCC) $(CFLAGS) -c $(INC)/registers.h  -o $(OBJ)/registers.o

instructions.o:
	$(GCC) $(CFLAGS) -c $(SRC)/instructions.c -o $(OBJ)/instructions.o

cpu.o:
	$(GCC) $(CFLAGS) -c $(SRC)/cpu.c -o $(OBJ)/cpu.o

units.o:
	$(GCC) $(CFLAGS) -c $(SRC)/units.c -o $(OBJ)/units.o

test.o:
	$(GCC) $(CFLAGS) -c $(SRC)/test.c -o $(OBJ)/test.o

test: test.o instructions.o cpu.o
	$(GCC) $(CFLAGS) $(OBJ)/instructions.o $(OBJ)/cpu.o \
		$(OBJ)/test.o -o $(BIN)/test

clean:
	rm -v $(OBJ)/*.o
	rm -v $(BIN)/test
