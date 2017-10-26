#include <sys/types.h> 
#include <sys/wait.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h>
#include <string.h>



int main(int argc, char const *argv[])
{
	pid_t pid=fork();
	if (pid==0)
	{
		//return (0);
	}
	else if (pid!=0)
	{
		sleep(10);		
	}
	return 0;
}	