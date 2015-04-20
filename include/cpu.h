/*
 * Trabalho de SO I
 * Simulador de MIPS multithreaded
 * Klaus Borges (7986740)
 */

#ifndef CPU_H
#define CPU_H

#include "../include/registers.h"
#include <semaphore.h>
#include <pthread.h>

/* Program counter, should be read-only for all threads except the main one */
extern unsigned int pc;

/* Cycle counter, should be read-only for all thrads except the main one */
extern unsigned int cycle;

/* Registers array */
extern unsigned int registers[N_REGISTERS];

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

/* Memory size is arbitrary, 128KiB divided words (4 bytes ea.),
 * which equals to 32768 memory positions. */
#define MEMORY_SIZE (128<<10)/4

#define STACK_START MEMORY_SIZE-1

extern unsigned int memory[MEMORY_SIZE];

/* Main thread semaphore
 * Indicates a new cycle is running for the unit threads to start working */
extern pthread_mutex_t m_cond;
extern pthread_cond_t c_wait_for_broadcast;

extern pthread_barrier_t b_wait_for_units;
extern pthread_barrier_t b_wait_for_control_unit;

/* */
extern int cpu_loading_threads;


/* Functions */

/* cpu_start
 * Initializes the CPU setting up the starting values */
void cpu_start();

/* cpu_run
 * Function for the main thread of the program, runs all the instructions
 * of a program */
void *cpu_run();

/* cpu_exit
 * Ends all CPU activity, prints out status and frees used memory */
void cpu_exit();

#endif
