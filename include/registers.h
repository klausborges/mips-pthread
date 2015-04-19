/*
 * Trabalho de SO I
 * Simulador de MIPS multithreaded
 * Klaus Borges (7986740)
*/

#ifndef REGISTERS_H
#define REGISTERS_H

/* Register descriptions taken from Patterson and Hennessy's Computer
 * Organization and Design Appendix A. */

#define RG_ZERO   registers[0]    /* constant zero */

#define RG_AT     registers[1]    /* reserved for assembler */

#define RG_V0     registers[2]    /* expression evaluation & function results */
#define RG_V1     registers[3]

#define RG_A0     registers[4]    /* arguments */
#define RG_A1     registers[5]
#define RG_A2     registers[6]
#define RG_A3     registers[7]

#define RG_T0     registers[8]    /* temporary (not preserved across calls */
#define RG_T1     registers[9]
#define RG_T2    registers[10]
#define RG_T3    registers[11]
#define RG_T4    registers[12]
#define RG_T5    registers[13]
#define RG_T6    registers[14]
#define RG_T7    registers[15]

#define RG_S0    registers[16]    /* saved temporary (preserved across calls */
#define RG_S1    registers[17]
#define RG_S2    registers[18]
#define RG_S3    registers[19]
#define RG_S4    registers[20]
#define RG_S5    registers[21]
#define RG_S6    registers[22]
#define RG_S7    registers[23]

#define RG_T8    registers[24]    /* temporary (not preserved across calls */
#define RG_T9    registers[25]

#define RG_K0    registers[26]    /* reserved for OS kernel */
#define RG_K1    registers[27]

#define RG_GP    registers[28]    /* pointer to global area */
#define RG_SP    registers[29]    /* stack pointer */
#define RG_FP    registers[30]    /* frame pointer */
#define RG_RA    registers[31]    /* return address (used by function call) */

#endif
