//task 3
//fix blarg, put in file called blarg1.c
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
// //task 4
// //blarg little endian and big endian
// //put in file named blarg2.c
// #include <stdio.h>

// #define TOTAL_ELEMENTS ((sizeof(array) / sizeof(array[0])))
// int array[] = {9, 2, 15, 20, 0, 43, 12};

// int main(int argc, char *argv[]) {
//   int i;  

//   for (i=0;i <= TOTAL_ELEMENTS-1; i++) {
//     printf("Element %d has value %d\n", i, array[i]);
//   }
  
//   return 0;
// }
//task 5
//
char x='X', s=' ';int main(){int i,j;for(j=0;j<5;j++){if(j%2==0){putchar(s);}for(i=0;i<5;i++){putchar(s),putchar(x);}printf("\n");}return 0;}
