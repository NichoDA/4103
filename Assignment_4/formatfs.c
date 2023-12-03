// Nicholas Domingue and Bryce Olivier
#include <stdio.h>
#include <stdlib.h>
#include "softwaredisk.h"
#include "filesystem.h"

// this code needs to run before running 'testfs0.c'
static Bitmap data_bitmap;
static Bitmap inode_bitmap;

// initialize filesystem
int main(int argc, char *argv[]) {
    format_filesystem();
    sd_print_error();
}

// initialize bitmap
static void init_bitmap(Bitmap *bitmap, unsigned long size_in_blocks) {
    bitmap->size_in_blocks = size_in_blocks;
    bitmap->bits = calloc(size_in_blocks, sizeof(unsigned char));
    if (bitmap->bits == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory for the bitmap.\n");
        exit(EXIT_FAILURE);
    }
}

// free bitmap
static void free_bitmap(Bitmap *bitmap) {
    free(bitmap->bits);
}

void format_filesystem(){
    printf("Intitializing Software Disk...\n");
    init_software_disk();

    // initialize bitmap
    init_bitmap(&data_bitmap, NUM_BLOCKS);
    init_bitmap(&inode_bitmap, NUM_BLOCKS / INODES_PER_BLOCK);

    // free bitmap
    free_bitmap(&data_bitmap);
    free_bitmap(&inode_bitmap);
}
