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
    return 0;
}

int my_openit(char *name, int prot){
    printf("my_openit");
    return 0;
}

void my_closeit(void){
    printf("my_closeit");
}