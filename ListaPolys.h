#pragma once
#include "Math_aux.h"


struct NodoPoly{
	poly val;
	NodoPoly *nextNodo = NULL;
	NodoPoly *prevNodo = NULL;
};


NodoPoly* CrearListaPoly(void){
	return NULL;
}

bool EsvaciaLista(NodoPoly *Lista){
	if(Lista == NULL)
		return true;
	else
		return false;
}

void EliminarNodo(NodoPoly *Nodo, NodoPoly **Lista){
	
	if(!EsvaciaLista(*Lista)&& Nodo != NULL){
		NodoPoly *nextNodo = Nodo->nextNodo;
		NodoPoly *prevNodo = Nodo->prevNodo;
		if(prevNodo == NULL && nextNodo == NULL){
			free(Nodo);
			*Lista = NULL;
		}
		else if(prevNodo == NULL){
			nextNodo->prevNodo = NULL;
			*Lista = nextNodo;
			free(Nodo);
		}else if(nextNodo == NULL){
			prevNodo->nextNodo = NULL;
			free(Nodo);
		}else{
			nextNodo->prevNodo = prevNodo;
			prevNodo->nextNodo = nextNodo;
			free(Nodo);
		}
	
	}
	
}

void BorrarLista(NodoPoly **Lista){
	NodoPoly *auxNodo = NULL;
	while(!EsvaciaLista(*Lista)){
		auxNodo = *Lista;
		*Lista = auxNodo -> nextNodo;
		free(auxNodo);
	}
}


void InsertarLista(NodoPoly **Lista, poly val){
	NodoPoly *Nodo = (NodoPoly*)malloc(sizeof(NodoPoly));
	Nodo -> val = val;
	Nodo -> prevNodo = NULL;
	
	
	if(EsvaciaLista(*Lista)){
		Nodo->nextNodo = NULL;
		*Lista = Nodo;
	}else{
		Nodo -> nextNodo = *Lista;
		(*Lista)->prevNodo = Nodo;
		*Lista = Nodo;
	}
}




