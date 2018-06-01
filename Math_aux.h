#pragma once
#include <esat/math.h>
#include <math.h>

struct Er {float a,b,c; };
struct poly{ esat::Vec2 *points; int vertices; };

esat::Vec2 Vec2xScalar(const esat::Vec2 &v, float scalar){		//Vector por escalar
	esat::Vec2 s;
	s.x = v.x * scalar;
	s.y = v.y * scalar;
	
	return s;
}

esat::Vec2 Vec2minusVec2(const esat::Vec2 &v, const esat::Vec2 &w){		//Vector menos vector
	esat::Vec2 s;
	s.x = v.x - w.x;
	s.y = v.y - w.y; 
	
	return s;
}

esat::Vec2 Vec2plusVec2(const esat::Vec2 &v, const esat::Vec2 &w){		//Vector mas vector
	esat::Vec2 s;
	s.x = v.x + w.x;
	s.y = v.y + w.y; 
	
	return s;
}

float Module(const esat::Vec2 &v){
	return(sqrt(v.x*v.x+v.y*v.y));
}

esat::Vec2 Vec2Normalized(const esat::Vec2 &v){					//Vector normalizado
	esat::Vec2 s;
	if(Module(v)>0){
		float mod = Module(v);
		s.x = v.x/mod;
		s.y = v.y/mod;
		return s;
	}else
		return v;
	
	
	
}

Er Vec2toEr(const esat::Vec2 &v, const esat::Vec2 &w){			//Dado dos puntos, saca la ecuacion de la recta
	
	Er aux;
	
	aux.a = v.y - w.y;
	aux.b = w.x - v.x;
	aux.c = (w.y * v.x) - (v.y * w.x);
	
	return aux;
}


bool TestDotEr(esat::Vec2 v, Er r){								//Comprueba el lado al que esta un punto respecto de la recta

	if((r.a * v.x + r.b * v.y + r.c) >= 0)
		return true;
	else 
		return false;
}

bool ColVec2Poly(esat::Vec2 d,poly p){							
	
	Er Eaux;
	for(int i=0;i < p.vertices;i++){
		
		Eaux = Vec2toEr(p.points[i],p.points[i+1]);
		if(!TestDotEr(d,Eaux))
			return false;
	}
	return true;
}


