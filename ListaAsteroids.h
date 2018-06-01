#pragma once
#include "asteroids.h"


struct NodoAsteroid{
	asteroid val;
	NodoAsteroid *nextNodo = NULL;
	NodoAsteroid *prevNodo = NULL;
};


NodoAsteroid* CrearListaAsteroide(void){
	return NULL;
}

bool EsvaciaLista(NodoAsteroid *Lista){
	if(Lista == NULL)
		return true;
	else
		return false;
}

void EliminarNodo(NodoAsteroid *Nodo, NodoAsteroid **Lista){
	
	if(!EsvaciaLista(*Lista)&& Nodo != NULL){
		NodoAsteroid *nextNodo = Nodo->nextNodo;
		NodoAsteroid *prevNodo = Nodo->prevNodo;
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

void BorrarLista(NodoAsteroid **Lista){
	NodoAsteroid *auxNodo = NULL;
	while(!EsvaciaLista(*Lista)){
		auxNodo = *Lista;
		*Lista = auxNodo -> nextNodo;
		free(auxNodo);
	}
}


void InsertarLista(NodoAsteroid **Lista, asteroid val){
	NodoAsteroid *Nodo = (NodoAsteroid*)malloc(sizeof(NodoAsteroid));
	
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

void MostrarLista(NodoAsteroid *Lista){
	NodoAsteroid *aux = Lista;
	
	
	
	while(aux != NULL){
	
		Draw_asteroid(&(aux->val));
		aux = aux -> nextNodo;
	}	
	

}

void MoveAsteroids(NodoAsteroid **Lista){
	NodoAsteroid *aux = *Lista;

	
	while(aux != NULL){
		UpdatePos(&(aux->val));
		aux = aux -> nextNodo;
	}	

}

void InitAsteroids(NodoAsteroid **Lista){		//Inicializa los asteroides de la partida

	asteroid asteroide1;						//Crea 3 asteroides y los introduce en la lista
	Init_asteroid(&asteroide1,20);
	asteroid asteroide2;
	Init_asteroid(&asteroide2,20);
	asteroid asteroide3;
	Init_asteroid(&asteroide3,20);

	InsertarLista(Lista,asteroide1);
	InsertarLista(Lista,asteroide2);
	InsertarLista(Lista,asteroide3);

}


