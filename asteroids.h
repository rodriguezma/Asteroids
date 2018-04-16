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
	//esat::Vec2 aux[5] = {{40.f,40.f},{80.f,40.f},{80.f,80.f},{40.f,80.f},{40.f,40.f}};
	//{{0.f,1.f},{1.f,2.f},{2.f,1.f},{1.5f,0.f},{2.f,-1.f},{0.f,-2.f},{-1.f,-2.f},{-2.f,-1.f},{-2.f,1.f},{-1.f,2.f},{0.f,1.f}};
	//esat::Vec2 aux2[11] = {{0.f,0.f},{0.f,0.f},{0.f,0.f},{0.f,0.f},{0.f,0.f},{0.f,0.f},{0.f,0.f},{0.f,0.f},{0.f,0.f},{0.f,0.f},{0.f,0.f}};
	a->puntos_locales = (esat::Vec2*)malloc(sizeof(esat::Vec2)*5);
	a->puntos_locales[0].x = 40.f;
	a->puntos_locales[0].y = 40.f;
	a->puntos_locales[1].x = 40.f;
	a->puntos_locales[1].y = 40.f;
	a->puntos_locales[2].x = 40.f;
	a->puntos_locales[2].y = 40.f;
	a->puntos_locales[3].x = 40.f;
	a->puntos_locales[3].y = 40.f;
	a->puntos_locales[4].x = 40.f;
	a->puntos_locales[4].y = 40.f;
	//a->puntos_locales = aux;
	//a->puntos_globales = (esat::Vec2*)malloc(sizeof(esat::Vec2)* 11);
	//a->puntos_globales = aux2;
	a->pos = {400,400};
}

void Draw_asteroid(asteroid *a){
	/*esat::Mat3 t = esat::Mat3Translate(a->pos.x,a->pos.y);
	
	for (int i=0;i<11;i++){
		a->puntos_globales[i] = esat::Mat3TransformVec2(t,a->puntos_locales[i]);
	}
	*/
	esat::DrawPath(&(a->puntos_locales[0].x),5);
}

