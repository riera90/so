#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>



void* read_lines(void* parametros)
{
	int* exit_value=(int*)malloc(sizeof (int));
	*exit_value=-1;
	FILE* f;
	f=fopen( (char*)parametros, "r" );

	int nlineas=0;
	char* temp;
	size_t tam=1;
	size_t tam_leido=0;
	while (tam_leido!=-1){
		(*exit_value)++;
		tam_leido=getline (&temp,&tam,f);
	}

	fclose(f);
	pthread_exit((void*)(exit_value));
}

int main(int argc, char const *argv[])
{
	pthread_t tid[argc];

	for (int i = 0; i < argc-1; ++i){
		pthread_create(&tid[i],NULL,read_lines,(void*)argv[i+1]);
	}
	
	int* output;
	int suma_lineas=0;
	for (int i = 0; i < argc-1; ++i){
		pthread_join(tid[i],(void**)&output);
		printf("el documento %s tiene %i lineas\n",argv[i+1],*output);
		suma_lineas+=*output;
	}
	printf("la suma de las lineas de todas las lineas es: %i\n", suma_lineas);
	
	
	return 0;
}
