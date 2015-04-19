/*
 * Trabalho de SO I
 * Simulador de MIPS multithread
 * Klaus Borges (7986740)
*/

#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

/*      opcode [31-26]    funct [5-0]
  add              00             32
  sub              00             34
  and              00             36
  or               00             37
  slt              00             42
  lw               35
  sw               43
  beq              04
  j                02
*/

/* Macros */

/* Opcodes */
#define OP_FUNC 0
#define OP_J    2
#define OP_BEQ  4
#define OP_LW   35
#define OP_SW   43

/* Function codes for opcode 0 */
#define FN_ADD  32
#define FN_SUB  33
#define FN_AND  36
#define FN_OR   37
#define FN_SLT  42

/* Masks */
#define FNCODE_MASK 0x3f



/* Functions */

/* get_instruction_opcode
 * Returns the decimal opcode of an instruction */
unsigned int get_instruction_opcode(unsigned long);

/* get_instruction_fncode
 * Returns the function code of an instruction */
unsigned int get_instruction_fncode(unsigned long inst);

#endif
