#include "cpu_interface.h"
#include "process_manager.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

  // struct Cpu *cpu;
  //
  // struct Process* process=(struct Process*)malloc(sizeof(struct Process));
  //
  // printf("\n");
  //
  // cpu=poweron(cpu);
  //
  // if (create_process(cpu,"pr1",5)) {
  //   printf("ok\n");
  // }
  // if (create_process(cpu,"pr2",6)) {
  //   printf("ok\n");
  // }
  //
  //
  // printf("%i\n", process->pid);
  //
  // printf("---------\n");
  // cpu->active_process[0]=cpu->active_process[1];
  // //roll_queue(cpu);
  // //pop_process(cpu);
  //
  // process=&cpu->active_process[0];
  // printf("%i\n", process->pid );
  //
  // printf("\n");
  //
  // poweroff(cpu);
  //
  // printf("---------\n");
  //
  //
  // struct Cpu *cpu2;
  // cpu2=poweron(cpu2);
  //
  // FCFS(cpu2);
  //
  // poweroff(cpu2);
  //
  //
  //
  // struct Cpu *cpu3;
  // cpu3=poweron(cpu3);
  //
  // SJF(cpu3);
  //
  // poweroff(cpu3);


  struct Cpu *cpu4;
  cpu4=poweron(cpu4);

  Round_Robin(cpu4);

  poweroff(cpu4);

  return 0;
}
