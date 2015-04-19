/*
 * Trabalho de SO I
 * Simulador de MIPS multithreaded
 * Klaus Borges (7986740)
 */

#include <stdio.h>
#include "../include/units.h"


void *control_unit() {
  printf("Control unit thread running.\n");


  printf("Control thread finished!\n");
  pthread_exit(0);
}
