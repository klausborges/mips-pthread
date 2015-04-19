#include <stdio.h>

int main(int argc, char **argv) {
  printf("Code is running fine.\n");

  int i = 10;
  unsigned int ui = 10;
  long l = 10;
  unsigned long ul = 10;
  printf("int\t%u\t\t\t%lu\n", i, sizeof(i));
  printf("unsigned int\t\t%d\t%lu\n", ui, sizeof(ui));
  printf("long\t\t%ld\t%lu\n", l, sizeof(l));
  printf("unsigned long\t%lu\t%lu\n", ul, sizeof(ul));

  return 0;
}
