#ifndef _CPU_INTERFACE_H_
#define _CPU_INTERFACE_H_

#include <stdlib.h>
#include <stdio.h>

#define bool int
#define true 1
#define false 0

#define MAX_PROCESS 10
#define EMPTY -1


struct Cpu{
  int cicle;
  int* queue;
  struct Process *active_process;
  bool* pid_in_use;
  bool in_use;
};

struct Process{
  unsigned int pid;
  char* name;
  int length;
  unsigned int total_time;
  unsigned int arrival_time;
  int cpu_time;
  bool in_use;
};

struct Cpu* poweron(struct Cpu *cpu);
  //set the necesary variables for the cpu to work
void poweroff(struct Cpu *cpu);
  //free the memory

bool create_process(struct Cpu* cpu, char* _name, int _length);
unsigned int get_new_pid(struct Cpu *cpu);
  //gets a free pid


bool push_process(struct Cpu *cpu, struct Process* process);
  //push the process on the first available position
struct Process* get_next_process(struct Cpu *cpu);
  //returns the process on the first position
struct Process* pop_process(struct Cpu *cpu);
  //pops the process on the first position
bool roll_queue(struct Cpu* cpu);

#endif
