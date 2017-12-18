#include "process_manager.h"

#define TOP_CICLE 50

void FCFS(struct Cpu* cpu){
  int pid_aux;
  int* finished_pid_asociation=(int*)malloc(sizeof(int)*MAX_PROCESS);
  struct Finish* finished=(struct Process*)malloc(sizeof(struct Process)*MAX_PROCESS);
  for (int i = 0; i < MAX_PROCESS; i++) {
    finished->in_use=false;
    finished_pid_asociation[i]=-1;
  }

  struct Process* aux=(struct Process*)malloc(sizeof(struct Process));
  aux=&cpu->active_process[0];

  while(cpu->in_use){

    if(cpu->cicle==0)create_process(cpu,"A",8);
    if(cpu->cicle==1)create_process(cpu,"B",4);
    if(cpu->cicle==2)create_process(cpu,"C",9);
    if(cpu->cicle==3)create_process(cpu,"D",5);
    if(cpu->cicle==4)create_process(cpu,"E",2);



    if (aux->length>0) {
      aux->length--;
      aux->cpu_time++;

      for (int i = 0; i < MAX_PROCESS; i++) {
        cpu->active_process[i].total_time++;
      }

      printf("clock: %i\n",cpu->cicle );
      printf("name: %s\t",aux->name );
      printf("pid: %i\t",aux->pid );
      printf("remeaning: %i\n",aux->length );

      if (aux->length==0) {
        printf("finished!!\n");
        pid_aux=aux->pid;
        finished[pid_aux].in_use=true;
        finished[pid_aux].finish_time=cpu->cicle+1;
        finished[pid_aux].process=*pop_process(cpu);

      }
      printf("*********************************\n");
    }else{
      printf("waiting!\n");
      roll_queue(cpu);
    }




    cpu->cicle++;
    if(cpu->cicle==TOP_CICLE) cpu->in_use=false;
  }

  int waiting_time;
  int start_time;

  for (int i = 0; i < MAX_PROCESS; i++) {
    if (finished[i].in_use==true) {

      waiting_time=finished[i].process.total_time - finished[i].process.cpu_time;
      if (waiting_time<0)waiting_time=0;

      start_time=finished[i].finish_time - finished[i].process.cpu_time;

      printf("name: %s\t",finished[i].process.name );
      printf("pid: %i\t", finished[i].process.pid );
      printf("arrival: %i\t", finished[i].process.arrival_time );
      printf("start_time: %i\t", start_time );
      printf("finish_time: %i\t", finished[i].finish_time );
      printf("cpu_time: %i\t",finished[i].process.cpu_time );
      printf("return_time: %i\t",finished[i].process.total_time );
      printf("waiting_time: %i\n", waiting_time );
    }
  }
}

void SJF(struct Cpu* cpu){

}

void Round_Robin(struct Cpu* cpu){

}
