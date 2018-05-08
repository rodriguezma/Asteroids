#pragma once
#include "ListaDisparos.h"
#include "ListaAsteroids.h"
#include "ListaPolys.h"
#include "ships.h"
#include "enemyship.h"


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

bool TestColPolys(NodoPoly **p, esat::Vec2 v){
	NodoPoly *aux = *p;
	
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
	bool col = false;

	while(auxd != NULL){
		col = false;
		auxa = *a;
		while(auxa != NULL && col == false){

			DivideAsteoroid(&p, &(auxa->val));
			if(TestColPolys( &p, auxd->val.pos)){
				col = true;
				if(auxa->val.size>5)
					DivideAsteroidCol(a,auxa->val.size/2,auxa->val.pos);
				auxd2 = auxd;
				auxd = auxd->nextNodo;
				EliminarNodo(auxa,a);
				EliminarNodo(auxd2,d);
			}
			BorrarLista(&p);
			auxa = auxa->nextNodo;
			
		}
		if(col == false)
			auxd = auxd->nextNodo;
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
	NodoAsteroid *auxa2 = NULL;
	
	NodoPoly *p = NULL;
	esat::Vec2 *ColShip = (esat::Vec2*)malloc(sizeof(esat::Vec2)*3);
	ColShip[0] = {nave->puntos_globales[0]};
	ColShip[1] = {nave->puntos_globales[1]};
	ColShip[2] = {nave->puntos_globales[4]};
	
	esat::Vec2 colDot;

	int i;
	bool col = false;
	while(auxa != NULL){
		col = false;
		i = 0;
		
		while(col == false && i<3){
			DivideAsteoroid(&p,&(auxa->val));
			colDot = ColShip[i];
			if(TestColPolys(&p,colDot)){
				col = true;
				if(auxa->val.size>5)
					DivideAsteroidCol(a,auxa->val.size/2,auxa->val.pos);
				auxa2 = auxa;
				auxa = auxa->nextNodo;
				EliminarNodo(auxa2,a);
				InitShip(nave);
			}
			BorrarLista(&p);
			i++;
			

		}
	
		if(col == false)
			auxa = auxa->nextNodo;	
	}
	
}

void ColEnemyAsteroids(EnemyShip *nave, NodoAsteroid **a){
	
	if(nave->live){
		NodoAsteroid *auxa = *a;
		NodoAsteroid *auxa2 = NULL;
		
		NodoPoly *p = NULL;
		esat::Vec2 *ColShip = (esat::Vec2*)malloc(sizeof(esat::Vec2)*6);
		ColShip[0] = nave->puntos_globales[0];
		ColShip[1] = nave->puntos_globales[2];
		ColShip[2] = nave->puntos_globales[3];
		ColShip[3] = nave->puntos_globales[4];
		ColShip[4] = nave->puntos_globales[5];
		ColShip[5] = nave->puntos_globales[7];
		
		esat::Vec2 colDot;

		int i;
		bool col = false;
		while(auxa != NULL){
			col = false;
			i = 0;
			
			while(col == false && i<6){
				DivideAsteoroid(&p,&(auxa->val));
				colDot = ColShip[i];
				if(TestColPolys(&p,colDot)){
					col = true;
					nave->live = false;
					if(auxa->val.size>5)
						DivideAsteroidCol(a,auxa->val.size/2,auxa->val.pos);
					auxa2 = auxa;
					auxa = auxa->nextNodo;
					EliminarNodo(auxa2,a);
					
				}
				BorrarLista(&p);
				i++;
				

			}
		
			if(col == false)
				auxa = auxa->nextNodo;	
		}
	}
}

void Disparo(NodoDisparo **ListaDisparos, EnemyShip *enemiga, ship *nave){
	if(enemiga->live){
		if(rand()%1000 < 10){
			disparo newshot;
			Init_disparo(&newshot,enemiga,nave->pos);
			InsertarLista(ListaDisparos,newshot);
		}
	}
}

void ColShipEnemy(EnemyShip *enemiga, ship *nave){
	
	if(enemiga->live == true){
		bool col = false;
		int i = 0;
		NodoPoly *Lp = NULL;
		esat::Vec2 *ColShip = (esat::Vec2*)malloc(sizeof(esat::Vec2)*3);
		ColShip[0] = nave->puntos_globales[0];
		ColShip[1] = nave->puntos_globales[1];
		ColShip[2] = nave->puntos_globales[4];
		
		poly p;
		
		p.points = (esat::Vec2*)malloc(sizeof(esat::Vec2)*7);
		p.points[0] = enemiga->puntos_globales[0];
		p.points[1] = enemiga->puntos_globales[2];
		p.points[2] = enemiga->puntos_globales[3];
		p.points[3] = enemiga->puntos_globales[4];
		p.points[4] = enemiga->puntos_globales[5];
		p.points[5] = enemiga->puntos_globales[7];
		p.points[6] = enemiga->puntos_globales[0];
		p.vertices = 6;
		
		InsertarLista(&Lp,p);
		
		while(col == false && i<3){
			if(TestColPolys(&Lp,ColShip[i])){
				col = true;
				InitShip(nave);
				enemiga->live = false;
			}
			i++;
		}
		
	}
}







