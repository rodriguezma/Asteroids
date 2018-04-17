#include <esat/window.h>
#include <esat/draw.h>
#include <esat/input.h>
#include <esat/time.h>
#include <stdio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <esat/math.h>
#include "ships.h"
#include "asteroids.h"

#define PI 3.14159265

ship Nave;	
asteroid asteroide;
	
int esat::main(int argc, char **argv) {
	
	double current_time,last_time; 		//tiempo que dura la musica inicial + tiempo actual
	unsigned int fps=60;
	esat::WindowInit(800,600);
	Init_asteroid(&asteroide);
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
		
		
		
		
		
		UpdatePos(&Nave);
		
		DrawShip(&Nave);
		Draw_asteroid(&asteroide);
		
		printf("%f,%f\n",Nave.v_force.x,Nave.v_force.y );
		
		esat::DrawEnd();
		do{
	   	 	current_time = esat::Time();
	    }while((current_time-last_time)<=1000.0/fps);
	    esat::WindowFrame();
	}
	
	return 0;
}
