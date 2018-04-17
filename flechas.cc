#include <esat/window.h>
#include <esat/draw.h>
#include <esat/input.h>
#include <esat/time.h>
#include <esat/math.h>
#include <stdio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>



#define PI 3.14159265
	
	float rads = 0;
	
	esat::Vec2 D[]={
		{20,10},
		{15,0},
		{12,0},
		{20,16},
		{28,0},
		{25,0},
		{20,10}
	};
	
	esat::Vec2 C[]{
		{0,0},
		{1,0},
		{1,4},
		{4,7},
		{4,8},
		{3,9},
		{2,9},
		{3,8},
		{3,7},
		{0,4},
		{0,0}	
	}
	
void DrawArrows(){
	esat::Mat3 d;
	esat::Vec2 G[]={
		{0,0},
		{0,0},
		{0,0},
		{0,0},
		{0,0},
		{0,0},
		{0,0}
	};
	esat::Mat3 t = esat::Mat3Translate(-20,0);

	
	t = esat::Mat3Multiply(esat::Mat3Scale(3,3),t);
	t = esat::Mat3Multiply(esat::Mat3Translate(0,100),t);
		
	for(int i=0;i<8;i++){
		d = esat::Mat3Multiply(esat::Mat3Rotate(rads) , t);
		d = esat::Mat3Multiply(esat::Mat3Translate(esat::MousePositionX(),esat::MousePositionY()),d);
		for (int i=0;i<7;i++){
			G[i] = esat::Mat3TransformVec2(d,D[i]);
		}

		esat::DrawPath(&(G[0].x),7);
		rads += PI/4;

	}
	
	rads = 0;
	t = esat::Mat3Translate(-20,0);
	t = esat::Mat3Multiply(esat::Mat3Scale(2,2),t);
	t = esat::Mat3Multiply(esat::Mat3Translate(0,-50),t);
	
	for(int i=0;i<5;i++){
		d = esat::Mat3Multiply(esat::Mat3Rotate(rads) , t);
		d = esat::Mat3Multiply(esat::Mat3Translate(esat::MousePositionX(),esat::MousePositionY()),d);
		for (int i=0;i<7;i++){
			G[i] = esat::Mat3TransformVec2(d,D[i]);
		}

		esat::DrawPath(&(G[0].x),7);
		rads += (2*PI)/5;

	}
	
}
	
	
int esat::main(int argc, char **argv) {
	
	double current_time,last_time; 		//tiempo que dura la musica inicial + tiempo actual
	unsigned int fps=60;
	esat::WindowInit(800,600);

	WindowSetMouseVisibility(true);
	

	while(esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)) {
		last_time = esat::Time();
		esat::DrawBegin();
	    esat::DrawClear(0,0,0);
		esat::DrawSetStrokeColor(255,255,255);
		
		DrawArrows();
		
		
		esat::DrawEnd();
		do{
	   	 	current_time = esat::Time();
	    }while((current_time-last_time)<=1000.0/fps);
	    esat::WindowFrame();
	}
	
	return 0;
}
