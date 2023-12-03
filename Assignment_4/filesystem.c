// Nicholas Domingue and Bryce Olivier
#include <stdio.h>
#include <stdlib.h>
#include "softwaredisk.h"
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

// fs error code set
FSError fserror;


// open existing file with pathname 'name' and access mode 'mode'.
// Current file position is set to byte 0.  Returns NULL on
// error. Always sets 'fserror' global.
File open_file(char *name, FileMode mode) {
    if(file_exists() == 1) {
        int current_file_position = 0;
        fserror=FS_NONE;
    } else {
        fserror=FS_FILE_NOT_FOUND;
        return NULL;
    }
}

// create and open new file with pathname 'name' and (implied) access
// mode READ_WRITE.  Current file position is set to byte 0.  Returns
// NULL on error. Always sets 'fserror' global.
File create_file(char *name) {
    if(file_exists() == 0){
        int current_file_position = 0;
        fserror=FS_NONE;
    } else {
        fserror=FS_FILE_ALREADY_EXISTS;
        return NULL;
    }
}

// close 'file'.  Always sets 'fserror' global.
void close_file(File file) {
    if(file is open) {
        fserror=FS_NONE;
        //close the file
    } else {
        fserror=FS_FILE_NOT_OPEN;
    }
}

// read at most 'numbytes' of data from 'file' into 'buf', starting at the 
// current file position.  Returns the number of bytes read. If end of file is reached,
// then a return value less than 'numbytes' signals this condition. Always sets
// 'fserror' global.
unsigned long read_file(File file, void *buf, unsigned long numbytes) {
    return read_sd_block(*buf, numbytes);
}

// write 'numbytes' of data from 'buf' into 'file' at the current file
// position.  Returns the number of bytes written. On an out of space
// error, the return value may be less than 'numbytes'.  Always sets
// 'fserror' global.
unsigned long write_file(File file, void *buf, unsigned long numbytes) {
    if() {
        
        return 0;
    }
    return write_sd_block(*buf, numbytes);
}

// sets current position in file to 'bytepos', always relative to the
// beginning of file.  Seeks past the current end of file should
// extend the file. Returns 1 on success and 0 on failure.  Always
// sets 'fserror' global.
int seek_file(File file, unsigned long bytepos) {
    printf("here");
}

// returns the current length of the file in bytes. Always sets
// 'fserror' global.
unsigned long file_length(File file) {
    printf("here");
}

// deletes the file named 'name', if it exists. Returns 1 on success,
// 0 on failure.  Always sets 'fserror' global.
int delete_file(char *name) {
    if(file_exists(*name) == 1) {
        // delete file *name
        fserror=FS_NONE;
        return 1;
    } else {
        fserror=FS_FILE_NOT_FOUND;
        return 0;
    }
}

// determines if a file with 'name' exists and returns 1 if it exists, otherwise 0.
// Always sets 'fserror' global.
int file_exists(char *name) {
    fserror=FS_NONE;
    if(*file_name == *name) {
        return 1;
    } else {
        return 0;
    }
}

// describe current filesystem error code by printing a descriptive
// message to standard error.
void fs_print_error(void) {
    switch (fserror) {
        case FS_NONE:
            printf("FS: No error.\n");
            break;
        case FS_OUT_OF_SPACE:
            printf("FS: Software disk is full.\n");
            break;
        case FS_FILE_NOT_OPEN:
            printf("FS: File not open.\n");
            break;
        case FS_FILE_OPEN:
            printf("FS: File already open.\n");
            break;
        case FS_FILE_NOT_FOUND:
            printf("FS: File does not exist.\n");
            break;
        case FS_FILE_READ_ONLY:
            printf("FS: File is read only.\n");
            break;
        case FS_FILE_ALREADY_EXISTS:
            printf("FS: File already exists.\n");
            break;
        case FS_EXCEEDS_MAX_FILE_SIZE:
            printf("FS: File exceeds max file size.\n");
            break;
        case FS_ILLEGAL_FILENAME:
            printf("FS: Illegal file name.\n");
            break;
        case FS_IO_ERROR:
            printf("FS: Something really bad happened.\n");
            break;
        default:
            printf("FS: Unknown error code %d.\n", fserror);
    }
}

// extra function to make sure structure alignment, data structure
// sizes, etc. on target platform are correct.  Should return 1 on
// success, 0 on failure.  This should be used in disk initialization
// to ensure that everything will work correctly.
int check_structure_alignment(void) {
    printf("here");
}