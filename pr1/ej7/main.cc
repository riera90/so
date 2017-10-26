#include <sys/shm.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <iostream>

#define key (key_t) 234

int main(int argc, char const *argv[])
{
	int id_mem;
	int *mem=NULL;
	key_t pid;
	int *status;

	id_mem=shmget (key, sizeof (int),0777 | IPC_CREAT);
	if (id_mem == -1)
	{
		printf("No consigo Id para Memoria compartida\n");
		exit(0);
	}

	mem = (int*)shmat (id_mem, (char*) 0,0);
	if (mem == NULL)
	{
		printf("No consigo Memoria compartida");
		exit(0);
	}
	mem[0]=0;

	pid=fork();
	pid=fork();
	pid=fork();
	pid=fork();
	pid=fork();
	pid=fork();
	switch (pid)
	{
		case 0:
			for(int j = 0; j < 100; ++j) mem[0]++;
			return (0);

		default:
			wait(status);
			wait(status);
			wait(status);
			wait(status);
			wait(status);
			wait(status);

			break;
	}

	printf("%i \n",*mem);
	shmdt ((char *)mem);
	shmctl (id_mem, IPC_RMID, (struct shmid_ds *)NULL);
	return 0;
}