// Nicholas Domingue and Bryce Olivier
#include <stdio.h>
int my_openit(char* name, int prot);
void my_closeit(void);

typedef struct funcs{
    int (*openit)(char *name, int prot);
    void (*closeit)(void);
} funcs;

int main(){
    funcs x = {&my_openit, &my_closeit};

    // the commented out code bellow is just to test the program
    // x.openit("file.txt", 0);
    // x.closeit();

    return 0;
}

int my_openit(char *name, int prot){
    printf("my_openit\n");
}

void my_closeit(void){
    printf("my_closeit\n");
}
