#include <esat/window.h>
#include <esat/draw.h>
#include <esat/input.h>
#include <esat/time.h>
#include <stdio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "math_aux.h"
#include <esat/math.h>

#define PI 3.14159265


int main (){
	
	esat::Vec2 v;
	v.x = 4;
	v.y = 3;

	esat::Vec2 s = RotateVec2(v,90*(PI/180),1);
	printf("%f  %f",s.x,s.y);
}