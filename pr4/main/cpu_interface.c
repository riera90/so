#include "cpu_interface.h"

struct Cpu* poweron(struct Cpu *cpu){
  //allocates all the memory
  cpu=(struct Cpu*)malloc(sizeof(struct Cpu));
  cpu->queue=(int*)malloc(sizeof(int)*MAX_PROCESS);
  cpu->active_process=(struct Process*)malloc(sizeof(struct Process)*MAX_PROCESS);
  cpu->pid_in_use=(bool*)malloc(sizeof(bool)*MAX_PROCESS);

  //prepare the necesary memory to the start configuration
  struct Process* temp;
  cpu->cicle=0;
  cpu->in_use=true;
  for (int i = 0; i < MAX_PROCESS; i++) {
    cpu->pid_in_use[i]=false;
    cpu->queue[i]=EMPTY;
    cpu->active_process=(struct Process*)malloc(sizeof(struct Process)*MAX_PROCESS);
      //allocates the process memory
  }

  return cpu;
}


void poweroff(struct Cpu *cpu){
  free(cpu->queue);
  free(cpu->pid_in_use);
  free(cpu->active_process);
  free(cpu);
}




bool create_process(struct Cpu* cpu, char* _name, int _length){
  struct Process* temp=(struct Process*)malloc(sizeof(struct Process));

  temp->pid=get_new_pid(cpu);
  temp->name=_name;
  temp->length=_length;
  temp->total_time=0;
  temp->arrival_time=cpu->cicle;
  temp->in_use=true;
  temp->cpu_time=0;
  return push_process(cpu,temp);
}


unsigned int get_new_pid(struct Cpu *cpu){
  for (int i = 0; i < MAX_PROCESS; i++) {
    if (cpu->pid_in_use[i]==false) {
      printf("--------test%i\n",i );
      cpu->pid_in_use[i]=true;
      return i;
    }
  }
  return -1;
}


bool push_process(struct Cpu *cpu, struct Process* process){
  if (process->pid==-1) {
    return false;
  }
  for (int i = 0; i < MAX_PROCESS; i++) {
    if (cpu->queue[i]==EMPTY) {
      cpu->queue[i]=process->pid;
      cpu->active_process[i]=*process;
      return true;
    }
  }
  return false;
}


struct Process* get_next_process(struct Cpu *cpu){
  return &cpu->active_process[0];
}


struct Process* pop_process(struct Cpu *cpu){
  // cant decoment becouse the process needs to be unique to the process manager recolector, if the recolector un unabled, feel free to decoment this, as it will make the program more efficient
  //this make the program only able to get as many programs as MAX_PROCESS even if they finish
  //cpu->pid_in_use[cpu->active_process[0].pid]=false;
  struct Process* temp=(struct Process*)malloc(sizeof(struct Process));
  *temp=cpu->active_process[0];
  for (int i = 0; i < MAX_PROCESS-1; i++) {
    cpu->active_process[i]=cpu->active_process[i+1];
  }
  return temp;
}


bool roll_queue(struct Cpu* cpu){
  struct Process temp;
  temp=cpu->active_process[0];
  for (int i = 0; i < MAX_PROCESS-1; i++) {
    cpu->active_process[i]=cpu->active_process[i+1];
  }
  cpu->active_process[MAX_PROCESS-1]=temp;
}
