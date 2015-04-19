/*
 * Trabalho de SO I
 * Simulador de MIPS multithreaded
 * Klaus Borges (7986740)
*/

#include <stdio.h>
#include "../include/instructions.h"

unsigned int get_instruction_opcode(unsigned int inst) {
  return inst >> 26;
}

unsigned int get_instruction_fncode(unsigned int inst) {
  return inst & FN_MASK;
}

unsigned int get_instruction_rs(unsigned int inst) {
  return (inst & RS_MASK) >> 21;
}

unsigned int get_instruction_rt(unsigned int inst) {
  return (inst & RT_MASK) >> 16;
}

unsigned int get_instruction_rd(unsigned int inst) {
  return (inst & RD_MASK) >> 11;
}

unsigned int get_instruction_target(unsigned int inst) {
  return inst & TARGET_MASK;
}

unsigned int get_instruction_offset(unsigned int inst) {
  return inst & OFFSET_MASK;
}
