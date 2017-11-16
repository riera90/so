#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#define N_THREADS 10

int contador=0;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; 

void* contador_(void* a)
{
	pthread_mutex_lock(&lock);

	for (int i = 0; i < 100; ++i) contador++;

	pthread_mutex_unlock(&lock);

}

int main(int argc, char const *argv[])
{
	pthread_t tid[N_THREADS];

	for (int i = 0; i < N_THREADS; ++i){
		pthread_create(&tid[i],NULL,contador_,NULL);
	}

	for (int i = 0; i < N_THREADS; ++i){
		pthread_join(tid[i],NULL);

	}
	printf("contador: <%i>\n",contador );

	return 0;
}
