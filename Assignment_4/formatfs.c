// Nicholas Domingue and Bryce Olivier
#include <stdio.h>
#include <stdlib.h>
#include "softwaredisk.h"

// this code needs to run before running 'testfs0.c'

// initialize filesystem
int main(int argc, char *argv[]) {
    printf("Intitializing Software Disk...\n");
    init_software_disk();
    printf("Software disk size: " + software_disk_size() + "\n");
    printf("\n");
    sd_print_error();
}
