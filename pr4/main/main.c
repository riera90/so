#include "cpu_interface.h"
#include "process_manager.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

  struct Cpu *cpu;

  struct Process* process=(struct Process*)malloc(sizeof(struct Process));

  printf("\n");

  cpu=poweron(cpu);

  if (create_process(cpu,argv[1],5,5,5)) {
    printf("ok\n");
  }
  if (create_process(cpu,argv[1],6,6,6)) {
    printf("ok\n");
  }

  process=get_next_process(cpu);
  printf("%i\n", process->length);

  printf("---------\n");

  roll_queue(cpu);
  //pop_process(cpu);

  process=get_next_process(cpu);
  printf("%i\n", process->length );

  printf("\n");

  poweroff(cpu);


  return 0;
}
