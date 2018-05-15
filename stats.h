struct Stats{
	int puntuacion;
	int level;
	int lives;
};

void InitStats(Stats *player){
	player->puntuacion = 0;
	player->level = 0;
	player->lives = 3;
}