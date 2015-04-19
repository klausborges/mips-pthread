/*
 * Trabalho de SO I
 * Simulador de MIPS multithreaded
 * Klaus Borges (7986740)
*/


/* control_unit
 * Manages the signals that guide every other unit, and the state */
void *control_unit();

/* alu_unit
 * Executes arithmetical and logical operations */
void *alu_unit();

/* alu_control_unit
 * Determines what operation will be executed by the ALU at a given time */
void *alu_control_unit();




/* Multiplexer units have names related to the signal that multiplexes
 * their inputs */

/* mux_iord_unit
 * Multiplexes PC and ALUOut for the next memory address to be executed */
void *mux_iord_unit();

/* mux_regdst_unit
 * Multiplexes */
void *mux_regdst_unit();

/* mux_memtoreg_unit
 * Multiplexes */
void *mux_memtoreg_unit();

/* mux_alusrca_unit
 * Multiplexes */
void *mux_alusrca_unit();

/* mux_alusrcb_unit
 * Multiplexes */
void *mux_alusrcb_unit();

/* mux_pcsource_unit
 * Multiplexes */
void *mux_pcsource_unit();



/* sign_extender_unit
 * Extends Instruction[15:0] from 16 to 32 while keeping the sign */
void *sign_extender_unit();



/* Shifter units have names related to the unit they pass their output to */

/* shifter_pcsource_unit
 * Performs a bitwise shift of 2 on Instruction[25-0] and then concatenates
 * the result with PC[31:28] to determine the address to complete the jump
 * operation */
void *shifter_pcsource_unit();

/* shifter_alusrcb_unit
 * Performes a bitwise shift of 2 on the output of the sign extender */
void *shifter_alusrcb_unit();



/* pcwrite_condition_unit()
 * Enables writing PC if the following logical expression evaluates to true:
 * (PCWriteCond AND ??) || PCWrite) */
void *pcwrite_condition_unit();
