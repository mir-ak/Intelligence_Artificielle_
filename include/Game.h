#ifndef GAME_H_
#define GAME_H_
#include "Cube.h"
#include "Rand.h"
#include "Score.h"

enum START{
	GAME_STOP = -1,
	GAME_PAUSE = 0,
	GAME_RUN = 1,
};


class Game
{
private:
	int plateau[30][30];
	int copie_plateau_t[30][30];
	int copie_plateau_l[30][30];
	color pl_color[30][30];
	int x ,y ;
	START start;
	Score s;
	Forme* n_cube;
	Forme* nextCube;
	char form[1000];
	int indexform = 0,v;
private:
	bool deplacer_bas();
	bool deplacer_gauche();
	bool deplacer_droite();
	char getCube();
	void rempli_Plateau();
	bool verifier_Plateau();
public:
	char choix ;
	Game(int a);

	~Game();

	
	void createCube();
	
	void move(int dir);
	void choisir();
	void rotation();
	
	void descends();
	
	void verifier_Ligne();
	
	void downLigne(int niveau_ligne);

	void printNextCube(Forme* n_Cube,int step);
	void printId(int a);
	void gameInit();

	START getStart();
	void setStart(START);
	void setChoix(char choix);
	void print_touche();
};

#endif
