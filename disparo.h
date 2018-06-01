#pragma once
#include <esat/draw.h>
#include <esat/time.h>
#include "Math_aux.h"
#include "ships.h"
#include "enemyship.h"



struct disparo{ 
	esat::Vec2 pos;
	esat::Vec2 v;
	double time;
};

void Init_disparo(disparo *a, ship *nave){		//Inicializa el disparo
	a->pos = nave->puntos_globales[0];			//Posicion del disparo sera igual al punto de arriba de la nave
	a->v = Vec2xScalar(nave->v_dir,8);
	a->time = esat::Time();
}
void Init_disparo(disparo *a, EnemyShip *nave, esat::Vec2 v){	//Inicializa el disparo de la nave enemiga
	a->pos = nave->pos;											
	a->v = Vec2minusVec2(v,nave->pos);							//Vector director resultante de restar la posicion de la nave, con la de la nave enemiga
	a->v = Vec2Normalized(a->v);								
	a->v = Vec2xScalar(a->v,8);
	a->time = esat::Time();	
}

void Draw_shot(disparo *a){						//Dibuja el disparo
	
	esat::Vec2 aux = Vec2minusVec2(a->pos,Vec2xScalar(Vec2Normalized(a->v),4.f));
	esat::DrawLine(a->pos.x,a->pos.y,aux.x,aux.y);
	
}

void UpdatePos(disparo *a){ 					//Actualiza la posicion de los disparos	
	a->pos = Vec2plusVec2(a->pos,a->v);
	if(a->pos.x<0)								//Actualiza la posicion cuando rebasa los limites
		a->pos.x = 800 + a->pos.x;
	if(a->pos.y<0)
		a->pos.y = 600 + a->pos.y;
	a->pos.x = (int)a->pos.x%800;
	a->pos.y = (int)a->pos.y%600;	
}

