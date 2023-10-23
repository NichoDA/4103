// Nicholas Domingue and Bryce Olivier
// MLFQ programming assignment 3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prioque.h"

// holds information for each process
typedef struct {
  int time, pid, run, io, repeat;
} Process;

// create array to hold processes
Process processes[100]; // max of 100 processes
int num_of_processes = 0;


// comparison function for queue of process elements
int process_compare(const void *e1, const void *e2) {
  Process *p1=(Process *)e1;
  Process *p2=(Process *)e2;
  // need to compare CPU instead of arrival time
  if (p1->pid == p2->pid && p1->time == p2->time) { /*change this*/
    return 1;
  }
  else {
    return 0;
  }
}

// main loop for queues
int main(int argc, char *argv[]) {
    Queue q1, q2, q3, q4;
    int lvl1 = 10, lvl2 = 30, lvl3 = 100, lvl4 = 200;
    int clock = 0;
    int element, finished = 0;
    int totalProcesses = 6;
    

    // ask user for queue entries
    printf("Queue entries one per line:\n");
    // read input and add to processes array
    while (num_of_processes <= 10){ /* need to come back and make while loop dynamic */
        scanf("%d %d %d %d %d", &processes[num_of_processes].time, &processes[num_of_processes].pid, 
                &processes[num_of_processes].run, &processes[num_of_processes].io, &processes[num_of_processes].repeat);
        num_of_processes++;
    }


    for (int i = 0; i < num_of_processes; i++){
        int j = 0;
        for (j = 0; j < num_of_processes; j++){
            if(processes[i].pid == processes[j].pid){
                break;
            }
        }
        if (i == j) {
            totalProcesses++;
        }
    }


    // initializing queue
    init_queue(&q1, sizeof(processes), TRUE, process_compare, FALSE);

    // run while there is at least one undetermined process
    while(finished != totalProcesses){ 

        for (int i = 0; i < num_of_processes; i++){
            // check if process should enter queue at current clock value
            if(processes[i].time >= clock) {
                //add process to queue
                printf("PID: %d, ARRIVAL TIME: %d\n", processes[i].pid, processes[i].time);
                //add_to_queue(&q1, &processes[i].pid, current_priority(&q1)); /*unsure if this is how to get priority*/
                printf("CREATE: Process %d entered the ready queue at time %d\n", processes[i].pid, processes[i].time);
            }
            
            // execute highest-priority process
            element = 0;
            rewind_queue(&q1);
            if (processes[i].time <= clock) { ////////
                // make exit, I/O, demotion or promotion decisions
                while(processes[i].repeat >= 0){ /* peek_at_current(&q1, 4) */
                    if (processes[i].repeat > 0) {
                        // do RUN for processes[i].time units
                        
                        printf("RUN: Process %d started execution from level %d at time %d; wants to execute for %d ticks.\n", 
                                processes[i].pid, 1, clock, processes[i].run);
                        // do I/O for processes[i].io time units
                        printf("I/O: Process %d blocked for I/O at time %d.\n", processes[i].pid, clock);
                        clock += processes[i].io;
                        processes[i].repeat--;
                    }
                    else if(processes[i].repeat == 0){
                        // do RUN for processes[i].time units
                        printf("RUN: Process %d started execution from level %d at time %d; wants to execute for %d ticks.\n", 
                                processes[i].pid, 1, clock, processes[i].run);
                        clock += processes[i].run;
                        // do FINISH after RUN time
                        printf("FINISHED: Process %d finished at time %d.\n", processes[i].pid, clock);
                        remove_from_front(&q1, &processes[i]);
                        finished++;
                        int timeUnits = (processes[i].repeat + 1) * processes[i].run;
                        processes[i].repeat--;
                    }
                }
            }
         }   

        clock++;
    }
    printf("Scheduler shutdown at time %d.\n", clock);
    printf("Total CPU usage for all processes scheduled: \n");
    /*print each pid with the the final clock time and total CPU usage of 
    all processes (including the <<null>> process) scheduled when it exits.*/   
}

