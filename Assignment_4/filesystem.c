// Nicholas Domingue and Bryce Olivier
#include <stdio.h>
#include <stdlib.h>
#include "filesystem.h"

typedef struct superblock {
    int num_inodes;
} superblock;

typedef struct inode {
    int size;
    char name[8];
} inode;

void print_fs(){
    printf("Superblock info:\n");
    printf("\tnum inodes%d\n", s.num_inodes);
    printf("inodes:\n");
    int i;
    for (i = 0; i < sb.num_inodes; i++) {
        printf("\tsize: %d name: %s", inodes[i].size, indoes[i].name);
    }
}