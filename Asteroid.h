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
	nave->ShipRads = 0.f;
	nave->v_dir = {0.f,0.f};
	nave->v = 0.f;
	nave->v_force = {0.f,0.f};
	nave->SpeedUp = 0.f;
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
		if (nave->SpeedUp<10){
			nave->SpeedUp+=1;
		}

		esat::Vec2 v_aux = Vec2xScalar(nave->v_dir,nave->SpeedUp);

		nave->v += nave->SpeedUp;
		if(nave->v > 20)
			nave->v = 10;
		
		nave->v_force = Vec2plusVec2(nave->v_force,v_aux);	
			
	}else{
		nave->SpeedUp = 0;
		
	}
	if(nave->v>0)
	nave->v -=;	
		
}

void UpdateVdir(ship *nave){
	nave->v_dir = Vec2minusVec2(nave->puntos_globales[0],nave->pos);
	nave->v_dir = Vec2Normalized(nave->v_dir);
	
}

void UpdatePos(ship *nave){
	nave->pos = Vec2plusVec2(nave->pos,nave->v_force);
}

void CheckVforce (ship *nave){
	if(nave->v>0){
		nave->v_force = Vec2Normalized(nave->v_force);
	}
	nave->v_force = Vec2xScalar(nave->v_force,nave->v);

}





