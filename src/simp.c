/*
 * Trabalho de SO I
 * Simulador de MIPS multithreaded
 * Klaus Borges (7986740)
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "../include/cpu.h"

int main(int argc, char **argv) {
  pthread_t cpu;

  printf("Starting main thread...\n");

  if (pthread_create(&cpu, NULL, &cpu_run, NULL)) {
    fprintf(stderr, "Error creating main CPU thread, exiting.\n");
    return 1;
  }

  pthread_join(cpu, NULL);

  printf("Main thread finished!\n");

  return 0;
}
