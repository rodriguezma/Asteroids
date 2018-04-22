#pragma once
#include "ListaDisparos.h"
#include "ListaAsteroids.h"
#include "ships.h"


void Disparo(NodoDisparo **ListaDisparos, ship *nave){
	
	if(esat::IsSpecialKeyDown(esat::kSpecialKey_Space)){
		disparo newshot;
		Init_disparo(&newshot,nave);
		InsertarLista(ListaDisparos,newshot);
	}
	
}

void BorrarDisparo(NodoDisparo *Lista){
	NodoDisparo *aux = Lista;
	aux = aux->nextNodo;
	if(esat::IsSpecialKeyDown(esat::kSpecialKey_Keypad_2))
		EliminarNodo(aux,&Lista);
}

void BorrarAst(NodoAsteroid **Lista){
	NodoAsteroid *aux = *Lista;

	if(esat::IsSpecialKeyDown(esat::kSpecialKey_Enter))
		EliminarNodo(aux,Lista);
}

void BorrarDsp(NodoDisparo **Lista){
	NodoDisparo *aux = *Lista;
	
	if(esat::IsSpecialKeyDown(esat::kSpecialKey_Keypad_1))
		EliminarNodo(aux,Lista);
}