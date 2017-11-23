#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>



void* consumidor(void* parametro){
	int cp_parametro=*(int*)parametro;
	//if not enought //lock
	//remove element
}

void* productor(void* parametro){
	int cp_parametro=*(int*)parametro;
	//add element
}


int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}