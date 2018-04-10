#include <esat/math.h>

#include <math.h>

struct Mat2 { float d[4]; };


Mat2 RotateMat2 (float radians, int sentido){
	Mat2 aux;

	aux.d[0] = 	cos(radians);
	aux.d[3] = 	cos(radians);
	
	if(sentido == 0){
		aux.d[1] = 	-sin(radians);
		aux.d[2] = 	sin(radians);
	}else{
		aux.d[1] = 	sin(radians);
		aux.d[2] = 	-sin(radians);
	}

	return aux;		 

}

esat::Vec2 MultiplyVec2Mat2 (const esat::Vec2 &v, const Mat2 &a){
	esat::Vec2 s;

	s.x = a.d[0]*v.x + a.d[1]*v.y;
	s.y = a.d[2]*v.x + a.d[3]*v.y;

	return s;
}

esat::Vec2 RotateVec2 (const esat::Vec2 &v, float radians, int sentido){

	Mat2 s = RotateMat2 (radians,sentido);
	esat::Vec2 a = MultiplyVec2Mat2(v,s);

	return a;

}



