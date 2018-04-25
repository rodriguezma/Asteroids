#pragma once
#include <esat/draw.h>
#include "Math_aux.h"


struct asteroid{
	esat::Vec2 *puntos_locales;
	esat::Vec2 *puntos_globales;
	esat::Vec2 pos;
	esat::Vec2 v;
	int vertices;
	int size;
	int tipo;

};

void Init_asteroid(asteroid *a, int size){
	
	int randAsteroid = rand()%4;

	a->tipo = randAsteroid;
	
	switch(randAsteroid){
		
		case 0:
			a->puntos_globales = (esat::Vec2*)malloc(sizeof(esat::Vec2)* 11);
			a->puntos_locales = (esat::Vec2*)malloc(sizeof(esat::Vec2)*11);
			a->vertices = 11;
			a->puntos_locales[0] = {0.f,2.f};
			a->puntos_locales[1] = {2.f,3.f};
			a->puntos_locales[2] = {4.f,2.f};
			a->puntos_locales[3] = {3.f,0.f};
			a->puntos_locales[4] = {4.f,-2.f};
			a->puntos_locales[5] = {1.f,-3.f};
			a->puntos_locales[6] = {-2.f,-3.f};
			a->puntos_locales[7] = {-4.f,-1.f};
			a->puntos_locales[8] = {-4.f,2.f};
			a->puntos_locales[9] = {-2.f,3.f};
			a->puntos_locales[10] = {0.f,2.f};
		break;
		case 1:
			a->puntos_globales = (esat::Vec2*)malloc(sizeof(esat::Vec2)* 12);
			a->puntos_locales = (esat::Vec2*)malloc(sizeof(esat::Vec2)*12);
			a->vertices = 12;
			a->puntos_locales[0] = {2.f,3.f};
			a->puntos_locales[1] = {4.f,1.f};
			a->puntos_locales[2] = {4.f,-1.f};
			a->puntos_locales[3] = {2.f,-3.f};
			a->puntos_locales[4] = {0.f,-3.f};
			a->puntos_locales[5] = {0.f,-1.f};
			a->puntos_locales[6] = {-2.f,-3.f};
			a->puntos_locales[7] = {-4.f,-1.f};
			a->puntos_locales[8] = {-2.f,0.f};
			a->puntos_locales[9] = {-4.f,1.f};
			a->puntos_locales[10] = {-1.f,3.f};
			a->puntos_locales[11] = {2.f,3.f};
		break;
		case 2:
			a->puntos_globales = (esat::Vec2*)malloc(sizeof(esat::Vec2)* 12);
			a->puntos_locales = (esat::Vec2*)malloc(sizeof(esat::Vec2)*12);
			a->vertices = 12;
			a->puntos_locales[0] = {1.f,3.f};
			a->puntos_locales[1] = {4.f,1.f};
			a->puntos_locales[2] = {1.f,0.f};
			a->puntos_locales[3] = {4.f,-1.f};
			a->puntos_locales[4] = {2.f,-3.f};
			a->puntos_locales[5] = {1.f,-2.f};
			a->puntos_locales[6] = {-2.f,-3.f};
			a->puntos_locales[7] = {-4.f,0.f};
			a->puntos_locales[8] = {-4.f,2.f};
			a->puntos_locales[9] = {-1.f,2.f};
			a->puntos_locales[10] = {-2.f,3.f};
			a->puntos_locales[11] = {1.f,3.f};
		break;
		case 3:
			a->puntos_globales = (esat::Vec2*)malloc(sizeof(esat::Vec2)* 13);
			a->puntos_locales = (esat::Vec2*)malloc(sizeof(esat::Vec2)*13);
			a->vertices = 13;
			a->puntos_locales[0] = {2.f,3.f};
			a->puntos_locales[1] = {4.f,2.f};
			a->puntos_locales[2] = {2.f,1.f};
			a->puntos_locales[3] = {4.f,-1.f};
			a->puntos_locales[4] = {2.f,-3.f};
			a->puntos_locales[5] = {-1.f,-2.f};
			a->puntos_locales[6] = {-2.f,-3.f};
			a->puntos_locales[7] = {-4.f,-2.f};
			a->puntos_locales[8] = {-3.f,0.f};
			a->puntos_locales[9] = {-4.f,1.f};
			a->puntos_locales[10] = {-2.f,3.f};
			a->puntos_locales[11] = {0.f,2.f};
			a->puntos_locales[12] = {2.f,3.f};
		break;
		
	}
	
	a->tipo = randAsteroid;
	a->size = size;
	a->pos = {(float)(rand()%700 + 50),(float)(rand()%500 + 50)};
	a->v ={(float)(rand()%21 - 10), (float)(rand()%21 - 10)};
	a->v = Vec2xScalar(Vec2Normalized(a->v),3);
}

void Draw_asteroid(asteroid *a){
	esat::Mat3 t = esat::Mat3Scale(a->size,a->size);
	t = esat::Mat3Multiply(esat::Mat3Translate(a->pos.x,a->pos.y),t);
	
	for (int i=0;i<a->vertices;i++){
		a->puntos_globales[i] = esat::Mat3TransformVec2(t,a->puntos_locales[i]);
	}
	
	esat::DrawPath(&(a->puntos_globales[0].x),a->vertices);
}

void UpdatePos(asteroid *a){
	a->pos = Vec2plusVec2(a->pos,a->v);
	if(a->pos.x<0)
		a->pos.x = 800 + a->pos.x;
	if(a->pos.y<0)
		a->pos.y = 600 + a->pos.y;
	a->pos.x = (int)a->pos.x%800;
	a->pos.y = (int)a->pos.y%600;	
}

