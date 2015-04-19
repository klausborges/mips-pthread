GCC=gcc
CFLAGS_LAZY=-Wall
CFLAGS_HARD=-Wall -pedantic -ansi
CFLAGS=-Wall -ansi
PTHREAD=-pthread
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

simp.o:
	$(GCC) $(CFLAGS) -c $(SRC)/simp.c -o $(OBJ)/simp.o

simp: instructions.o cpu.o units.o simp.o
	$(GCC) $(CFLAGS) $(PTHREAD) $(OBJ)/instructions.o $(OBJ)/cpu.o \
		$(OBJ)/units.o $(OBJ)/simp.o -o simp

clean:
	rm -v $(OBJ)/*.o
	rm -v simp
