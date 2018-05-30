#pragma once
using namespace std;

#include <iostream>
#include <string.h>
#include <esat/draw.h>
#include <esat/math.h>
#include "stats.h"
#include "ships.h"
#include "sqlite3.h"
#include "ListaAsteroids.h"

int nrows = 0;

static int callback(void *unused, int count, char **data, char **columns)
{
    int idx;

    printf("There are %d column(s)\n", count);

    for (idx = 0; idx < count; idx++) {
        printf("The data in column \"%s\" is: %s\n", columns[idx], data[idx]);
    }
	nrows++;
    printf("\n");

    return 0;
}

void PrintUi(Stats *stats, ship *nave){
	
	esat::Vec2 *aux = (esat::Vec2*)malloc(sizeof(esat::Vec2)*6);
	
	esat::Mat3 t = esat::Mat3Scale(5,5);
	esat::Mat3 t2;
	char buffer[50];
	esat::DrawText(100,50,itoa(stats->puntuacion,buffer,10));
	
	for(int i=0; i<stats->lives; i++){
		t2 = esat::Mat3Multiply(esat::Mat3Translate(i*25 + 100,70),t);
		for(int j=0;j<6;j++){
			aux[j]=esat::Mat3TransformVec2(t2, nave->puntos_locales[j]);
		}
		esat::DrawPath(&(aux[0].x),6);
	}
}

bool Col (esat::Vec2 *v, esat::Vec2 w){
	if(w.x > v[0].x && w.x <v[1].x && w.y > v[0].y && w.y < v[3].y)
		return true;
	else 
		return false;
}

void PrintMainMenu(int *GameState){
	esat::Vec2 MousePos = {(float)esat::MousePositionX(),(float)esat::MousePositionY()};

	esat::DrawSetTextSize(50);
	esat::DrawText(300,150,"ASTEROIDS");
	
	esat::DrawSetTextSize(30);
	esat::DrawText(350,300,"LOGIN");
	esat::DrawText(330,400,"REGISTER");
	
	esat::Vec2 login[] = {{345,270},{385,270},{385,305},{345,305},{345,270}};
	esat::DrawPath(&(login[0].x),5);
	
	esat::Vec2 reg[] = {{325,370},{395,370},{395,405},{325,405},{325,370}};
	esat::DrawPath(&(reg[0].x),5);

	if(Col(login,MousePos) && esat::MouseButtonDown(0))
		*GameState = 1;

	if(Col(reg,MousePos) && esat::MouseButtonDown(0))
		*GameState = 2;
}

bool CheckUser(bd *b, sqlite3 *db){
	nrows = 0;
	char *zErrMsg = 0;
   const char *cn;
   int rc;
   string sql;

	sql = "SELECT * FROM USUARIOS WHERE Nickname ='";
	sql += b->user;
	sql += "' AND Password='";
	sql += b->password;
	sql += "';"; 

	cn = sql.c_str();
	
	printf("%s\n",cn);
	
	rc = sqlite3_exec(db, cn, callback, NULL, NULL);

	if( rc != SQLITE_OK ){
		return false;
    }else {
		if(nrows > 0)
			return true;
		else 
			return false;
    }      
}

void PrintLoginMenu(int *GameState, bd *b, int *campo, sqlite3 *bd){
	esat::Vec2 MousePos = {(float)esat::MousePositionX(),(float)esat::MousePositionY()};
	esat::Vec2 play[]= {{315,370},{355,370},{355,400},{315,400},{315,370}};
		
	esat::DrawSetTextSize(30);
	esat::DrawText(300,200,"NICKNAME:");
	esat::DrawText(300,240,"PASSWORD:");
	esat::DrawText(320,400,"PLAY");
	esat::DrawText(370,200,b->user);
	esat::DrawText(370,240,b->password);

	esat::Vec2 nick[]= {{370,170},{600,170},{600,200},{370,200},{370,170}};
	esat::Vec2 pass[]= {{370,210},{600,210},{600,240},{370,240},{370,210}};

	if(Col(nick,MousePos) && esat::MouseButtonDown(0)){
		*campo = 0;
	}else if(Col(pass,MousePos) && esat::MouseButtonDown(0)){
		*campo = 1;
	}


	switch(*campo){
		case 0:
			b->user[strlen(b->user)] = esat::GetNextPressedKey();
			break;

		case 1:
			b->password[strlen(b->password)] = esat::GetNextPressedKey();
			break;
	}

	esat::DrawPath(&(nick[0].x),5);
	esat::DrawPath(&(pass[0].x),5);	

	esat::DrawPath(&(play[0].x),5);

	if(Col(play,MousePos) && esat::MouseButtonDown(0))
		if(CheckUser(b,bd))
			*GameState = 3;
}


bool InsertToDateBase(bd *b, sqlite3 *db){
   char *zErrMsg = 0;
   const char *cn;
   int rc;
   string sql;

	sql = "INSERT INTO USUARIOS (Nickname,Name,Password,Country,Subname) VALUES ('";
	sql += b->user;
	sql += "', '";
	sql += b->name;
	sql += "', '";
	sql += b->password;
	sql +="', '";
	sql += b->country;
	sql += "', '";
	sql += b->subname;
	sql += "' );"; 
	
	cn = sql.c_str();
	printf("%s\n",cn);
	
	rc = sqlite3_exec(db, cn, callback, 0, &zErrMsg);

	if( rc != SQLITE_OK ){
      	return false;
    }else {
      	return true;
    }      
}



void PrintRegisterMenu(int *GameState, bd *b, int *campo, sqlite3 *bd){
	esat::Vec2 MousePos = {(float)esat::MousePositionX(),(float)esat::MousePositionY()};

	esat::DrawSetTextSize(30);
	esat::DrawText(300,200,"NICKNAME:");
	esat::DrawText(300,240,"PASSWORD:");
	esat::DrawText(300,280,"NOMBRE:");
	esat::DrawText(300,320,"APELLIDO:");
	esat::DrawText(300,360,"PAIS:");
	esat::DrawText(320,450,"PLAY");
	esat::Vec2 play[]= {{315,420},{355,420},{355,450},{315,450},{315,420}};
	esat::DrawPath(&(play[0].x),5);

	esat::DrawText(370,200,b->user);
	esat::DrawText(370,240,b->password);
	esat::DrawText(370,280,b->name);
	esat::DrawText(370,320,b->subname);
	esat::DrawText(370,360,b->country);


	esat::Vec2 nick[]= {{370,170},{600,170},{600,200},{370,200},{370,170}};
	esat::Vec2 pass[]= {{370,210},{600,210},{600,240},{370,240},{370,210}};
	esat::Vec2 name[]= {{370,250},{600,250},{600,280},{370,280},{370,250}};
	esat::Vec2 sname[]= {{370,290},{600,290},{600,320},{370,320},{370,290}};
	esat::Vec2 cntry[]= {{370,330},{600,330},{600,360},{370,360},{370,330}};
	
	esat::DrawPath(&(nick[0].x),5);
	esat::DrawPath(&(pass[0].x),5);	
	esat::DrawPath(&(name[0].x),5);
	esat::DrawPath(&(sname[0].x),5);	
	esat::DrawPath(&(cntry[0].x),5);
	

	if(Col(nick,MousePos) && esat::MouseButtonDown(0)){
		*campo = 0;
	}else if(Col(pass,MousePos) && esat::MouseButtonDown(0)){
		*campo = 1;
	}else if(Col(name,MousePos) && esat::MouseButtonDown(0)){
		*campo = 2;
	}else if(Col(sname,MousePos) && esat::MouseButtonDown(0)){
		*campo = 3;
	}else if(Col(cntry,MousePos) && esat::MouseButtonDown(0)){
		*campo = 4;
	}


	switch(*campo){
		case 0:
			b->user[strlen(b->user)] = esat::GetNextPressedKey();
			break;
		case 1:
			b->password[strlen(b->password)] = esat::GetNextPressedKey();
			break;
		case 2:
			b->name[strlen(b->name)] = esat::GetNextPressedKey();
			break;
		case 3:
			b->subname[strlen(b->subname)] = esat::GetNextPressedKey();
			break;
		case 4:
			b->country[strlen(b->country)] = esat::GetNextPressedKey();
			break;
	}



	if(Col(play,MousePos) && esat::MouseButtonDown(0)){
		if(InsertToDateBase(b,bd))
			*GameState = 3;
	}
}

void PrintGameOverMenu(int *GameState, Stats *stats, NodoAsteroid *asteroides){
	esat::Vec2 MousePos = {(float)esat::MousePositionX(),(float)esat::MousePositionY()};
	
	esat::Vec2 mainmenu[]= {{320,370},{390,370},{390,400},{320,400},{320,370}};
	esat::Vec2 playagain[]= {{320,410},{390,410},{390,440},{320,440},{320,410}};
		
	esat::DrawSetTextSize(60);
	esat::DrawText(300,200,"GAME OVER");
	esat::DrawSetTextSize(30);
	esat::DrawText(320,400,"MAIN MENU");
	esat::DrawText(320,440,"PLAY AGAIN");
	BorrarLista(&asteroides);
	InitStats(stats);
	InitAsteroids(&asteroides);
	

	
	esat::DrawPath(&(mainmenu[0].x),5);	
	esat::DrawPath(&(playagain[0].x),5);

	if(Col(mainmenu,MousePos) && esat::MouseButtonDown(0))
		*GameState = 0;
	else if(Col(playagain,MousePos) && esat::MouseButtonDown(0)){
		*GameState = 3;
	}
		
			
}

