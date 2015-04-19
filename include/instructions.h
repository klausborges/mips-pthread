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

/* Masks to get certain fields from the binary instructions
 *
 *        Field         Hex mask                                 Binary mask */
#define FN_MASK       0x0000003F  /* 0000 0000 0000 0000 0000 0000 0011 1111 */
#define RS_MASK       0x03E00000  /* 0000 0011 1110 0000 0000 0000 0000 0000 */
#define RT_MASK       0x001F0000  /* 0000 0000 0001 1111 0000 0000 0000 0000 */
#define RD_MASK       0x0000F800  /* 0000 0000 0000 0000 1111 1000 0000 0000 */
#define TARGET_MASK   0x03FFFFFF  /* 0000 0011 1111 1111 1111 1111 1111 1111 */
#define OFFSET_MASK   0x0000FFFF  /* 0000 0000 0000 0000 1111 1111 1111 1111 */



/* Functions */

/* get_instruction_opcode
 * Returns the decimal opcode of an instruction */
unsigned int get_instruction_opcode(unsigned int);

/* get_instruction_fncode
 * Returns the function code of an instruction */
unsigned int get_instruction_fncode(unsigned int);

/* get_instruction_rs
 * Returns the number of the rs register of an instruction */
unsigned int get_instruction_rs(unsigned int);

/* get_instruction_rt
 * Returns the number of the rt register of an instruction */
unsigned int get_instruction_rt(unsigned int);

/* get_instruction_rd
 * Returns the number of the rd register of an instruction */
unsigned int get_instruction_rd(unsigned int);

/* get_instruction_target
 * Returns the target address for the jump instruction */
unsigned int get_instruction_target(unsigned int);

/* get_instruction_offset
 * Returns the offset for the load, store and branch if equal instructions */
unsigned int get_instruction_offset(unsigned int);

#endif
