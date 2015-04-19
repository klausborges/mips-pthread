/*
 * Trabalho de SO I
 * Simulador de MIPS multithreaded
 * Klaus Borges (7896740)
*/

#include "../include/cpu.h"

void cpu_start() {
  /* Clears and starts up every variable */
  pc = 0;
  cycle = 0;

  int i;
  for (i = 0; i < N_REGISTERS; i++) {
    registers[i] = 0;
  }
}
