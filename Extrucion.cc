#include <esat/window.h>
#include <esat/draw.h>
#include <esat/input.h>
#include <esat/time.h>
#include <esat/math.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>


#define PI 3.14159265

struct Surface3D{
	esat::Vec3 *path;
	int num_dots;
	int num_divisions;
};

void Surface3DAlloc(Surface3D *t, int d, int n){
	t->path = (esat::Vec3*)malloc(sizeof(esat::Vec3)*((d+1)*n));
	t->num_dots = n;
	t->num_divisions = d;	
}

void Surface3DExtrusion(Surface3D *t, esat::Vec2 *shape, float h, int d, int n){
	
	Surface3DAlloc(t,d,n);
	
	for(int i=0;i<(d+1);i++){
		for(int j=0;j<n;j++){
			t->path[j+i*(d+1)] = {shape[j].x,shape[j].y,(float)((h/d)*i)}; 
		}
	}
}

void Surface3DFree(Surface3D *t){
	free(t->path);
	t->path = NULL;
	t->num_dots = 0;
	t->num_divisions = 0;
}

void Surface3DDraw(const Surface3D *t, esat::Mat4 m){
	
	esat::Vec3 *aux = (esat::Vec3*)malloc(sizeof(esat::Vec3)*((t->num_divisions+1)*t->num_dots));
	
	for(int i=0;i<(t->num_divisions+1)*t->num_dots;i++)
		aux[i] = esat::Mat4TransformVec3(m,t->path[i]);
	
	printf("hola3");
	
	for(int i=0;i<(t->num_divisions+1);i++){
		for(int j=0;j<t->num_dots;j++){
			esat::DrawLine(aux[j+i*(t->num_divisions+1)].x,aux[j+i*(t->num_divisions+1)].y,
							aux[((j+1)%t->num_dots)+i*(t->num_divisions+1)].x,aux[(j+1)+i*(t->num_divisions+1)].y);
		}
	}
	printf("hola4");
}

	
int esat::main(int argc, char **argv) {
	
	Surface3D a;
	esat::Vec2 s[4] = {
		{1.f,1.f},
		{1.f,-1.f},
		{-1.f,-1.f},
		{-1.f,1.f},		
	};
	
	printf("hola1");
	Surface3DExtrusion(&a,s,40,5,4);
	
	
	esat::Mat4 m;
	
	m = esat::Mat4Projection();
	m = esat::Mat4Multiply(esat::Mat4Translate(esat::MousePositionX(),esat::MousePositionY(),0.f),m);

	printf("hola2");
	double current_time,last_time; 		//tiempo que dura la musica inicial + tiempo actual
	unsigned int fps=60;
	esat::WindowInit(800,600);
	
	
	WindowSetMouseVisibility(true);
	

	while(esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)) {
		last_time = esat::Time();
		esat::DrawBegin();
	    esat::DrawClear(0,0,0);
		esat::DrawSetStrokeColor(255,255,255);
		
		Surface3DDraw(&a,m);
		

		
		esat::DrawEnd();
		do{
	   	 	current_time = esat::Time();
	    }while((current_time-last_time)<=1000.0/fps);
	    esat::WindowFrame();
	}
	
	Surface3DFree(&a);
	
	return 0;
}
