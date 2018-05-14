struct Stats{
	int puntuacion = 0;
	int level = 0;
};

void InitStats(Stats *player){
	player->puntuacion = 0;
	player->level = 0;
}