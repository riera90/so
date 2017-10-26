#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>

void espera(int time, char *name)
{
	int suma, childpid, status;
	sleep(time);
	suma+=getpid()%10;
	while(childpid=wait(&status)>0)
	{
		if(WIFEXITED(status)>0)
		{
			suma+=WEXITSTATUS(status);
		}
	}
	printf("soy: %s, mi pid: %d, y mi suma es %d\n", name,getpid(),suma);
	exit(suma);
}

int main(void)
{
	int pid;
	int status;
	int suma;

	pid=fork();
	if (pid==0)//hijo 1
	{
		espera(0,(char*)"hijo 1");
	}
	pid=fork();
	if (pid==0)//hijo 2
	{
		pid=fork();
		if (pid==0) //nieto 1
		{
			espera(0,(char*)"nieto 1");
		}
		pid=fork();
		if (pid==0) //nieto 2
		{
			espera(0.1,(char*)"nieto 2");
		}
		espera(0.2,(char*)"hijo 2");
	}
	espera(0.3,(char*)"padre");
}
	
