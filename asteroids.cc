#pragma once
#include <esat/window.h>
#include <esat/input.h>
#include <esat/time.h>
#include <esat/math.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Game.h"

#define PI 3.14159265

ship Nave;	

NodoAsteroid *asteroides = NULL;
NodoDisparo *disparos = NULL;
	
int esat::main(int argc, char **argv) {
	
	srand(time(NULL));
	
	double current_time,last_time; 		//tiempo que dura la musica inicial + tiempo actual
	unsigned int fps=60;
	esat::WindowInit(800,600);
	
	asteroides = CrearListaAsteroide();
	disparos = CrearListaDisparo();
	asteroid asteroide1;
	Init_asteroid(&asteroide1,1);
	asteroid asteroide2;
	Init_asteroid(&asteroide2,1);
	asteroid asteroide3;
	Init_asteroid(&asteroide3,1);
	printf("hola");
	InsertarLista(&asteroides,asteroide1);
	printf("hola1");
	InsertarLista(&asteroides,asteroide2);
	InsertarLista(&asteroides,asteroide3);

	
	
	InitShip(&Nave);
	WindowSetMouseVisibility(true);
	

	while(esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)) {
		last_time = esat::Time();
		esat::DrawBegin();
	    esat::DrawClear(0,0,0);
		esat::DrawSetStrokeColor(255,255,255);
		
		RotateShip(&Nave);
		UpdateVdir(&Nave);
		SpeedUp(&Nave);
		BorrarAst(&asteroides);
		Disparo(&disparos,&Nave);
		MoveDisparos(&disparos);
		MostrarLista(disparos);
		BorrarDsp(&disparos);
		
		UpdatePos(&Nave);
		MoveAsteroids(&asteroides);
		
		DrawShip(&Nave);
		MostrarLista(asteroides);
		
		esat::DrawEnd();
		do{
	   	 	current_time = esat::Time();
	    }while((current_time-last_time)<=1000.0/fps);
	    esat::WindowFrame();
	}
	
	return 0;
}
