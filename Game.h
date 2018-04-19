#include "ListaDisparos.h"
#include "ListaAsteroids.h"
#include "ships.h"


void Disparo(NodoDisparo *ListaDisparos, ship *nave){
	
	if(esat::IsSpecialKeyDown(esat::kSpecialKey_Keypad_1)){
		disparo newshot;
		Init_disparo(&newshot,nave->puntos_globales[0],nave->v_dir);
		InsertarLista(&ListaDisparos,newshot);
	}
	
}

void BorrarDisparo(NodoDisparo *Lista){
	NodoDisparo *aux = Lista;
	aux = aux->nextNodo;
	if(esat::IsSpecialKeyDown(esat::kSpecialKey_Keypad_2))
		EliminarNodo(aux,&Lista);
}

void BorrarAst(NodoAsteroid *Lista){
	NodoAsteroid *aux = *Lista;
	aux = aux->nextNodo;
	if(esat::IsSpecialKeyDown(esat::kSpecialKey_Space))
		EliminarNodo(aux,&Lista);
}