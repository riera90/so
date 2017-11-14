#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; 



void* call(void* seed)
{
	int sum;
	pthread_mutex_lock(&lock);
	sum=rand()%100+1;
	pthread_mutex_unlock(&lock);
	
	printf("pseudo random number generator <%i>\n",sum );

	pthread_exit ((void*)&sum);
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	printf("this program add random values \ngenerated on diferent threads\n");
	int nthreads;
	void* output;
	int result=0;
	printf("\n\n\ttype the number or threads: ");
	scanf("%i",&nthreads);
	printf(" \n\n");
	printf("nthreads: <%i>\n",nthreads );
	int seed[nthreads];
	pthread_t thread[nthreads];

	for (int i = 0; i < nthreads; ++i) seed[i]=i;

	for (int i = 0; i < nthreads; ++i){
		pthread_create(&thread[i],NULL,call,(void*)&seed[i]);
	}
	for (int i = 0; i < nthreads; ++i){
		pthread_join(thread[i],&output);
		result+=*(int*)output;
	}
	printf("result: <%i>\n",result);
	

	return 0;
}
