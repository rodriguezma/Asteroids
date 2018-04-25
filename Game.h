#pragma once
#include "ListaDisparos.h"
#include "ListaAsteroids.h"
#include "ListaPolys.h"
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

void DivideAsteoroid(NodoPoly **p, asteroid *a){
	switch(a->tipo){
		case 0:
			poly p1;
			p1.vertices = 4;
			p1.points = (esat::Vec2*)malloc(sizeof(esat::Vec2)*5);
			p1.points[0] = a->puntos_globales[0];
			p1.points[1] = a->puntos_globales[1];
			p1.points[2] = a->puntos_globales[2];
			p1.points[3] = a->puntos_globales[3];
			p1.points[4] = a->puntos_globales[0];
			poly p2;
			InsertarLista(p,p1);
			p2.vertices = 8;
			p2.points = (esat::Vec2*)malloc(sizeof(esat::Vec2)*9);
			p2.points[0] = a->puntos_globales[0];
			p2.points[1] = a->puntos_globales[3];
			p2.points[2] = a->puntos_globales[4];
			p2.points[3] = a->puntos_globales[5];
			p2.points[4] = a->puntos_globales[6];
			p2.points[5] = a->puntos_globales[7];
			p2.points[6] = a->puntos_globales[8];
			p2.points[7] = a->puntos_globales[9];
			p2.points[8] = a->puntos_globales[0];
			InsertarLista(p,p2);
		break;
		case 1:
			poly p3;
			p3.vertices = 6;
			p3.points = (esat::Vec2*)malloc(sizeof(esat::Vec2)*7);
			p3.points[0] = a->puntos_globales[0];
			p3.points[1] = a->puntos_globales[1];
			p3.points[2] = a->puntos_globales[2];
			p3.points[3] = a->puntos_globales[3];
			p3.points[4] = a->puntos_globales[4];
			p3.points[5] = a->puntos_globales[5];
			p3.points[6] = a->puntos_globales[0];
			InsertarLista(p,p3);
			poly p4;
			p4.vertices = 4;
			p4.points = (esat::Vec2*)malloc(sizeof(esat::Vec2)*5);
			p4.points[0] = a->puntos_globales[5];
			p4.points[1] = a->puntos_globales[6];
			p4.points[2] = a->puntos_globales[7];
			p4.points[3] = a->puntos_globales[8];
			p4.points[4] = a->puntos_globales[5];
			InsertarLista(p,p4);
			poly p5;
			p5.vertices = 4;
			p5.points = (esat::Vec2*)malloc(sizeof(esat::Vec2)*5);
			p5.points[0] = a->puntos_globales[5];
			p5.points[1] = a->puntos_globales[9];
			p5.points[2] = a->puntos_globales[10];
			p5.points[3] = a->puntos_globales[0];
			p5.points[4] = a->puntos_globales[5];
			InsertarLista(p,p5);
		break;
		case 2:
			
			poly p6;
			p6.vertices = 5;
			p6.points = (esat::Vec2*)malloc(sizeof(esat::Vec2)*6);
			p6.points[0] = a->puntos_globales[0];
			p6.points[1] = a->puntos_globales[1];
			p6.points[2] = a->puntos_globales[2];
			p6.points[3] = a->puntos_globales[9];
			p6.points[4] = a->puntos_globales[10];
			p6.points[5] = a->puntos_globales[0];
			InsertarLista(p,p6);
			poly p7;	
			p7.vertices = 4;
			p7.points = (esat::Vec2*)malloc(sizeof(esat::Vec2)*5);
			p7.points[0] = a->puntos_globales[2];
			p7.points[1] = a->puntos_globales[3];
			p7.points[2] = a->puntos_globales[4];
			p7.points[3] = a->puntos_globales[5];
			p7.points[4] = a->puntos_globales[2];
			InsertarLista(p,p7);
			poly p8;
			p8.vertices = 6;
			p8.points = (esat::Vec2*)malloc(sizeof(esat::Vec2)*7);
			p8.points[0] = a->puntos_globales[2];
			p8.points[1] = a->puntos_globales[5];
			p8.points[2] = a->puntos_globales[6];
			p8.points[3] = a->puntos_globales[7];
			p8.points[4] = a->puntos_globales[8];
			p8.points[5] = a->puntos_globales[9];
			p8.points[6] = a->puntos_globales[2];
			InsertarLista(p,p8);
		break;
		case 3:
			poly p9;
			p9.vertices = 4;
			p9.points = (esat::Vec2*)malloc(sizeof(esat::Vec2)*5);
			p9.points[0] = a->puntos_globales[0];
			p9.points[1] = a->puntos_globales[1];
			p9.points[2] = a->puntos_globales[2];
			p9.points[3] = a->puntos_globales[11];
			p9.points[4] = a->puntos_globales[0];
			InsertarLista(p,p9);
			poly p10;
			p10.vertices = 7;
			p10.points = (esat::Vec2*)malloc(sizeof(esat::Vec2)*8);
			p10.points[0] = a->puntos_globales[2];
			p10.points[1] = a->puntos_globales[3];
			p10.points[2] = a->puntos_globales[4];
			p10.points[3] = a->puntos_globales[5];
			p10.points[4] = a->puntos_globales[8];
			p10.points[5] = a->puntos_globales[9];
			p10.points[6] = a->puntos_globales[10];
			p10.points[7] = a->puntos_globales[2];
			InsertarLista(p,p10);
			poly p11;
			p11.vertices = 4;
			p11.points = (esat::Vec2*)malloc(sizeof(esat::Vec2)*5);
			p11.points[0] = a->puntos_globales[5];
			p11.points[1] = a->puntos_globales[6];
			p11.points[2] = a->puntos_globales[7];
			p11.points[3] = a->puntos_globales[8];
			p11.points[4] = a->puntos_globales[5];
			InsertarLista(p,p11);
		break;
	}
}

bool TestColPolys(NodoPoly *p, esat::Vec2 v){
	NodoPoly *aux = p;
	
	while(aux != NULL){
		if(ColVec2Poly(v,aux->val))
			return true;
		aux = aux->nextNodo;
	}

	return false;

}

void DivideAsteroidCol(NodoAsteroid **a,int size,esat::Vec2 pos){
	asteroid a1,a2;
	Init_asteroid(&a1,size);
	Init_asteroid(&a2,size);
	a1.pos = pos;
	a2.pos = pos;
	InsertarLista(a,a1);
	InsertarLista(a,a2);
}

void ColShotAsteroids(NodoAsteroid **a, NodoDisparo **d){
	
	NodoDisparo *auxd = *d;
	NodoDisparo *auxd2 = NULL;
	NodoAsteroid *auxa = *a;
	NodoPoly *p = NULL;

	while(auxd != NULL){
		auxd2 = auxd->nextNodo;
		auxa = *a;
		while(auxa != NULL){

			DivideAsteoroid(&p, &(auxa->val));
			if(TestColPolys( p, auxd->val.pos)){
				printf("-------------------------");
				if(auxa->val.size>5)
					DivideAsteroidCol(a,auxa->val.size/2,auxa->val.pos);
				EliminarNodo(auxa,a);
				EliminarNodo(auxd,d);
			}
			BorrarLista(&p);
			auxa = auxa->nextNodo;
		}
		auxd = auxd2;
	}
}

void DeadTimeShots(NodoDisparo **d){
	
	NodoDisparo *auxd = *d;
	NodoDisparo *auxd2 = NULL;
	
	while(auxd != NULL){
		auxd2 = auxd->nextNodo;
		if((auxd->val.time + 1500) < esat::Time()){
			EliminarNodo(auxd,d);
		}
		auxd = auxd2;
	}
	
}

void ColShipAsteroids(ship *nave, NodoAsteroid **a){
	NodoAsteroid *auxa = *a; 
	NodoPoly *p = NULL;
	esat::Vec2 ColShip[] = {{nave->puntos_globales[0]},{nave->puntos_globales[1]},{nave->puntos_globales[4]}};
	int i;
	bool col = false;
	while(auxa != NULL){
		col = false;
		i = 0;
		DivideAsteoroid(&p,&(auxa->val));
		while(col == false && i<3){
			if(TestColPolys(p,ColShip[i])){
				col = true;
				if(auxa->val.size>5)
					DivideAsteroidCol(a,auxa->val.size/2,auxa->val.pos);
				EliminarNodo(auxa,a);
				InitShip(nave);
			}
			BorrarLista(&p);
			i++;
		}
		
	auxa = auxa->nextNodo;	
	}
}



