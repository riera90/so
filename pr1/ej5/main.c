#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
	pid_t pid;
	int status;
	FILE * f;
	f=fopen (argv[1],"w+");
	fflush(f);

	pid=fork();

	if(pid==0)//father
	{
		sleep(0.1);
		fprintf(f,"1 and i'm his son\n");
		printf("1s\n");
		//fflush(f);
		exit(0);
	
	}
	else if (pid!=0)
	{
		fprintf(f,"1 hi, i'm the perent\n");// no se por que lo escribe en el fichero dos veces pero solo hace el printf 1
		printf("1p\n");
		wait(&status);

		sleep(1);

		pid=fork();

		if (pid==0)//son 2
		{
			sleep(0.1);
			fprintf(f,"2 and i'm his second son\n");
			printf("2s\n");
			exit (0);
		}
		
		fprintf(f,"2 hi, i'm the perent again\n");
		printf("2p\n");
		wait(&status);
		//waitpid(pid,&status,0);
		sleep(0.5);
		//fflush(f);
		fclose(f);

		return 0;
	}
}