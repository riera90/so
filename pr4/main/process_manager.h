#ifndef _PROCESS_MANAGER_H_
#define _PROCESS_MANAGER_H_

#include <stdlib.h>
#include <stdio.h>
#include "cpu_interface.h"

#define MAX_LENGHT 99
#define TOP_CICLE 30
#define CUANTO 3

struct Finish{
  struct Process process;
  int finish_time;
  bool in_use;
};

void FCFS(struct Cpu* cpu);
void SJF(struct Cpu* cpu);
void Round_Robin(struct Cpu* cpu);

#endif
