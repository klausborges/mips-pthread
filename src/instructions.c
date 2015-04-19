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

unsigned int get_instruction_rs(unsigned long inst) {
  return (inst & RS_MASK) >> 21;
}

unsigned int get_instruction_rt(unsigned long inst) {
  return (inst & RT_MASK) >> 16;
}

unsigned int get_instruction_rd(unsigned long inst) {
  return (inst & RD_MASK) >> 11;
}

unsigned long get_instruction_target(unsigned long inst) {
  return inst & TARGET_MASK;
}

unsigned int get_instruction_offset(unsigned long inst) {
  return inst & OFFSET_MASK;
}
