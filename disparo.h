#pragma once
#include <esat/draw.h>
#include "Math_aux.h"
#include "ships.h"


struct disparo{
	esat::Vec2 pos;
	esat::Vec2 v;
};

void Init_disparo(disparo *a, ship *nave){
	a->pos = nave->puntos_globales[0];
	a->v = Vec2xScalar(nave->v_dir,8);
}

void Draw_shot(disparo *a){
	
	esat::Vec2 aux = Vec2minusVec2(a->pos,Vec2xScalar(Vec2Normalized(a->v),4.f));
	esat::DrawLine(a->pos.x,a->pos.y,aux.x,aux.y);
	
}

void UpdatePos(disparo *a){
	a->pos = Vec2plusVec2(a->pos,a->v);
	if(a->pos.x<0)
		a->pos.x = 800 + a->pos.x;
	if(a->pos.y<0)
		a->pos.y = 600 + a->pos.y;
	a->pos.x = (int)a->pos.x%800;
	a->pos.y = (int)a->pos.y%600;	
}
