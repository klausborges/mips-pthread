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

  unsigned long i_test = 0x04444010;
  printf("Decoding %x:\n", (unsigned int) i_test);
  printf("     Opcode: %u\n", get_instruction_opcode(i_test));
  printf("         RS: %u\n", get_instruction_rs(i_test));
  printf("         RT: %u\n", get_instruction_rt(i_test));
  printf("         RD: %u\n", get_instruction_rd(i_test));
  printf("     Fncode: %u\n", get_instruction_fncode(i_test));

  unsigned long t_test = 0x031F0FFF;
  printf("Decoding %x: %lu\n", (unsigned int) t_test,
      get_instruction_target(t_test));

  return 0;
}
