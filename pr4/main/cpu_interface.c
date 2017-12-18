#include "cpu_interface.h"

struct Cpu* poweron(struct Cpu *cpu){
  //allocates all the memory
  cpu=(struct Cpu*)malloc(sizeof(struct Cpu));
  cpu->queue=(int*)malloc(sizeof(int)*MAX_PROCESS);
  cpu->active_process=(struct Process*)malloc(sizeof(struct Process)*MAX_PROCESS);
  cpu->active_process_in_use=(bool*)malloc(sizeof(bool)*MAX_PROCESS);

  //prepare the necesary memory to the start configuration
  struct Process* temp;
  cpu->cicle=0;
  cpu->in_use=false;
  for (int i = 0; i < MAX_PROCESS; i++) {
    cpu->active_process_in_use[i]=false;
    cpu->queue[i]=EMPTY;
    cpu->active_process=(struct Process*)malloc(sizeof(struct Process)*MAX_PROCESS);
      //allocates the process memory
  }

  return cpu;
}


void poweroff(struct Cpu *cpu){
  free(cpu->queue);
  free(cpu->active_process_in_use);
  free(cpu->active_process);
  free(cpu);
}




bool create_process(struct Cpu* cpu,const char* _name, int _length, int _total_time, int _arrival_time){
  struct Process* temp=(struct Process*)malloc(sizeof(struct Process));

  if (temp->pid=get_new_pid(cpu)==-1) {
    return false;
  };
  temp->name=_name;
  temp->length=_length;
  temp->total_time=_total_time;
  temp->arrival_time=_arrival_time;
  return push_process(cpu,temp);
}


unsigned int get_new_pid(struct Cpu *cpu){
  for (int i = 0; i < MAX_PROCESS; i++) {
    if (cpu->active_process_in_use[i]==false) {
      cpu->active_process_in_use[i]=true;
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
  for (int i = 0; i < MAX_PROCESS; i++) {
    if (cpu->queue[0]==cpu->active_process[i].pid) {
      return &cpu->active_process[i];
    }
  }
  return NULL;
}


struct Process* pop_process(struct Cpu *cpu){
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
