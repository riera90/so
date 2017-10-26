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
	int m_s;
	int q=0;

	id_mem=shmget (key, sizeof (int)*2,0777 | IPC_CREAT);
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
	for (int i = 0; i < 2; ++i) mem[i]=0;

	pid_t p1=getpid();
	int x =0;
	pid=fork();
	if (pid==0)
	{
		m_s=x;
		x++;
	}
	pid=fork();
	if (pid==0)
	{
		m_s=x;
		x++;
	}
	pid=fork();
	if (pid==0)
	{
		m_s=x;
		x++;
	}
	pid=fork();
	if (pid==0)
	{
		m_s=x;
		x++;
	}
	pid=fork();
	if (pid==0)
	{
		m_s=x;
		x++;
	}
	pid=fork();
	if (pid==0)
	{
		m_s=x;
		x++;
	}
	if (pid==0)
	{
		printf("%i\n", m_s);
	}
	while(1)
	{

		switch (pid)
		{
			case 0:
				if (mem[1]==m_s) 
				{
					for(int j = 0; j < 100; ++j) mem[0]++;
					return (0);
				}

			default:
				sleep(1);

				if (p1==getpid())
				{
					printf("mem[1]%i\n",mem[1]);
					printf("mem[0]%i \n\n",mem[0]);
					mem[1]++;
				}

				if (mem[1]==6) q=-1;
		}
		if (q==-1) break;
	}

	
	shmdt ((char *)mem);
	shmctl (id_mem, IPC_RMID, (struct shmid_ds *)NULL);
	return 0;
}