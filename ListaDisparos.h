#pragma once
#include "disparo.h"


struct NodoDisparo{
	disparo val;
	NodoDisparo *nextNodo = NULL;
	NodoDisparo *prevNodo = NULL;
};


NodoDisparo* CrearListaDisparo(void){
	return NULL;
}

bool EsvaciaLista(NodoDisparo *Lista){
	if(Lista == NULL)
		return true;
	else
		return false;
}

void EliminarNodo(NodoDisparo *Nodo, NodoDisparo **Lista){
	
	if(!EsvaciaLista(*Lista)&& Nodo != NULL){
		NodoDisparo *nextNodo = Nodo->nextNodo;
		NodoDisparo *prevNodo = Nodo->prevNodo;
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

void BorrarLista(NodoDisparo **Lista){
	NodoDisparo *auxNodo = NULL;
	while(!EsvaciaLista(*Lista)){
		auxNodo = *Lista;
		*Lista = auxNodo -> nextNodo;
		free(auxNodo);
	}
}


void InsertarLista(NodoDisparo **Lista, disparo val){
	NodoDisparo *Nodo = (NodoDisparo*)malloc(sizeof(NodoDisparo));

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

void MostrarLista(NodoDisparo *Lista){
	NodoDisparo *aux = Lista;

	while(aux != NULL){
		Draw_shot(&(aux->val));
		aux = aux -> nextNodo;
	}	

}

void MoveDisparos(NodoDisparo **Lista){
	NodoDisparo *aux = *Lista;
	

	while(aux != NULL){
		UpdatePos(&(aux->val));
		aux = aux -> nextNodo;
	}	

}


