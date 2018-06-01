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

bool EsvaciaLista(NodoDisparo *Lista){			//Comprueba si esta vacia
	if(Lista == NULL)
		return true;
	else
		return false;
}

void EliminarNodo(NodoDisparo *Nodo, NodoDisparo **Lista){		//Elimina el nodo pasado por parametro y conecta los adyacentes si los hubiera
	
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

void BorrarLista(NodoDisparo **Lista){		//Recorre la lista borrando los nodos
	NodoDisparo *auxNodo = NULL;
	while(!EsvaciaLista(*Lista)){
		auxNodo = *Lista;
		*Lista = auxNodo -> nextNodo;
		free(auxNodo);
	}
}


void InsertarLista(NodoDisparo **Lista, disparo val){			//Inserta nodo por el inicio
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


