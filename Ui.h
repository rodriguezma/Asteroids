#include <esat/draw.h>
#include <esat/math.h>
#include "stats.h"
#include "ships.h"

void PrintUi(Stats *stats, ship *nave){
	
	esat::Vec2 *aux = (esat::Vec2*)malloc(sizeof(esat::Vec2)*6);
	
	esat::Mat3 t = esat::Mat3Scale(5,5);
	esat::Mat3 t2;
	char buffer[50];
	esat::DrawText(100,50,itoa(stats->puntuacion,buffer,10));
	
	for(int i=0; i<stats->lives; i++){
		t2 = esat::Mat3Multiply(esat::Mat3Translate(i*25 + 100,70),t);
		for(int j=0;j<6;j++){
			aux[j]=esat::Mat3TransformVec2(t2, nave->puntos_locales[j]);
		}
		esat::DrawPath(&(aux[0].x),6);
	}
}

bool Col (esat::Vec2 *v, esat::Vec2 w){
	if(w.x > v[0].x && w.x <v[1].x && w.y > v[0].y && w.y < v[3].y)
		return true;
	else 
		return false;
}

void PrintMainMenu(int *GameState){
	esat::Vec2 MousePos = {(float)esat::MousePositionX(),(float)esat::MousePositionY()};

	esat::DrawSetTextSize(50);
	esat::DrawText(300,150,"ASTEROIDS");
	
	esat::DrawSetTextSize(30);
	esat::DrawText(350,300,"LOGIN");
	esat::DrawText(330,400,"REGISTER");
	
	esat::Vec2 login[] = {{345,270},{385,270},{385,305},{345,305},{345,270}};
	esat::DrawPath(&(login[0].x),5);
	
	esat::Vec2 reg[] = {{325,370},{395,370},{395,405},{325,405},{325,370}};
	esat::DrawPath(&(reg[0].x),5);

	if(Col(login,MousePos) && esat::MouseButtonDown(0))
		*GameState = 1;

	if(Col(reg,MousePos) && esat::MouseButtonDown(0))
		*GameState = 2;
}

void PrintLoginMenu(int *GameState, bd *user){
	esat::Vec2 MousePos = {(float)esat::MousePositionX(),(float)esat::MousePositionY()};

	esat::DrawSetTextSize(30);
	esat::DrawText(300,200,"NICKNAME:");
	esat::DrawText(300,240,"PASSWORD:");
	esat::DrawText(320,400,"PLAY");
	esat::Vec2 play[]= {{315,370},{355,370},{355,400},{315,400},{315,370}};
	esat::DrawPath(&(play[0].x),5);

	if(Col(play,MousePos) && esat::MouseButtonDown(0))
		*GameState = 3;
}

void PrintRegisterMenu(int *GameState, bd *user){
	esat::Vec2 MousePos = {(float)esat::MousePositionX(),(float)esat::MousePositionY()};

	esat::DrawSetTextSize(30);
	esat::DrawText(300,200,"NICKNAME:");
	esat::DrawText(300,240,"PASSWORD:");
	esat::DrawText(300,280,"NOMBRE:");
	esat::DrawText(300,320,"APELLIDO:");
	esat::DrawText(300,360,"PAIS:");
	esat::DrawText(320,450,"PLAY");
	esat::Vec2 play[]= {{315,420},{355,420},{355,450},{315,450},{315,420}};
	esat::DrawPath(&(play[0].x),5);

	if(Col(play,MousePos) && esat::MouseButtonDown(0))
		*GameState = 3;
}

	