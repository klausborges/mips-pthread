#include <stdio.h>
#include "../include/instructions.h"

unsigned int get_instruction_opcode(unsigned long inst) {
  return inst >> 26;
}

unsigned int get_instruction_fncode(unsigned long inst) {
  return inst & FNCODE_MASK;
}
