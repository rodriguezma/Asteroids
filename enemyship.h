#pragma once
#include <esat/math.h>
#include <esat/draw.h>
#include "Math_aux.h"

struct EnemyShip{
	esat::Vec2 puntos_locales[9] = {{1.f,-3.f},{2.f,-1.f},{5.f,1.f},
	{2.f,3.f},{-2.f,3.f},{-5.f,1.f},
	{-2.f,-1.f},{-1.f,-3.f},{1.f,-3.f}};
	esat::Vec2 puntos_globales[9];
	esat::Vec2 pos;
	esat::Vec2 v_dir;
	float v;
	bool live;
	int size;

};

void InitShip(EnemyShip *nave){
	if(rand()%2 == 0){
		nave->pos = {1.f,(float)(rand()%500 + 50)};
		esat::Vec2 t = {1.f,(float)(rand()%3-1)};
		t = Vec2Normalized(t);
		nave->v_dir = t;
	}else{
		nave->pos = {799.f,(float)(rand()%500 + 50)};
		esat::Vec2 t = {-1.f,(float)(rand()%3-1)};
		t = Vec2Normalized(t);
		nave->v_dir = t;
		
	}
	
	nave->v = 3;
	nave->size = rand()%3+4;
	nave->live = false;
}

void DrawShip(EnemyShip *nave){
	
	if(nave->live){
	esat::Mat3 t = esat::Mat3Scale(nave->size, nave->size);
	
	t = esat::Mat3Multiply(esat::Mat3Translate(nave->pos.x, nave->pos.y), t);
	for (int i = 0; i<9; i++) {
		nave->puntos_globales[i] = esat::Mat3TransformVec2(t, nave->puntos_locales[i]);
	}
	
	
		esat::DrawPath(&(nave->puntos_globales[0].x),9);
		esat::DrawLine(nave->puntos_globales[1].x,nave->puntos_globales[1].y,nave->puntos_globales[6].x,nave->puntos_globales[6].y);
		esat::DrawLine(nave->puntos_globales[2].x,nave->puntos_globales[2].y,nave->puntos_globales[5].x,nave->puntos_globales[5].y);
	}
	
}

void UpdatePos(EnemyShip *nave){
	if(nave->live){
		nave->pos = Vec2plusVec2(nave->pos,Vec2xScalar(nave->v_dir,nave->v));
		if(nave->pos.x<0)
			nave->pos.x = 800 + nave->pos.x;
		if(nave->pos.y<0)
			nave->pos.y = 600 + nave->pos.y;
		nave->pos.x = (int)nave->pos.x%800;
		nave->pos.y = (int)nave->pos.y%600;			
	}
}

void UpdateState(EnemyShip *nave){
	if(!nave->live){
		if(rand()%1000 < 2){
			InitShip(nave);
			nave->live = true;
		}
	}
}
void UpdateDir(EnemyShip *nave){
	if(nave->live){
		if(rand()%1000 < 10){
			nave->v_dir.y = (float)(rand()%3-1);
			nave->v_dir = Vec2Normalized(nave->v_dir);
		}
	}
}