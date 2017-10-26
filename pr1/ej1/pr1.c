#include <sys/types.h> 
#include <sys/wait.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h>
#include <string.h>

///*
//parte a

int main()
{
	printf("\n\n\n<<<<<<<<<<parte a>>>>>>>>>>\n\n\n");
	printf("introduce el numero de hijos\n");
	int a;
	scanf("%i",&a);
	pid_t pid;
	for (int i = 0; i < a; ++i)
	{
		pid=fork();
	}
	if (pid==0)
	{
		printf("Soy el hijo, mi PID es %d, mi padre: %d\n",getpid( ),getppid());
		return (0);
	}
	else if (pid!=0)
	{
		sleep(1);
		printf("Soy el padre, mi PID es %d\n", getpid());
		
	}

	return 0;
}
//*/
/*
//parte b
int main()
{
	printf("\n\n\n<<<<<<<<<<parte b>>>>>>>>>>\n\n\n");
	printf("introduce el numero de hijos\n");
	int a,status;
	scanf("%i",&a);
	pid_t pid=fork();

	if (pid==0)
	{
		
		while (a>0)
		{
			printf("Soy el hijo, mi PID es %d, mi padre: %d\n",getpid( ),getppid());
			a--;
			pid=fork();
			
			if(pid!=0)
			{
				printf("ahora Soy un padre, mi PID es %d\n", getpid());
				return 0;
			}
		}
		return (0);
	}
	else if (pid!=0)
	{
		//sleep(1);
		waitpid(pid,&status,0);
	}
	return 0;
}
*/