#include <esat/math.h>
#include <esat/draw.h>
#include <esat/input.h>
#include "Math_aux.h"

struct ship{
	esat::Vec2 puntos_locales[6] = {{0.f,3.f},{2.f,-2.f},{1.f,-1.f},{-1.f,-1.f},{-2.f,-2.f},{0.f,3.f}};
	esat::Vec2 puntos_globales[6];
	float ShipRads;
	esat::Vec2 pos;
	esat::Vec2 v_dir;
	esat::Vec2 v_force;
	float v;
	float SpeedUp;
};

void InitShip(ship *nave){
	nave->pos = {500.f,300.f};
	nave->ShipRads = 0;
	nave->v_dir = {0.f,0.f};
	nave->v = 0;
	nave->v_force = {0.f,0.f};
	nave->SpeedUp = 0;
}

void DrawShip(ship *nave){
	esat::Mat3 t = esat::Mat3Scale(5,5);
	t = esat::Mat3Multiply(t, esat::Mat3Rotate(nave->ShipRads));
	t = esat::Mat3Multiply(esat::Mat3Translate(nave->pos.x,nave->pos.y),t);
	
	for (int i=0;i<6;i++){
		nave->puntos_globales[i] = esat::Mat3TransformVec2(t,nave->puntos_locales[i]);
	}
	esat::DrawPath(&(nave->puntos_globales[0].x),6);
}

void RotateShip(ship *nave){
	if(esat::IsSpecialKeyPressed(esat::kSpecialKey_Right))
		nave->ShipRads+= 0.1;
	if(esat::IsSpecialKeyPressed(esat::kSpecialKey_Left))
		nave->ShipRads-= 0.1;
}

void SpeedUp(ship *nave){
	if(esat::IsSpecialKeyPressed(esat::kSpecialKey_Up)){
		if (SpeedUp<1){
			SpeedUp+=0.05;
		}
		nave->v_force = Vec2plusVec2(nave->v_force,Vec2xScalar(nave->v_dir,nave->SpeedUp*10));	
			
	}else{
		SpeedUp -= 0.025;
		nave->v_force = Vec2xScalar(nave->v_force,SpeedUp);
		
		
	}
		
		
}

void UpdateVdir(ship *nave){
	nave->v_dir = Vec2minusVec2(nave->puntos_globales[0],nave->pos);
	nave->v_dir = Vec2Normalized(nave->v_dir);
	
}

void UpdatePos(ship *nave){
	nave->pos = Vec2plusVec2(nave->pos,Vec2xScalar(nave->v_dir,nave->v));
}

void 



