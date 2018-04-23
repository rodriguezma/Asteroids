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

void DivideAsteoroid(poly *p, asteroid *a){
	switch(a->tipo){
		case 0:
			p->points = (esat::Vec2*)malloc(sizeof(esat::Vec2)*(p->vertices + 1));
			p->points[0] = a->puntos_globales[0];
			p->points[1] = a->puntos_globales[1];
			p->points[2] = a->puntos_globales[2];
			p->points[3] = a->puntos_globales[3];
			p->points[4] = a->puntos_globales[0];
		break;
		case 1:
		break;
		case 2:
		break;
		case 3:
		break;
	}
}

void ColDotPoly(){
	
}