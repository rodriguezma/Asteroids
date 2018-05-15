#include <esat/draw.h>
#include <esat/math.h>
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

void PrintMainMenu(){
	esat::DrawSetTextSize(50);
	esat::DrawText(300,150,"ASTEROIDS");
	esat::DrawSetTextSize(30);
	esat::DrawText(350,300,"LOGIN");
	esat::DrawSetTextSize(30);
	esat::DrawText(330,400,"REGISTER");
	esat::Vec2 login[] = {{345,270},{385,270},{385,305},{345,305},{345,270}};
	esat::DrawPath(&(login[0].x),5);
	
	esat::Vec2 reg[] = {{325,370},{395,370},{395,405},{325,405},{325,370}};
	esat::DrawPath(&(reg[0].x),5);
}

bool Col (esat::Vec2 *v, esat::Vec2 w){
	if(w.x > v[0].x && w.x <v[1].x && w.y > v[0].y && w.y < v[3].y)
		return true;
	else 
		return false;
}

void DetectColMenu(int *GameState){
	
	esat::Vec2 login[] = {{345,270},{385,270},{385,305},{345,305},{345,270}};
	esat::Vec2 reg[] = {{325,370},{395,370},{395,405},{325,405},{325,370}};
	
	esat::Vec2 MousePos = {esat::MousePositionX(),esat::MousePositionY()};
	
	if(Col(&login,MousePos) && esat::MouseButtonDown(0))
		*GameState = 1;
		
	
}


	