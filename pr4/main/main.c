#include "cpu_interface.h"
#include "process_manager.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

  struct Cpu *cpu;

  struct Process* process=(struct Process*)malloc(sizeof(struct Process));

  // struct Cpu *cpu1;
  // cpu1=poweron(cpu1);
  // FCFS(cpu1);
  // poweroff(cpu1);

  struct Cpu *cpu2;
  cpu2=poweron(cpu2);
  SJF(cpu2);
  poweroff(cpu2);

  struct Cpu *cpu3;
  cpu3=poweron(cpu3);
  Round_Robin(cpu3) ;
  poweroff(cpu3);

  return 0;
}
