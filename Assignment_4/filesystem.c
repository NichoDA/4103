// Nicholas Domingue and Bryce Olivier
#include <stdio.h>
#include <stdlib.h>
#include "filesystem.h"

#define MAX_FILES                     512
#define DATA_BITMAP_BLOCK               0
#define INODE_BITMAP_BLOCK              1
#define FIRST_INODE_BLOCK               2
#define LAST_INODE_BLOCK                5

#define INODES_PER_BLOCK              128
#define FIRST_DIR_ENTRY_BLOCK           6
#define LAST_DIR_ENTRY_BLOCK           69
#define DIR_ENTRIES_PER_BLOCK           8

#define FIRST_DATA_BLOCK               70
#define LAST_DATA_BLOCK              4095
#define MAX_FILENAME_SIZE             507
#define NUM_DIRECT_INODE_BLOCKS        13
#define NUM_SINGLE_INDIRECT_BLOCKS      (SOFTWARE_DISK_BLOCK_SIZE / sizeof(unit16_t))

#define MAX_FILE_SIZE                   (NUM_DIRECT_INODE_BLOCKS + NUM_SINGLE_INDIRECT_BLOCKS) * SOFTWARE_DISK_BLOCK_SIZE