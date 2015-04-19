/*
 * Trabalho de SO I
 * Simulador de MIPS multithreaded
 * Klaus Borges (7986740)
*/

#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

/*
 * Available operations and their op codes/function codes.
 *
 *   OP  OPCODE [31-26] function [5-0]
 * ----------------------------------
 *  add              00             32
 *  sub              00             34
 *  and              00             36
 *   or              00             37
 *  slt              00             42
 *    j              02
 *  beq              04
 *   lw              35
 *   sw              43
*/

/* Op codes */
#define OP_FUNC      0
#define OP_J         2
#define OP_BEQ       4
#define OP_LW       35
#define OP_SW       43

/* Function codes for opcode 0 */
#define FN_ADD      32
#define FN_SUB      33
#define FN_AND      36
#define FN_OR       37
#define FN_SLT      42

/* Masks */
#define FN_MASK   0x3f



/* Functions */

/* get_instruction_opcode
 * Returns the decimal opcode of an instruction */
unsigned int get_instruction_opcode(unsigned long);

/* get_instruction_fncode
 * Returns the function code of an instruction */
unsigned int get_instruction_fncode(unsigned long inst);

#endif
