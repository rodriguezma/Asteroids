#include <esat/math.h>
#include <esat/draw.h>
#include <esat/input.h>




struct asteroid{
	esat::Vec2 *puntos_locales;
	esat::Vec2 *puntos_globales;
	esat::Vec2 pos;
	esat::Vec2 v;

};

void Init_asteroid(asteroid *a){
	
	a->puntos_globales = (esat::Vec2*)malloc(sizeof(esat::Vec2)* 11);
	a->puntos_locales = (esat::Vec2*)malloc(sizeof(esat::Vec2)*11);
	
	a->puntos_locales[0] = {0.f,1.f};
	a->puntos_locales[1] = {1.f,2.f};
	a->puntos_locales[2] = {2.f,1.f};
	a->puntos_locales[3] = {1.5f,0.f};
	a->puntos_locales[4] = {2.f,-1.f};
	a->puntos_locales[5] = {0.f,-2.f};
	a->puntos_locales[6] = {-1.f,-2.f};
	a->puntos_locales[7] = {-2.f,-1.f};
	a->puntos_locales[8] = {-2.f,1.f};
	a->puntos_locales[9] = {-1.f,2.f};
	a->puntos_locales[10] = {0.f,1.f};

	a->pos = {(float)(rand()%700 + 50),(float)(rand()%500 + 50)};
	a->v ={(float)(rand()%21 - 10), (float)(rand()%21 - 10)};
	a->v = Vec2xScalar(Vec2Normalized(a->v),3);
}

void Draw_asteroid(asteroid *a){
	esat::Mat3 t = esat::Mat3Scale(20,20);
	t = esat::Mat3Multiply(esat::Mat3Translate(a->pos.x,a->pos.y),t);
	
	for (int i=0;i<11;i++){
		a->puntos_globales[i] = esat::Mat3TransformVec2(t,a->puntos_locales[i]);
	}
	
	esat::DrawPath(&(a->puntos_globales[0].x),11);
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

