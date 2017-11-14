#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


void* msg(char* a)
{
	//printf("%s\n",text);
	for (int i = 0; i < strlen(a); ++i)
	{
		printf("%c\n",a[i] );
		usleep(30000);
	}
	//printf("test: %s\n",a );
	printf("\n");
	//pthread_exit (0);
}

int main(int argc, char const *argv[])
{
	printf("testerino\n");
	
	char* a="hola ";
	char* b="mundo";


	pthread_t tida;
	pthread_t tidb;

	pthread_create(&tida,NULL,(void*)msg,a);
	pthread_join(tida,NULL);
	pthread_create(&tidb,NULL,(void*)msg,b);
	pthread_join(tidb,NULL);


	return 0;
}
