#pragma once

struct Stats{
	int puntuacion=0;
	int level=0;
	int lives=3;
};


struct bd{
	char user[50]="";
	char password[50]="";
	char name[50]="";
	char subname[50]="";
	char country[50]="";
	int puntuacion_maxima = 0;
};

void InitStats(Stats *player){
	player->puntuacion = 0;
	player->level = 0;
	player->lives = 3;
}

void InitBd(bd *mybd){
	bd aux;
	*mybd = aux;
}

