#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
	int pid,starus;
	pid=fork();

	if (pid==0)//son 1
	{
		//substitute "ls" for "calculator" (gnome calculator)
		//execl("/bin/ls","ls","-l",NULL);
		exit(0);
	}

	pid=fork();

	if (pid==0) //son 2
	{
		char* const *arch[]={"ls","-l"};
		//dociment1_path and document2_path can be substituted by argv[] or the folowing line of code
		execv("/bin/ls",arch);
		//execl("/bin/gedit","gedit","document1_path","document2_path",NULL);
		exit(0);
	}

	if (pid!=0)//father
	{
		sleep(0.5);
	}

	pid=fork();
	return 0;
}