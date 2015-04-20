/*
 * Trabalho de SO I
 * Simulador de MIPS multithreaded
 * Klaus Borges (7986740)
 */

#include <stdio.h>
#include <unistd.h>
#include "../include/units.h"
#include "../include/cpu.h"

void debug(char* unit_name, char *msg) {
  printf("[\e[33munit\e[0m] [\e[32m%11s\e[0m] %s\n", unit_name, msg);
}

void *control_unit() {
  debug("Control", "Waiting for CPU to load all threads");

  pthread_mutex_lock(&m_cond);
  while (cpu_loading_threads) {
    pthread_cond_wait(&c_wait_for_broadcast, &m_cond);
  }
  pthread_mutex_unlock(&m_cond);

  debug("Control", "Running");

  debug("Control", "Waiting for other units at barrier");
  int bar = pthread_barrier_wait(&b_wait_for_units);
  if (bar) {
    fprintf(stderr, "ERROR - Could not wait on barrier\n");
  }

  debug("Control", "Exiting");

  pthread_exit(0);
}

void *alu_unit() {
  debug("ALU", "Waiting for CPU to load all threads");

  pthread_mutex_lock(&m_cond);
  while (cpu_loading_threads) {
    pthread_cond_wait(&c_wait_for_broadcast, &m_cond);
  }
  pthread_mutex_unlock(&m_cond);

  debug("ALU", "Running");

  debug("ALU", "Waiting for other units at barrier");
  int bar = pthread_barrier_wait(&b_wait_for_units);
  if (bar) {
    fprintf(stderr, "ERROR - Could not wait on barrier\n");
  }

  debug("ALU", "Exiting");
  pthread_exit(0);
}

void *alu_control_unit() {
  debug("ALU Control", "Waiting for CPU to load all threads");

  pthread_mutex_lock(&m_cond);
  while (cpu_loading_threads) {
    pthread_cond_wait(&c_wait_for_broadcast, &m_cond);
  }
  pthread_mutex_unlock(&m_cond);

  debug("ALU Control", "Running");

  debug("ALU Control", "Waiting for other units at barrier");
  int bar = pthread_barrier_wait(&b_wait_for_units);
  if (bar) {
    fprintf(stderr, "ERROR - Could not wait on barrier\n");
  }

  debug("ALU Control", "Exiting");

  pthread_exit(0);
}
