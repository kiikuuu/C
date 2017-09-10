#include <stdio.h>
#include <stdlib.h>

void* mallocc(size_t size){

	void* value = malloc(size);
	if(value == NULL){
		fprintf(stderr, "Não foi possivel alocar memoria!\n");
		exit(1);
	}else
		return value;
}

void* callocc(size_t nItens , size_t size){

	void* value = calloc(nItens , size);
	if(value == NULL){
		fprintf(stderr,"Não foi possivel alocar memoria!\n");
		exit(1);
	}else
		return value;
}
