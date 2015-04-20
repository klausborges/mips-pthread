/*
 * Trabalho de SO I
 * Simulador de MIPS multithreaded
 * Klaus Borges (7896740)
 */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include "../include/cpu.h"
#include "../include/units.h"

unsigned int pc, cycle, A, B, IR, ALUOut, MDR;
unsigned int registers[N_REGISTERS];
unsigned int signals[N_SIGNALS];
unsigned int memory[MEMORY_SIZE];

pthread_mutex_t m_wait_for_signals;
pthread_mutex_t m_cond;
pthread_cond_t c_wait_for_broadcast;
pthread_barrier_t b_wait_for_units;
pthread_barrier_t b_wait_for_control_unit;

int cpu_loading_threads;


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

  /* Initialize mutex */
  pthread_mutex_init(&m_wait_for_signals, NULL);

  /* Initializes cond and its associated mutex */
  pthread_mutex_init(&m_cond, NULL);
  pthread_cond_init(&c_wait_for_broadcast, NULL);

  /* Initializes barrier */
  if (pthread_barrier_init(&b_wait_for_units, NULL, 3)) {
    fprintf(stderr, "ERROR -- could not create barrier\n");
  }

  if (pthread_barrier_init(&b_wait_for_control_unit, NULL, 2)) {
    fprintf(stderr, "ERROR -- could not create barrier\n");
  }
}

void *cpu_run() {
  printf("CPU thread running.\n");

  pthread_mutex_lock(&m_cond);
  cpu_loading_threads = 1;

  /* Creates and starts the control unit thread */
  pthread_t control_unit_thread;
  if (pthread_create(&control_unit_thread, 0, &control_unit, 0)) {
    fprintf(stderr, "Error creating control unit thread. Exiting.\n");
  }

  pthread_t alu_unit_thread;
  if (pthread_create(&alu_unit_thread, 0, &alu_unit, 0)) {
    fprintf(stderr, "Error creating ALU unit thread. Exiting.\n");
  }

  pthread_t alu_control_unit_thread;
  if (pthread_create(&alu_control_unit_thread, 0, &alu_control_unit, 0)) {
    fprintf(stderr, "Error creating ALU Control unit thread. Exiting.\n");
  }

  cpu_loading_threads = 0;

  /* After creating all threads, signals them to load */
  printf("\nCPU finished starting threads, signaling them to wake up.\n\n");
  pthread_mutex_unlock(&m_cond);
  pthread_cond_broadcast(&c_wait_for_broadcast);

  /* Waits for the control unit thread to finish before exiting */
  pthread_join(control_unit_thread, 0);
  printf("CPU thread finished. Exiting.\n");

  pthread_exit(0);
}

void cpu_exit() {
  printf("CPU exiting, destroying variables.");

  pthread_mutex_destroy(&m_wait_for_signals);
  pthread_mutex_destroy(&m_cond);
  pthread_cond_destroy(&c_wait_for_broadcast);
  pthread_barrier_destroy(&b_wait_for_units);
  pthread_barrier_destroy(&b_wait_for_control_unit);
}
