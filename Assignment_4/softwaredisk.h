//
// Software disk implementation for LSU 4103 filesystem assignment.
// (@nolaforensix), 11/2017.  Minor updates 11/2019.  Updated 6/2022.
// Modified by AAG, 11/2022

#if ! defined(SOFTWARE_DISK_BLOCK_SIZE)
#define SOFTWARE_DISK_BLOCK_SIZE 4096

// software disk error codes
typedef enum  {
  SD_NONE,
  SD_NOT_INIT,               // software disk not initialized
  SD_ILLEGAL_BLOCK_NUMBER,   // specified block number exceeds size of software disk
  SD_INTERNAL_ERROR          // the software disk has failed
} SDError;

// function prototypes for software disk API

// initializes the software disk to all zeros, destroying any existing
// data.  Returns 1 on success, otherwise 0. Always sets global 'sderror'.
int init_software_disk();

// returns the size of the SoftwareDisk in multiples of SOFTWARE_DISK_BLOCK_SIZE
unsigned long software_disk_size();

// writes a block of data from 'buf' at location 'blocknum'.  Blocks are numbered 
// from 0.  The buffer 'buf' must be of size SOFTWARE_DISK_BLOCK_SIZE.  Returns 1
// on success or 0 on failure.  Always sets global 'sderror'.
int write_sd_block(void *buf, unsigned long blocknum);

// reads a block of data into 'buf' from location 'blocknum'.  Blocks are numbered 
// from 0.  The buffer 'buf' must be of size SOFTWARE_DISK_BLOCK_SIZE.  Returns 1
// on success or 0 on failure.  Always sets global 'sderror'.
int read_sd_block(void *buf, unsigned long blocknum);

// describe current software disk error code by printing a descriptive message to
// standard error.
void sd_print_error(void);

// software disk  error code set (set by each software disk function).
extern SDError sderror;
#endif
