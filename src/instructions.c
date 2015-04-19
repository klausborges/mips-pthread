/*
 * Trabalho de SO I
 * Simulador de MIPS multithreaded
 * Klaus Borges (7986740)
*/

#include <stdio.h>
#include "../include/instructions.h"

unsigned int get_instruction_opcode(unsigned long inst) {
  return inst >> 26;
}

unsigned int get_instruction_fncode(unsigned long inst) {
  return inst & FN_MASK;
}
