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
EnemyShip NaveEnemiga;
NodoAsteroid *asteroides = NULL;
NodoDisparo *disparos = NULL;
NodoDisparo *disparos_enemigos = NULL;
	
int esat::main(int argc, char **argv) {
	
	srand(time(NULL));
	
	double current_time,last_time; 		//tiempo que dura la musica inicial + tiempo actual
	unsigned int fps=60;
	esat::WindowInit(800,600);
	
	asteroides = CrearListaAsteroide();
	disparos = CrearListaDisparo();
	disparos_enemigos = CrearListaDisparo();
	asteroid asteroide1;
	Init_asteroid(&asteroide1,20);
	asteroid asteroide2;
	Init_asteroid(&asteroide2,20);
	asteroid asteroide3;
	Init_asteroid(&asteroide3,20);
	InitShip(&NaveEnemiga);
	InsertarLista(&asteroides,asteroide1);

	InsertarLista(&asteroides,asteroide2);
	InsertarLista(&asteroides,asteroide3);

	
	InitShip(&NaveEnemiga);
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
		UpdateState(&NaveEnemiga);
		UpdateDir(&NaveEnemiga);
		Disparo(&disparos,&Nave);
		Disparo(&disparos_enemigos,&NaveEnemiga,&Nave);
		MoveDisparos(&disparos);
		MoveDisparos(&disparos_enemigos);
		MoveAsteroids(&asteroides);
		UpdatePos(&Nave);
		UpdatePos(&NaveEnemiga);
		ColEnemyAsteroids(&NaveEnemiga, &asteroides);
		ColShipAsteroids(&Nave, &asteroides);
		ColShotAsteroids(&asteroides,&disparos);
		ColShotAsteroids(&asteroides,&disparos_enemigos);
		ColShipEnemy(&NaveEnemiga,&Nave);
		DeadTimeShots(&disparos);
		DeadTimeShots(&disparos_enemigos);
		
		DrawShip(&NaveEnemiga);
		MostrarLista(disparos);
		MostrarLista(disparos_enemigos);
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
