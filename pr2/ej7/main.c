#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#define N_MODELOS 5

pthread_mutex_t lock_copia_parametros = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock_vector = PTHREAD_MUTEX_INITIALIZER;

int camisetas[N_MODELOS];

int posicion_clientes=0;
int posicion_proveedores=0;

void* modificar_clentes(void* parametros)
{
	pthread_mutex_t lock_producto_agotado = PTHREAD_MUTEX_INITIALIZER;
	int bool_=1;
	int dif=*(int*)parametros;
	pthread_mutex_unlock(&lock_copia_parametros);
	printf("dif: %i, camisetas: %i  ",dif,camisetas[posicion_clientes] );
	if (dif>camisetas[posicion_clientes]){
		printf("error, producto agotado\n");
	}

	//to do producto agotado
	
	else{
		pthread_mutex_lock(&lock_vector);
		camisetas[posicion_clientes]-=dif;
		posicion_clientes+=(posicion_clientes+1)%N_MODELOS;
		pthread_mutex_unlock(&lock_vector);
	}
}

void* modificar_proveedores(void* parametros)
{

	int dif=*(int*)parametros;
	//sleep(1);

	camisetas[posicion_proveedores]+=dif;
	posicion_proveedores+=(posicion_proveedores+1)%N_MODELOS;
	pthread_mutex_unlock(&lock_vector);
}

int main(int argc, char const *argv[])
{
	int n_clientes;
	printf("introduzca el numero de clientes\n");
	scanf("%i",&n_clientes);

	pthread_t tid_consumidores[N_MODELOS];
	pthread_t tid_proveedores[N_MODELOS];

	int cantidad=1;

	for (int i = 0; i < N_MODELOS; ++i){
		camisetas[i]=0;
	}

	printf("antes de compra\n");
	for (int i = 0; i < N_MODELOS; ++i){
		printf("camisetas[%i] = %i\n",i,camisetas[i] );
	}

//------------------------------------------------------------

	//lanza los threads de los clentes
	for (int i = 0; i < n_clientes; ++i){
		//pthread_mutex_lock(&lock_copia_parametros);
		//pthread_create(&tid_consumidores[i],NULL,modificar_clentes,(void*)&cantidad);
	}

	sleep(1);
	printf("\n");
	printf("despues de intento de compra\n");
	for (int i = 0; i < N_MODELOS; ++i){
		printf("camisetas[%i] = %i\n",i,camisetas[i] );
	}
	//lanza los threads de los proveedores
	for (int i = 0; i < N_MODELOS; ++i){
		pthread_mutex_lock(&lock_vector);
		pthread_create(&tid_proveedores[i],NULL,modificar_proveedores,(void*)&cantidad);
	}

	sleep(1);
	printf("\n");
	printf("despues de proveedores\n");
	for (int i = 0; i < N_MODELOS; ++i){
		printf("camisetas[%i] = %i\n",i,camisetas[i] );
	}

//------------------------------------------------------------

	//cierra los threads de los cientes
	for (int i = 0; i < n_clientes; ++i){
		//pthread_join(tid_consumidores[i],NULL);
	}

	//cierra los threads de los proveedores
	for (int i = 0; i < N_MODELOS; ++i){
		pthread_join(tid_proveedores[i],NULL);
	}
	sleep(1);
	printf("\n");
	printf("final\n");
	for (int i = 0; i < N_MODELOS; ++i){
		printf("camisetas[%i] = %i\n",i,camisetas[i] );
	}

	
	return 0;
}