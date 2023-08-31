#include <stdio.h>

#define TOTAL_ELEMENTS ((sizeof(array) / sizeof(array[0])))
int array[] = {9, 2, 15, 20, 0, 43, 12};

int main(int argc, char *argv[]) {
  int i;  

  for (i=0;i <= TOTAL_ELEMENTS-1; i++) {
    printf("Element %d has value %d\n", i, array[i]);
  }
  
  return 0;
}