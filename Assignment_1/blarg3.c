// Nicholas Domingue and Bryce Olivier
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  unsigned long *p = malloc(sizeof(unsigned long));
  *p = 0xdeadbeefcafebc00;
  unsigned char *c=(unsigned char *)p;
  int i;

  // little endian
  for (i=0; i < sizeof(unsigned long); i++) {
    printf("%02x ", *c);
    c++;
  }
  printf("\n");

  // big endian
  c = (unsigned char *)p;
  for (i=sizeof(unsigned long) - 1; i >= 0; i--) {
    printf("%02x ", *(c + i));
  }
  printf("\n");

  return 0;
}