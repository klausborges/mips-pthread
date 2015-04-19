#include <stdio.h>
#include "../include/instructions.h"
#include "../include/registers.h"

int main(int argc, char **argv) {
  printf("Running tests");

  unsigned long i_j   = 0x08000000;
  unsigned long i_add = 0x00000020;
  unsigned long i_slt = 0x0000002A;

  printf("Decoding %x: %u\n", (int) i_j, get_instruction_opcode(i_j));
  printf("Decoding %x: %u\n", (int) i_add, get_instruction_fncode(i_add));
  printf("Decoding %x: %u\n", (int) i_slt, get_instruction_fncode(i_slt));

  return 0;
}
