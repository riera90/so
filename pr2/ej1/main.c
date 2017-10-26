#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


void* msg(int a)
{
	//printf("%s\n",text);
	printf("test: %i\n",a );
	usleep (1000000);
	exit (0);
}

int main(int argc, char const *argv[])
{
	printf("testerino\n");
	
	int a;

	pthread_t tid[3];

	pthread_create(&tid[0],NULL,(void*)msg,&a);
	pthread_join(tid[0],NULL);


	return 0;
}
