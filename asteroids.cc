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
#include "bbdd.h"
#include "stats.h"

#define PI 3.14159265

	Stats stats;
	ship Nave;	
	EnemyShip NaveEnemiga;
	NodoAsteroid *asteroides = NULL;
	NodoDisparo *disparos = NULL;
	NodoDisparo *disparos_enemigos = NULL;
	sqlite3 *db;
	bd user;

void GameLoop(void){
	UpdateColStatus(&Nave);
	RotateShip(&Nave);
	UpdateVdir(&Nave);
	SpeedUp(&Nave);
	UpdateDir(&NaveEnemiga);
	Disparo(&disparos,&Nave);
	Disparo(&disparos_enemigos,&NaveEnemiga,&Nave);
	MoveDisparos(&disparos);
	MoveDisparos(&disparos_enemigos);
	MoveAsteroids(&asteroides);
	UpdatePos(&Nave);
	UpdatePos(&NaveEnemiga);
	ColEnemyAsteroids(&NaveEnemiga, &asteroides);
	ColShipAsteroids(&Nave, &asteroides, &stats);
	ColShotAsteroids(&asteroides,&disparos,&stats);
	ColShotAsteroids(&asteroides,&disparos_enemigos);
	ColShipEnemy(&NaveEnemiga,&Nave,&stats);
	ColShotEnemy(&NaveEnemiga,&disparos,&stats);
	ColShotShip(&Nave,&disparos_enemigos,&stats);
	DeadTimeShots(&disparos);
	DeadTimeShots(&disparos_enemigos);
	UpdateState(&NaveEnemiga);
	DrawShip(&NaveEnemiga);
	MostrarLista(disparos);
	MostrarLista(disparos_enemigos);
	DrawShip(&Nave);
	MostrarLista(asteroides);
	PrintUi(&stats, &Nave);
}

void MainLoop(int *GameState, bd *bduser, int *campo){

	switch(*GameState){
		case 0:
			PrintMainMenu(GameState,bduser);
			break;
		case 1:
			PrintLoginMenu(GameState,bduser,campo,db);
			break;
		case 2:
			PrintRegisterMenu(GameState,bduser,campo,db);
			break;
		case 3:
			GameLoop();
			CheckDeath(GameState, &stats);
			CheckWin(GameState, asteroides);
			break;
		case 4:
			PrintGameOverMenu(GameState);
			break;
		case 6:
			InitGame(&Nave,&NaveEnemiga,&stats,&disparos, &disparos_enemigos,&asteroides);
			*GameState = 3;
			break;
		case 5:
			PrintWinMenu(GameState,&stats);
			break;			
	}	
}


int esat::main(int argc, char **argv) {
	
	int GameState = 0;
	int Campo = 0;
	
	srand(time(NULL));
	
	double current_time,last_time; 		//tiempo que dura la musica inicial + tiempo actual
	unsigned int fps=60;
	esat::WindowInit(800,600);
	
	

	sqlite3_open("asteroids.db", &db);
	
	
	WindowSetMouseVisibility(true);
	esat::DrawSetTextFont("Diner-Regular.ttf");
	esat::DrawSetTextSize(30);
	

	while(esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)) {
		last_time = esat::Time();
		esat::DrawBegin();
	    esat::DrawClear(0,0,0);
		esat::DrawSetStrokeColor(255,255,255);
		esat::DrawSetFillColor(255,255,255);
				
		MainLoop(&GameState,&user, &Campo);
		
		esat::DrawEnd();
		do{
	   	 	current_time = esat::Time();
	    }while((current_time-last_time)<=1000.0/fps);
	    esat::WindowFrame();
	}
	sqlite3_close(db);
	return 0;
}
