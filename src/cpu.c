/*
 * Trabalho de SO I
 * Simulador de MIPS multithreaded
 * Klaus Borges (7896740)
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include "../include/cpu.h"
#include "../include/units.h"

unsigned int pc, cycle, A, B, IR, ALUOut, MDR;
unsigned int registers[N_REGISTERS];
unsigned int signals[N_SIGNALS];
unsigned int memory[MEMORY_SIZE];

void cpu_start() {
  /* Zeroes every variable */
  pc = 0;
  cycle = 0;
  A = 0;
  B = 0;
  IR = 0;
  ALUOut = 0;
  MDR = 0;

  /* Zeroes all registers and memory */
  int i;
  for (i = 0; i < N_REGISTERS; i++) {
    registers[i] = 0;
  }
  for (i = 0; i < MEMORY_SIZE; i++) {
    memory[i] = 0;
  }

  /* Points the stack pointer to the last memory position */
  RG_SP = STACK_START;
}

void *cpu_run() {
  printf("CPU thread running.\n");

  pthread_t control_unit_thread;

  if (pthread_create(&control_unit_thread, 0, &control_unit, 0)) {
    fprintf(stderr, "Error creating control unit thread. Exiting.\n");
  }

  pthread_join(control_unit_thread, 0);

  printf("CPU thread finished.\n");

  pthread_exit(0);
}

