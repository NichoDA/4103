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


// main loop for queues
int main(int argc, char *argv[]) {
    Queue q1, q2, q3, q4;
    int clock = 0;
    int element;

    // ask user for queue entries
    printf("Queue entries one per line:\n");
    // read input and add to processes array
    while (num_of_processes <= 10){ // need to come back and make while loop dynamic
        scanf("%d %d %d %d %d", &processes[num_of_processes].times, &processes[num_of_processes].pid, 
                &processes[num_of_processes].run, &processes[num_of_processes].io, &processes[num_of_processes].repeat);
        num_of_processes++;
    }
    // calculate length of processes
    int length = 100 + (num_of_processes - (sizeof(processes) / sizeof(processes[0])));


    // initializing queue
    init_queue(&q1, sizeof(processes), TRUE, process_compare, FALSE);

    // run while there's another (RUN, I/O, Repeat) phase for process PID
    while( /* there's another (RUN, I/O, REPEAT) phase for process PID */){

        for (int i = 0; i < length; i++){
            // check if process should enter queue
            if(processes[i].time == clock) {
                //add process to queue
                add_to_queue(&q1, &processes[i].pid, current_priority(&q1)); // unsure if this is how to get priority
            }
            
            // execute highest-priority process
            element = 0;
            rewind_queue(&q1);
            if(peek_at_current(&q1) == process[i]){
                printf("PID: %d, ARRIVAL TIME: %d", processes[i].pid, processes[i].time);
                printf("CREATE: Process %d entered the ready queue at time %d", processToEnqueue.pid, processToEnqueue.time);
                
            }
            // make exit, I/O, demotion or promotion decisions
            // ...
         }   

        clock++;
    }
    printf("Scheduler shutdown at time %d.\n", clock);
    printf("Total CPU usage for all processes scheduled: \n");
    /*print each pid with the the final clock time and total CPU usage of 
    all processes (including the <<null>> process) scheduled when it exits.*/   
}

// comparison function for queue of process elements
int process_compare(const void *e1, const void *e2) {
  Process *p1=(Process *)e1;
  Process *p2=(Process *)e2;
  // need to compare CPU instead of arrival time
  if (p1->pid == p2->pid && !p1->time == p2->time) { // change this
    return 1;
  }
  else {
    return 0;
  }
}







// function for enqueueing process
void enqueueProcess(Process processToEnqueue){

  if(processToEnqueue.time == clock){
    add_to_queue(q1, processToEnqueue, /*priority*/);
  }
}

// function to handle scheduling
void handleScheduling(){

}

// function to handle changing states between I/O, demotion, and promotion rules
void handleStateChange(){
    
}

