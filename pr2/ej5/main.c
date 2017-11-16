#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>


struct param{
	int tam;
	int** matrix_mult;
	int* matrix;
	pthread_t* tid;
};


void* read_lines(void* parametros)
{
	struct param *param=(struct param*)parametros;
	int* exit_value=(int*)malloc(sizeof (int));
	*exit_value=0;
	int nthread;

	for (int i = 0; i < param->tam; ++i){
		if ( pthread_equal(param->tid[i],pthread_self()) ){
			nthread=i;
		}	
	}

	


	for (int i = 0; i < param->tam; ++i){
		(*exit_value)+=(param->matrix[i])*(param->matrix_mult[i][nthread]);
	}
		
	pthread_exit((void*)(exit_value));
}

int main(int argc, char const *argv[])
{
	int tam;
	printf("introduzca el tamaño de la matriz \n");
	scanf("%i",&tam);

	pthread_t tid[tam];
	struct param p;
	struct param* parametros=&p;
	parametros->tam=tam;
	parametros->matrix=(int*)malloc(sizeof(int)*tam);
	parametros->matrix_mult=(int**)calloc(sizeof(int*),tam);
	for (int i = 0; i < tam; ++i){
		parametros->matrix_mult[i]=(int*)calloc(sizeof(int),tam);
	}

	//asignacion de datos a la matriz multiplicadora
	printf("\n");
	printf("matriz multiplicadora\n");
	for (int i = 0; i < tam; ++i){ 
		for (int j = 0; j < tam; ++j){
			(parametros->matrix_mult)[i][j]=1;
			printf("%i, ",(parametros->matrix_mult)[i][j] );
		}
		printf("\n");
	}
	printf("\n");

	//asignacion de datos a la matriz
	printf("matrix:\n");
	for (int i = 0; i < tam; ++i){
		parametros->matrix[i]=1;
		printf("%i\n", parametros->matrix[i]);
	}
	printf("\n");


	for (int i = 0; i < tam; ++i){
		pthread_create(&tid[i],NULL,read_lines,(void*)parametros);
	}

	//asignacion de tids a la estructura parametro
	parametros->tid=(pthread_t *)malloc(sizeof(pthread_t)*tam);
	for (int i = 0; i < tam; ++i){
		parametros->tid[i]=tid[i];
	}

	//colecta los datos de los threads
	int* matrix=(int*)calloc(sizeof(int),tam);
	int* output;
	for (int i = 0; i < tam; ++i){
		pthread_join(tid[i],(void**)&output);
		matrix[i]=*output;
	}

	//imprime dichos datos
	printf("matriz resultado:\n");
	for (int i = 0; i < tam; ++i){
		printf("%i\n",matrix[i]);
	}
	
	return 0;
}
