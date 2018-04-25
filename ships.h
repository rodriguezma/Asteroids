#pragma once
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
	float friction;

};

void InitShip(ship *nave){
	nave->pos = {400.f,300.f};
	nave->ShipRads = 0.f;
	nave->v_dir = {0.f,0.f};
	nave->v = 0.f;
	nave->v_force = {0.f,0.f};
	nave->SpeedUp = 0.f;
	nave->friction = 0.f;
	
}

void DrawFire(ship *nave){
	esat::Vec2 fire[4];
	fire[0] = nave->puntos_globales[2];
	fire[1] = nave->puntos_globales[3];
	fire[2] = Vec2minusVec2(nave->pos, Vec2xScalar(nave->v_dir, 20.f));
	fire[3] = nave->puntos_globales[2];
	esat::DrawPath(&fire[0].x,4);
}

void DrawShip(ship *nave){
	
	esat::DrawPath(&(nave->puntos_globales[0].x),6);
	
	if(esat::IsSpecialKeyPressed(esat::kSpecialKey_Up)){
		DrawFire(nave);
	}
}

void RotateShip(ship *nave){
	if(esat::IsSpecialKeyPressed(esat::kSpecialKey_Right))
		nave->ShipRads+= 0.1;
	if(esat::IsSpecialKeyPressed(esat::kSpecialKey_Left))
		nave->ShipRads-= 0.1;
}

void CheckVforce(ship * nave){
	if(Module(nave->v_force)>15){
		float aux = 15/Module(nave->v_force);
		nave->v_force = Vec2xScalar(nave->v_force,aux);
	}
	nave->v = Module(nave->v_force)/15;
}

esat::Vec2 DecreseVforce(esat::Vec2 &v,float f){

		return Vec2minusVec2(v,Vec2xScalar(v,f));


}



void SpeedUp(ship *nave){
	if(esat::IsSpecialKeyPressed(esat::kSpecialKey_Up)){
		if (nave->SpeedUp<3){
			nave->SpeedUp+=0.001;
		}

		esat::Vec2 v_aux = Vec2xScalar(nave->v_dir,nave->SpeedUp + 1.f);
		nave->v_force = Vec2plusVec2(nave->v_force,v_aux);

		CheckVforce(nave);
		nave->friction = 0.0001;
	
	}else{
		nave->friction = nave->friction * 1.2;
		if(nave->friction > 1)
			nave->friction = 1;
		
		nave->v_force = DecreseVforce(nave->v_force,nave->friction);
		nave->SpeedUp = 0;
		
	}		
	
}

void UpdateVdir(ship *nave){
	nave->v_dir = Vec2minusVec2(nave->puntos_globales[0],nave->pos);
	nave->v_dir = Vec2Normalized(nave->v_dir);
	
}

void UpdatePos(ship *nave){
	
	
	nave->pos = Vec2plusVec2(nave->pos,Vec2xScalar(nave->v_force,0.7));
	if(nave->pos.x<0)
		nave->pos.x = 800 + nave->pos.x;
	if(nave->pos.y<0)
		nave->pos.y = 600 + nave->pos.y;
	nave->pos.x = (int)nave->pos.x%800;
	nave->pos.y = (int)nave->pos.y%600;	
	
	esat::Mat3 t = esat::Mat3Scale(5,5);
	t = esat::Mat3Multiply(t, esat::Mat3Rotate(nave->ShipRads));
	t = esat::Mat3Multiply(esat::Mat3Translate(nave->pos.x,nave->pos.y),t);
	
	for (int i=0;i<6;i++){
		nave->puntos_globales[i] = esat::Mat3TransformVec2(t,nave->puntos_locales[i]);
	}
}











