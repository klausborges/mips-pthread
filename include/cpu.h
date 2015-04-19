/*
 * Trabalho de SO I
 * Simulador de MIPS multithreaded
 * Klaus Borges (7986740)
*/

#ifndef CPU_H
#define CPU_H

#include "../include/registers.h"

/* Program counter, read-only */
extern unsigned long pc;

/* Cycle counter */
extern unsigned int cycle;

/* Registers array */
extern unsigned long registers[N_REGISTERS];

/* Control signals */
#define PCWriteCond 0
#define PCWrite     1
#define IorD        2
#define MemRead     3
#define MemWrite    4
#define MemtoReg    5
#define IRWrite     6
#define PCSource    7
#define ALUOp       8
#define ALUSrcA     9
#define ALUSrcB     10
#define RegWrite    11
#define RegDst      12

/* Number of control signals */
#define N_SIGNALS   13

/* Control signals array */
extern unsigned int signals[N_SIGNALS];

/* Global registers */
extern unsigned int A;
extern unsigned int B;
extern unsigned int IR;      /* instruction register */
extern unsigned int ALUOut;
extern unsigned int MDR;     /* memory data register */


/* Functions */

/* cpu_start
 * Initializes the CPU setting up the starting values */
void cpu_start();

#endif
