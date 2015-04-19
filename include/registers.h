/*
    Trabalho de SO
    Simulador MIPS multithread
*/

#ifndef REGISTERS_H
#define REGISTERS_H

/* register_t stores the value of the register and its name (e.g. $t0, $t1) */
struct register_t {
  char name[4];
  int value;
};


/* Returns the number of the register given its name */
int register_number(char *);

#endif
