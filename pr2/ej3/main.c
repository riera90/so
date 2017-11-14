#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#define LONG_VECT 10
int lock=1;

struct param_sum{
	int data[LONG_VECT];
	pthread_t tid_s[LONG_VECT];
};



void* sum_threads(void* parametros)
{
	struct param_sum*param=(struct param_sum*)parametros;
	int *sum=(int*)malloc(sizeof(int));
	*sum=0;
	while (lock);

	for (int i = 0; i < LONG_VECT; ++i){
		if ( pthread_equal(param->tid_s[i],pthread_self()) ){
			*sum+=param->data[i];
		}
	}
	pthread_exit ((void*)sum);
}

int main(int argc, char const *argv[])
{
	struct param_sum param;
	struct param_sum* parametros=&param;


	for (int i = 0; i < LONG_VECT; ++i){
		param.data[i]=1;
	}

	//nthreads value asociation
	int nthreads;
	printf("\n\n\ttype the number or threads: ");
	scanf("%i",&nthreads);
	printf(" \n\n");
	printf("nthreads: <%i>\n",nthreads);

	pthread_t tid[nthreads];

	//launch of threads
	for (int i = 0; i < nthreads; ++i){
		pthread_create(&tid[i],NULL,sum_threads,(void*)parametros);
	}

	//thread sum asign
	for (int i = 0; i < LONG_VECT; ++i){
		parametros->tid_s[i]=tid[i%nthreads];
	}

	lock=0;//launches the threads algorithm

	int *output;
	int result=0;

	for (int i = 0; i < nthreads; ++i){
		pthread_join(tid[i], (void **) &output);
		printf("output: <%d>\n",*output);
		result+=*output;
	}
	printf("result: <%i>\n",result);
	
	
	return 0;
}
