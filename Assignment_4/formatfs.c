// Nicholas Domingue and Bryce Olivier
#include <stdio.h>
#include <stdlib.h>
#include "filesystem.h"

struct superblock sb;

// initialize filesystem
void init_filesystem() {
    sb.num_inodes = 10;

    int i;
    inodes = malloc(sizeof (struct inode) * sb.num_inodes);
    for(i = 0; i < sb.num_inodes; i++){
        inodes[i].size = -1;
        inodes[i].name = "";
    }
}