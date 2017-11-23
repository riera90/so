#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#define N_CAMISETAS 5

void printc();

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t vector = PTHREAD_MUTEX_INITIALIZER;

int camisetas[N_CAMISETAS];

int posicion_clientes=0;
int posicion_proveedores=0;

void* modificar_clentes(void* parametros){
	pthread_mutex_lock(&lock);

	while(*(int*)parametros>camisetas[posicion_clientes]){
		pthread_mutex_lock(&vector);
		printf("bloqueado\n");
	}
	camisetas[posicion_clientes]-=*(int*)parametros;
	posicion_clientes++;
	posicion_clientes%=N_CAMISETAS;

	pthread_mutex_unlock(&lock);
}


void* modificar_proveedores(void* parametros){
	pthread_mutex_lock(&lock);
	camisetas[posicion_proveedores]+=*(int*)parametros;
	printf("proveedores %i\n",posicion_proveedores);
	posicion_proveedores++;
	posicion_proveedores%=N_CAMISETAS;
	pthread_mutex_unlock(&lock);
	pthread_mutex_unlock(&vector);
}

int main(int argc, char const *argv[])
{




	int n_clientes;
	int n_proveedores;
	int cantidad=1;
	printf("introduzca el numero de clientes\n");
	scanf("%i",&n_clientes);

	printf("introduzca el numero de proveedores\n");
	scanf("%i",&n_proveedores);

	//n_clientes=5;
	//n_proveedores=10;

	pthread_t tid_consumidores[n_proveedores];
	pthread_t tid_proveedores[n_proveedores];


	for (int i = 0; i < n_proveedores; ++i){
		camisetas[i]=0;
	}
	printc();


//------------------------------------------------------------


	
	//lanza los threads de los proveedores
	for (int i = 0; i < n_proveedores; ++i){
		pthread_create(&tid_proveedores[i],NULL,modificar_proveedores,(void*)&cantidad);
	}
	
	//lanza los threads de los clentes
	for (int i = 0; i < n_clientes; ++i){
		pthread_create(&tid_consumidores[i],NULL,modificar_clentes,(void*)&cantidad);
	}

//------------------------------------------------------------



	//cierra los threads de los proveedores
	for (int i = 0; i < n_proveedores; ++i){
		pthread_join(tid_proveedores[i],NULL);
	}

	//cierra los threads de los cientes
	for (int i = 0; i < n_clientes; ++i){
		pthread_join(tid_consumidores[i],NULL);
	}
	printc();


	
	return 0;
}



void printc()
{
	for (int i = 0; i < N_CAMISETAS; ++i){
		printf("camisetas[%i] = %i\n",i,camisetas[i]);
	}
	printf("\n\n");
}