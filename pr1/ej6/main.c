#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <iostream>

int val=0;
int a;

int main(int argc, char const *argv[])
{
	pid_t pid;
	int status;

	printf("introduce el numero de hijos\n");
	scanf("%i",a);
	pid=fork();
	while(val<a)
	{
		if (pid==0) //son
		{
			val++;
			pid=fork();
			if (pid!=0) return 0;
			if (a==val) return 0;
		}
		else if (pid!=0) //father
		{
			wait(&status);
			printf("val: \n",&val);
			break;
		}
	}
		return 0;
}