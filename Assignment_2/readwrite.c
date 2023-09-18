#include <stdio.h>
#include "fileio.h"

int main(int argc, char *argv[]) {
  File f;
  system("rm important.dat");
  printf("Creating new file called \"important.dat\"...\n");
  f=open_file("important.dat");
  fs_print_error();
  printf("Writing something benign to beginning of file...\n");
  write_file_at(f, "\x7F""EFL", 4, BEGINNING_OF_FILE, 0L);
  fs_print_error();
  printf("Writing something evil to beginning of file...\n");
  write_file_at(f, "\x7F""ELF", 4, BEGINNING_OF_FILE, 0L);
  fs_print_error();
  printf("Closing file...\n");
  close_file(f);
  fs_print_error();
  return 0;
}
  

  

