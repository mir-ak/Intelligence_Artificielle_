#include "../include/Game.h"
#include "../include/Rand.h"
#include <csignal>
#include <cstring>
#include <cstdio>
#include <pthread.h>
#include <unistd.h>
#define SPEED 500000
#define PLATEAU_SIZE (30*30*sizeof(int))
#define CUBE_SIZE (4*4*sizeof(int))

pthread_mutex_t	mutex_lock;

int num = 0;


static Rand r;
//fonction qui permet d'afficher les prochains cubes a choisir
void Game::printNextCube(Forme* Cube,int step)
{
	int x,y;
	int i,j;
	Position p;
	Plan f;   

	p.save_position();
	p.place_cordonnee(4,37);
	cout<<"next : ";
	p.res_position();

	p.place_cordonnee(10,40);
	cout<<"1";
	p.res_position();
	p.place_cordonnee(10,46);
	cout<<"2";
	p.res_position();
	p.place_cordonnee(10,52);
	cout<<"3";
	p.res_position();

	int a[4][4] = {0};
	Cube->getLocate(&x,&y);
	memcpy(a,Cube->getArray(),CUBE_SIZE);
	for(i = 0; i < 4; i++)
		for(j = 0; j < 4; j++)
		{
			f.setPlan(i+6,j+40 + step);
			f.setColor(CLEAR);
			f.printPoint();
			f.setPlan(i+5+x,j+40 + step);
			if(a[i][j] == 1)
			{
				f.setColor(Cube->getColor());
				f.printPoint();
			}
		}
}

//fonction qyu affiches les touches pour déplacé les cubes
void Game::print_touche()
{
	Position p;
	p.save_position();
	p.place_cordonnee(12,38);
	cout<<"q: vas a gauche " << endl;
	p.res_position();
	p.save_position();
	p.place_cordonnee(13,38);
	cout<<"d: vas a droite" << endl;
	p.res_position();
	p.save_position();
	p.place_cordonnee(14,38);
	cout<<"a: rotation" << endl;
	p.res_position();
	p.save_position();
	p.place_cordonnee(15,38);
	cout<<"s: descends " << endl;
	p.res_position();
	p.save_position();
	p.place_cordonnee(16,38);
	cout<<"z: pause " << endl;
	p.res_position();
}


//fonction qui initialise la partie 
void Game::gameInit()
{
	int choix ;
	print_touche();
	for (int i = 0; i < 1000; ++i)
	{
		form[i] = getCube();
	}
	nextCube = new Forme(form[indexform++]);
	nextCube->draw_cube();
	nextCube->setLocate(1,14);

	createCube();
}

START Game::getStart()
{
	return start;
}
void Game::setStart( START start )
{
	this->start = start;
}

Game::~Game()
{
	if( NULL != n_cube )
	{
		delete n_cube;
		n_cube = NULL;
	}

	if( NULL != nextCube )
	{
		delete nextCube;
		nextCube = NULL;
	}
}



//fonction qui permets de choisir la forme du plateau (taille par defaut)
Game::Game(int a)
{
	v = a ; 
	n_cube = NULL;
	Plan f;
	Position p;
	int i,j,k,l;
	
	cout<<"\t\t\t\t\t\t\t-----------------"<<endl;
	cout<<"\t\t\t\t\t\t\t    bienvenue    "<<endl;
	cout<<"\t\t\t\t\t\t\t-----------------"<<endl;
	
	s.printSecor();
	
	start = GAME_RUN;
	memset((void*)plateau,0,PLATEAU_SIZE); 
	memset((void*)pl_color,0,PLATEAU_SIZE);

	//rectangle 
	if(v > 15){
	for(l=0,i =0; i < 30; i++,l++)
	{
		f.setPlan(i,5);
		f.setColor(BLUE);
		f.printPoint();
		f.setPlan(i,30);
		f.setColor(BLUE);
		f.printPoint();
		plateau[i][0] = 1;
		plateau[i][25] = 1;
	}

	for(i = 0; i < 26; i++)
	{
		f.setPlan(29,5+i);
		f.setColor(BLUE);
		f.printPoint();
		f.setPlan(0,5+i);
		f.setColor(BLUE);
		f.printPoint();
		plateau[0][i] = 1;
		plateau[29][i] = 1;
	}
 }
 //triangle 
else{
 	if (v <= 5)
 	{
		for(k=16,j =13,l=0;l<11 ,i< 15; l--, i++,j--,k++)
		{
			
			plateau[i][j] = 1;
			copie_plateau_t[i][j]=1;
			
			plateau[i][k] = 1;
			copie_plateau_t[i][k]=1;
			
			plateau[i][29] = 1;
			copie_plateau_t[i][29]=1;
			
			plateau[i-2][28] = 1;
			copie_plateau_t[i-2][28]=1;
			
			plateau[i][0] = 1;
			copie_plateau_t[i][0]=1;
		}

		for(i = 0;i < 28; i++)
		{
			if(i < 12 || i >16){
				plateau[1][i]=1;
				copie_plateau_t[1][i]=1;
			}
			if(i < 11 || i >17){
				plateau[2][i]=1;
				copie_plateau_t[2][i]=1;
			}
			if(i < 10 || i >18){
				plateau[3][i]=1;
				copie_plateau_t[3][i]=1;
			}
			if(i < 9 || i >19){
				plateau[4][i]=1;
				copie_plateau_t[4][i]=1;
			}
			if(i < 8 || i >20){
				plateau[5][i]=1;
				copie_plateau_t[5][i]=1;
			}
			if(i < 7 || i >21 ){
				plateau[6][i]=1;
				copie_plateau_t[6][i]=1;
			}
			if(i < 6 || i > 22){
				plateau[7][i]=1;
				copie_plateau_t[7][i]=1;
			}
			if(i < 5 || i >23 ){
				plateau[8][i]=1;
				copie_plateau_t[8][i]=1;
			}
			if(i < 4 || i >24 ){
				plateau[9][i]=1;
				copie_plateau_t[9][i]=1;
			}
			if(i < 3 || i >25 ){
				plateau[10][i]=1;
				copie_plateau_t[10][i]=1;
			}
			if(i < 2 || i >26 ){
				plateau[11][i]=1;
				copie_plateau_t[11][i]=1;
			}
			f.setPlan(14,5+i);
			f.setColor(GREEN);
			f.printPoint();

			f.setPlan(11,32);
			f.setColor(GREEN);
			f.printPoint();

			f.setPlan(12,33);
			f.setColor(GREEN);
			f.printPoint();

			f.setPlan(13,34);
			f.setColor(GREEN);
			f.printPoint();
			
			f.setPlan(14,4);
			f.setColor(CLEAR);
			f.printPoint();

			f.setPlan(14,6+i+1);
			f.setColor(GREEN);
			f.printPoint();
			
			if (i > 15)
			{
				f.setPlan(-17+i,4+i);
				f.setColor(GREEN);
				f.printPoint();
			}
			else{
				f.setPlan(14-i,4+i);
				f.setColor(GREEN);
				f.printPoint();	
			}

			plateau[0][i] = 1;
			copie_plateau_t[0][i]=1;
			plateau[14][i+1] = 1;
			copie_plateau_t[14][i+1]=1;
		}
	}

//losange	
	if (v >=6 && v <= 10 )
	{
		for(k=16,j = 13 , i =0; i < 29; i++,j--,k++)
		{
			plateau[i][j] = 1;
			copie_plateau_l[i][j]=1;
			plateau[i][k] = 1;
			copie_plateau_l[i][k]=1;
			plateau[i][0] = 1;
			copie_plateau_l[i][0]=1;
			plateau[i][29] = 1;
			copie_plateau_l[i][29]=1;
			plateau[0][i] = 1;
			copie_plateau_l[0][i]=1;
			plateau[28][i] = 1;
			copie_plateau_l[28][i]=1;
			plateau[27][i] = 1;
			copie_plateau_l[27][i]=1;

			if(i < 12 || i >17){
				plateau[1][i]=1;
				copie_plateau_l[1][i]=1;
				
			}
			
			if(i < 11 || i >18){
				plateau[2][i]=1;
				plateau[24][i]=1;
				copie_plateau_l[2][i]=1;
				copie_plateau_l[24][i]=1;
			}
			if(i < 10 || i >19){
				plateau[3][i]=1;
				plateau[23][i]=1;
				copie_plateau_l[3][i]=1;
				copie_plateau_l[23][i]=1;
			}
			if(i < 9 || i >20){
				plateau[4][i]=1;
				plateau[22][i]=1;
				copie_plateau_l[4][i]=1;
				copie_plateau_l[22][i]=1;
			}
			if(i < 8 || i >21){
				plateau[5][i]=1;
				plateau[21][i]=1;
				copie_plateau_l[5][i]=1;
				copie_plateau_l[21][i]=1;
			}
			if(i < 7 || i >22 ){
				plateau[6][i]=1;
				plateau[20][i]=1;
				copie_plateau_l[6][i]=1;
				copie_plateau_l[20][i]=1;
			}
			if(i < 6 || i > 23){
				plateau[7][i]=1;
				plateau[19][i]=1;
				copie_plateau_l[7][i]=1;
				copie_plateau_l[19][i]=1;
			}
			if(i < 5 || i >24 ){
				plateau[8][i]=1;
				plateau[18][i]=1;
				copie_plateau_l[8][i]=1;
				copie_plateau_l[18][i]=1;
			}
			if(i < 4 || i >25 ){
				plateau[9][i]=1;
				plateau[17][i]=1;
				copie_plateau_l[9][i]=1;
				copie_plateau_l[17][i]=1;
			}
			if(i < 3 || i >26 ){
				plateau[10][i]=1;
				plateau[16][i]=1;
				copie_plateau_l[10][i]=1;
				copie_plateau_l[16][i]=1;
			}
			if(i < 2 || i >27 ){
				plateau[11][i]=1;
				plateau[15][i]=1;
				copie_plateau_l[11][i]=1;
				copie_plateau_l[15][i]=1;
			}	

			if (i<13|| i > 16)
			{
				plateau[26][i]=1;
				copie_plateau_l[26][i]=1;
			}
			if (i<12|| i > 17)
			{
				plateau[25][i]=1;
				copie_plateau_l[25][i]=1;
			}
			
		}
		for(j=14 ,i =1 ; i < 15 ; i++,j++)
		{
			plateau[j][i] = 1;
			copie_plateau_l[j][i]=1;
			f.setPlan(i-3,i+18);
			f.setColor(RED);
			f.printPoint();
			
			
			f.setPlan(27-i,i+20);
			f.setColor(RED);
			f.printPoint();
			f.setPlan(13+i,i+5);
			f.setColor(RED);
			f.printPoint();

			f.setPlan(13,5);
			f.setColor(RED);
			f.printPoint();

			f.setPlan(27,20);
			f.setColor(RED);
			f.printPoint();

			f.setPlan(12,33);
			f.setColor(RED);
			f.printPoint();
			
			f.setPlan(13-i,i+5);
			f.setColor(RED);
			f.printPoint();	

		}

	}


	// cercle 
	if (v >= 11 && v <= 15)
	{

	
		for(i =0; i < 25; i++)
		{

			plateau[i][0] = 1;
			plateau[i][25] = 1;
			
			plateau[1][6] = 1;
			plateau[2][5] = 1;
			plateau[3][4] = 1;
			plateau[4][3] = 1;
			plateau[5][2] = 1;
			plateau[6][1] = 1;
			plateau[1][19] = 1;
			plateau[2][20] = 1;
			plateau[3][21] = 1;
			plateau[4][22] = 1;
			plateau[5][23] = 1;
			plateau[6][24] = 1;

			if(i <6 || i>18 ){
				plateau[1][i]=1;
				plateau[23][i]=1;	
			}

			if(i < 5 || i>19 ){	
				plateau[2][i]=1;
				plateau[22][i]=1;
			}
			if(i <4 || i>20 ){	
				plateau[3][i]=1;
				plateau[21][i]=1;
			}
			if(i <3 || i > 21 ){	
				plateau[4][i]=1;
				plateau[20][i]=1;
			}
			if(i < 2 || i > 22 ){	
				plateau[5][i]=1;
				plateau[19][i]=1;
				}
			
			f.setPlan(6+i/2,5);
			f.setColor(BLUE);
			f.printPoint();
			f.setPlan(6+i/2,30);
			f.setColor(BLUE);
			f.printPoint();
			f.setPlan(6,5);
			f.setColor(CLEAR);
			f.printPoint();
			f.setPlan(1,11);
			f.setColor(BLUE);
			f.printPoint();
			f.setPlan(2,10);
			f.setColor(BLUE);
			f.printPoint();
			f.setPlan(3,9);
			f.setColor(BLUE);
			f.printPoint();
			f.setPlan(4,8);
			f.setColor(BLUE);
			f.printPoint();
			f.setPlan(5,7);
			f.setColor(BLUE);
			f.printPoint();
			f.setPlan(6,6);
			f.setColor(BLUE);
			f.printPoint();
			f.setPlan(6,30);
			f.setColor(CLEAR);
			f.printPoint();
			f.setPlan(1,24);
			f.setColor(BLUE);
			f.printPoint();
			f.setPlan(2,25);
			f.setColor(BLUE);
			f.printPoint();
			f.setPlan(3,26);
			f.setColor(BLUE);
			f.printPoint();
			f.setPlan(4,27);
			f.setColor(BLUE);
			f.printPoint();
			f.setPlan(5,28);
			f.setColor(BLUE);
			f.printPoint();
			f.setPlan(6,29);
			f.setColor(BLUE);
			f.printPoint();
			f.setPlan(18,30);
			f.setColor(CLEAR);
			f.printPoint();
			
		}

		for(i = 0; i < 24; i++)
		{
			f.setPlan(24,12+i/2);
			f.setColor(BLUE);
			f.printPoint();
			f.setPlan(0,12+i/2);
			f.setColor(BLUE);
			f.printPoint();
			plateau[0][i] = 1;
			plateau[24][i] = 1;
			
			
			plateau[18][1] = 1;
			plateau[19][2] = 1;
			plateau[20][3] = 1;
			plateau[21][4] = 1;
			plateau[22][5] = 1;
			plateau[23][6] = 1;
			
			f.setPlan(18,5);
			f.setColor(CLEAR);
			f.printPoint();

			f.setPlan(18,6);
			f.setColor(BLUE);
			f.printPoint();
			f.setPlan(19,7);
			f.setColor(BLUE);
			f.printPoint();
			f.setPlan(20,8);
			f.setColor(BLUE);
			f.printPoint();
			f.setPlan(21,9);
			f.setColor(BLUE);
			f.printPoint();
			f.setPlan(22,10);
			f.setColor(BLUE);
			f.printPoint();
			f.setPlan(23,11);
			f.setColor(BLUE);
			f.printPoint();
		
			plateau[18][24] = 1;
			plateau[19][23] = 1;
			plateau[20][22] = 1;
			plateau[21][21] = 1;
			plateau[22][20] = 1;
			plateau[23][19] = 1;
			f.setPlan(18,29);
			f.setColor(BLUE);
			f.printPoint();
			f.setPlan(19,28);
			f.setColor(BLUE);
			f.printPoint();
			f.setPlan(20,27);
			f.setColor(BLUE);
			f.printPoint();
			f.setPlan(21,26);
			f.setColor(BLUE);
			f.printPoint();
			f.setPlan(22,25);
			f.setColor(BLUE);
			f.printPoint();
			f.setPlan(23,24);
			f.setColor(BLUE);
			f.printPoint();
		}	
	}
 
}
	fflush(stdout);
	printId(v);
}
 void Game::printId(int a)
{
	Position c;
	char t[]={'A','B','C','D','E','F','G','H','I','G','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','@','$','#','&'};
	char d[]={'a','b','c','d','e','f','g','h','i','g','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','@','$','#','&'};
		if(a <= 5){
			for (int i = 0; i <30 ;++i)
			{
			c.save_position();
			c.place_cordonnee(15,i+5);
			cout<<t[i]<< endl;
			c.res_position();
			}
			for (int i = 0; i < 15;++i)
			{
			c.save_position();
			c.place_cordonnee(0+i,4);
			cout<<d[i]<< endl;
			c.res_position();
			}
		}

		if(a >=6 && a <= 10 ){
			for (int i = 0; i <29 ;++i)
			{
			c.place_cordonnee(28,i+6);
			cout<<t[i]<< endl;
			c.res_position();
			}
			for (int i = 0; i < 28;++i)
			{
			c.place_cordonnee(i,3);
			cout<<d[i]<< endl;
			c.res_position();
			}
		}

		if(a >=11 && a <= 15 ){
			for (int i = 0; i <25 ;++i)
			{			
			c.place_cordonnee(25,i+6);
			cout<<t[i]<< endl;
			c.res_position();			
			}
			for (int i = 0; i < 25;++i)
			{			
			c.place_cordonnee(i,4);
			cout<<d[i]<< endl;
			c.res_position();			
			}
		}


		if(a >15 ){
			for (int i = 0; i <26 ;++i)
			{			
			c.place_cordonnee(31,i+5);
			cout<<t[i]<< endl;
			c.res_position();			
			}
			for (int i = 0; i < 30;++i)
			{
			c.place_cordonnee(i,3);
			cout<<d[i]<< endl;
			c.res_position();			 
			}
		}
	
}

//fonction qui permet de recuperer de façon random les differentes formes 
char Game::getCube()
{
	char ch;
//rectangle
	if (v > 15)
	{
		switch(r.randNum(1,26))
		{
			case 1:ch = 'Z';break;
			case 2:ch = 'S';break;
			case 3:ch = 'T';break;
			case 4:ch = 'O';break;
			case 5:ch = 'I';break;
			case 6:ch = 'L';break;
			case 7:ch = 'J';break;
			case 8:ch =	'z';break;
			case 9:ch =	'N';break;
			case 10:ch ='i';break;
			case 11:ch ='R';break;
			case 12:ch ='t';break;
			case 13:ch ='c';break;
			case 14:ch ='u';break;
			case 15:ch ='P';break;
			case 16:ch ='g';break;
			case 17:ch ='l';break;
			case 18:ch ='G';break;
			case 19:ch ='Q';break;
			case 20:ch ='Y';break;
			case 21:ch ='C';break;
			case 22:ch ='H';break;
			case 23:ch ='A';break;
			case 24:ch ='U';break;
			case 25:ch ='B';break;	
			default:
				   cout<<"pas ce type de forme"<<endl;
				   ch = '\0';
				   break;
		}
	}
//triangle 
	if (v <= 5)
	{
		switch(r.randNum(1,14))
		{
		case 1:ch = 'Z';break;
		case 2:ch = 'S';break;
		case 3:ch = 'T';break;
		case 4:ch = 'O';break;
		case 5:ch = 'I';break;
		case 6:ch = 'L';break;
		case 7:ch = 'J';break;
		case 8:ch =	'z';break;
		case 9:ch =	'N';break;
		case 10:ch ='V';break;
		case 11:ch ='i';break;
		case 12:ch ='R';break;
		case 13:ch ='t';break;
		default:
			   cout<<"pas ce type de forme"<<endl;
			   ch = '\0';
			   break;
		}
	}
//losange
	if (v >= 6 && v <= 10 ){
		switch(r.randNum(1,16))
		{
			case 1:ch = 'Z';break;
			case 2:ch = 'S';break;
			case 3:ch = 'T';break;
			case 4:ch = 'O';break;
			case 5:ch = 'I';break;
			case 6:ch = 'L';break;
			case 7:ch = 'J';break;
			case 8:ch =	'c';break;
			case 9:ch =	'u';break;
			case 10:ch ='x';break;
			case 11:ch ='W';break;
			case 12:ch ='P';break;
			case 13:ch ='v';break;
			case 14:ch ='y';break;
			case 15:ch ='g';break;
			default:
				   cout<<"pas ce type de forme"<<endl;
				   ch = '\0';
				   break;
		}
	}
// cercle 
	if (v >=11 && v <= 15 ){
		switch(r.randNum(1,18))
		{
			case 1:ch = 'Z';break;
			case 2:ch = 'S';break;
			case 3:ch = 'T';break;
			case 4:ch = 'O';break;
			case 5:ch = 'I';break;
			case 6:ch = 'L';break;
			case 7:ch = 'J';break;
			case 8:ch = 'l';break;
			case 9:ch =	'G';break;
			case 10:ch ='Q';break;
			case 11:ch ='Y';break;
			case 12:ch ='C';break;
			case 13:ch ='H';break;
			case 14:ch ='A';break;
			case 15:ch ='U';break;
			case 16:ch ='X';break;
			case 17:ch ='B';break;	
					
			default:
				   cout<<"pas ce type de forme"<<endl;
				   ch = '\0';
				   break;
		}
	}
	return ch;
}

//fonction qui vérifie si le plateau est rempli
bool Game::verifier_Plateau()
{
	int x,y;
	int i,j;
	int b[4][4] = {0};  

	n_cube->getLocate(&x,&y);
	memcpy(b,n_cube->getArray(),CUBE_SIZE);
	for(i = 1; i < 4; i++)
		for(j = 1; j < 4; j++)
		{
			if(plateau[i+x][j+y] + b[i][j] > 1)
			{
				Position p;
				p.place_cordonnee(16,15);
				cout<<endl;
			    cout << " #####     #    #     # ####### 	####### #     # ####### ######\n" ;
			    cout << "#     #   # #   ##   ## #       	#     # #     # #       #     #\n";
			    cout << "#        #   #  # # # # #       	#     # #     # #       #     #\n";
			    cout << "#  #### #     # #  #  # #####   	#     # #     # #####   ######\n";
			    cout << "#     # ####### #     # #       	#     #  #   #  #       #   #\n";
			    cout << "#     # #     # #     # #       	#     #   # #   #       #    #\n";
			    cout << " #####  #     # #     # ####### 	#######    #    ####### #     #\n";
 				p.place_cordonnee(29,6);
				system("stty icanon echo");
				exit(0);
			}
		}
	return true;
}

void Game::rempli_Plateau()
{
	int x,y;
	int i,j;
	int b[4][4] = {0};

	n_cube->getLocate(&x,&y);
	memcpy(b,n_cube->getArray(),CUBE_SIZE);
	for(i = x; i < x + 4; i++)
		for(j = y; j < y + 4; j++)
		{
			plateau[i][j] += b[i-x][j-y];
			if(b[i-x][j-y] == 1)
				pl_color[i][j] = n_cube->getColor();
		}

	delete n_cube;
	n_cube = NULL;
	createCube();
}


	void Game::setChoix(char choix){
		this->choix = choix ; 
	}
// choisir forme avec une touche de clavier clique 
// d'aborde sur la touche D pouis le num de la forme voulu
void Game::choisir(void){

	int a=1;
	char key;
	while(a==1){
		fflush (stdout);
		choix = getchar();
		switch(choix)
		{
			case '1':
				nextCube = new Forme(form[indexform+1]);
				n_cube = nextCube;
				n_cube->printCube(YELLOW);
				nextCube->draw_cube();
				nextCube->setLocate(1,13);
				a =0;

				break;
			case '2':

				nextCube = new Forme(form[indexform+2]);
				n_cube = nextCube;
				n_cube->printCube(YELLOW);
				nextCube->draw_cube();
				nextCube->setLocate(1,13);
				a =0;
				
				break;		
			case '3':
				nextCube = new Forme(form[indexform+3]);
				n_cube = nextCube;
				n_cube->printCube(YELLOW);
				nextCube->draw_cube();
				nextCube->setLocate(1,13);
				a =0;

				break;			
			default:
				break;
		}	
	}
	a=a;
	verifier_Plateau();
}
void Game::createCube()
{

	Position p ;
	n_cube = nextCube;
	int c1,c2,c3;

	c1 = indexform+1;
	nextCube = new Forme(form[c1]);
	
	nextCube->draw_cube();
	nextCube->setLocate(1,13);
	printNextCube(nextCube,0);

	c2 = indexform+2;
	nextCube = new Forme(form[c2]);
	nextCube->draw_cube();
	nextCube->setLocate(1,13);
	printNextCube(nextCube,5);


	c3 = indexform+3;
	nextCube = new Forme(form[c3]);
	nextCube->draw_cube();
	nextCube->setLocate(1,13);
	printNextCube(nextCube,10);
	choisir(); 
	indexform++;

}

//fonction qui fait appel au fonction qui gere le deplacement des formes
void Game::move(int dir)
{

	if(GAME_RUN != start)
		return;
	pthread_mutex_lock(&mutex_lock);
	switch(dir)
	{
		case DOWN:
			if(false == deplacer_bas())
			{
				
				n_cube->printCube(CLEAR);
				n_cube->move_cube(DOWN);
				n_cube->printCube(YELLOW);
			}
			else
			{
				rempli_Plateau();
				n_cube->printCube(YELLOW);
				verifier_Ligne();
			}
			break;
		case LEFT:
			if(false == deplacer_gauche())
			{
				n_cube->printCube(CLEAR);
				n_cube->move_cube(LEFT);
				n_cube->printCube(YELLOW);
			}
			break;
		case RIGHT:
			if(false == deplacer_droite())
			{
				n_cube->printCube(CLEAR);
				n_cube->move_cube(RIGHT);
				n_cube->printCube(YELLOW);
			}
			break;
		default:
			break;
	}
	pthread_mutex_unlock(&mutex_lock);
}

//fonction qui permet de faire la rotation des formes en inversant les valeurs du tableau
void Game::rotation()
{
	int x,y;
	int i,j;
	int flag = 0;
	int b[4][4] = {0};  
	int temp[4][4] = {0};

	n_cube->getLocate(&x,&y);
	memcpy(b,n_cube->getArray(),CUBE_SIZE);
	//Efface l'anienne forme
	n_cube->printCube(CLEAR);
	//Fait trouner le tableau
	if (b[3][1] == 1)
        temp[1][0] = temp[1][1] = temp[1][2] = temp[1][3] = 1;
    else if (b[1][3] == 1)
        temp[0][1] = temp[1][1] = temp[2][1] = temp[3][1] = 1;
    else
    {
        for(i = 0; i < 3; i++)
            for(j = 0; j < 3; j++)
            {
                temp[2-j][i] = b[i][j];
            }
    }
    //Verfie si la rotation touche les bords
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++)
		{
			if (temp[i][j] == 1 && plateau[x + i][y + j] == 1)   
			{
				flag = 1;
				break;
			}
		}
		if(flag == 1)
			break;
	}
	if(flag == 0)
	{
		n_cube->rotation_cube();
	}
	n_cube->printCube(YELLOW);

}
void Game::descends()
{
	if(GAME_RUN != start)
		return;
	while(false == deplacer_bas())
	{
		n_cube->printCube(CLEAR);
		n_cube->move_cube(DOWN);
		n_cube->printCube(YELLOW);
	}
}

bool Game::deplacer_bas()
{
	int i,j;
	int cube_x,cube_y;
	int b[4][4] = {0};  
	int flag = false;

	n_cube->getLocate(&cube_x,&cube_y);
	memcpy(b,n_cube->getArray(),CUBE_SIZE);

	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++)
		{
		   if (b[i][j] == 1 && plateau[i + cube_x + 1][j + cube_y] == 1)
		   {
				flag = true;
				break;
		   }
		}
		if (flag == true)
			break;
	}
	return flag;
}

bool Game::deplacer_gauche()
{
	int i,j;
	int cube_x,cube_y;
	int b[4][4] = {0};  
	int flag = false;

	n_cube->getLocate(&cube_x,&cube_y);
	memcpy(b,n_cube->getArray(),CUBE_SIZE);

	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++)
		{
		   if (b[i][j] == 1 && plateau[i + cube_x][j + cube_y - 1] == 1)
		   {
				flag = true;
				break;
		   }
		}
		if (flag == true)
			break;
	}
	return flag;

}

bool Game::deplacer_droite()
{
	int i,j;
	int cube_x,cube_y;
	int b[4][4] = {0};  
	int flag = false;

	n_cube->getLocate(&cube_x,&cube_y);
	memcpy(b,n_cube->getArray(),CUBE_SIZE);

	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++)
		{
		   if (b[i][j] == 1 && plateau[i + cube_x][j + cube_y + 1] == 1)
		   {
				flag = true;
				break;
		   }
		}
		if (flag == true)
			break;
	}
	return flag;
}

void Game::verifier_Ligne()
{
   	int i,j;
   	int flag = 0;
   	static int count = 0;
//triangle 
 	if (v <= 5){
	   for(i = 13; i > 1; i--)
	   {
			for(j = 1; j < 29; j++)
			{
				if(plateau[i][j] == 0)
				{
					flag = 1;
				}
			}
			if(flag == 0)
			{
				//ajouter les points
				count++;
				s.setScore(count);
				s.printSecor();
				//La ligne du dessus est decsendu 
				downLigne(i);
				i++;
			}
			flag = 0;
	   }
	}
// Losange 
	if (v >=6 && v <= 10 ){
		for(i = 26; i > 1; i--)
   		{
			for(j = 1; j < 29; j++)
			{
				if(plateau[i][j] == 0)
				{
					flag = 1;
				}
			}
			if(flag == 0)
			{
				//ajouter les points
				count++;
				s.setScore(count);
				s.printSecor();
				//La ligne du dessus est decsendu 
				downLigne(i);
				i++;
			}
			flag = 0;
   		}
  	}
// Cercle
	if (v >= 11 && v <= 15){
		for(i = 24; i > 0; i--)
   		{
			for(j = 1; j < 25; j++)
			{
				if(plateau[i][j] == 0)
				{
					flag = 1;
				}
			}
			if(flag == 0)
			{
				//ajouter les points
				count++;
				s.setScore(count);
				s.printSecor();
				//La ligne du dessus est decsendu 
				downLigne(i);
				i++;
			}
			flag = 0;
	   	}
	}
  //Rectangle
	if (v > 16){

		for(i = 28; i > 0; i--)
   		{
			for(j = 1; j < 24; j++)
			{
				if(plateau[i][j] == 0)
				{
					flag = 1;
				}
			}
			if(flag == 0)
			{
				//ajouter les points
				count++;
				s.setScore(count);
				s.printSecor();
				//La ligne du dessus est decsendu 
				downLigne(i);
				i++;
			}
			flag = 0;
	   	}
	}
} 


//fonction qui permet de rescendre les lignes aprés suppression d'une ligne 
void Game::downLigne(int niveau_ligne)
{
	int i,j;
	int flag = 1;
	Plan f;
	//triangle 
	if (v <= 5){
		

		for (j = 1; j < 29; ++j)
		{
			plateau[niveau_ligne][j]=copie_plateau_t[niveau_ligne][j];
		}
		for(i = niveau_ligne; i > 1; i--)
			for(j = 1; j < 29; j++){
				if(copie_plateau_t[i][j]==0 && copie_plateau_t[i-1][j]==0)
				{
					plateau[i][j] = plateau[i-1][j];
					pl_color[i][j] = pl_color[i-1][j];
				}
			}
		for(i = 1; i < 14; i++)
			for(j = 1; j < 29; j++)
			{
				if(((i == 13 ) && (j > 0 && j < 29)) ||
				   ((i == 12 ) && (j > 1 && j < 28)) ||
  				   ((i == 11 ) && (j > 2 && j < 27)) ||
				   ((i == 10 ) && (j > 3 && j < 26)) ||
				   ((i == 9 ) && (j > 4 && j < 25))  ||
				   ((i == 8 ) && (j > 5 && j < 24))  ||
				   ((i == 7 ) && (j > 6 && j < 23))  ||
				   ((i == 6 ) && (j > 7 && j < 22))  ||
				   ((i == 5 ) && (j > 8 && j < 21))  ||
				   ((i == 4 ) && (j > 9 && j < 20))  ||
				   ((i == 3 ) && (j > 10 && j < 19)) ||
				   ((i == 2 ) && (j > 11 && j < 18)) ||
				   ((i == 1 ) && (j > 12 && j < 17)))
				{
					if(plateau[i][j] == 1)
					{
						f.setPlan(i,5+j);
						f.setColor(pl_color[i][j]);
						f.printPoint();
					}
					if(plateau[i][j] == 0)
					{
						f.setPlan(i,5+j);
						f.setColor(CLEAR);
						f.printPoint();
					}
				}		
			}
	}
	// Losange ///////////////////////////////////////////////
	if (v >=6 && v <= 10 ){
		for (j = 1; j < 29; ++j)
		{
			plateau[niveau_ligne][j]=copie_plateau_l[niveau_ligne][j];
		}
		for(i = niveau_ligne; i > 1; i--) 
			for(j = 1; j < 29; j++){
				if(copie_plateau_l[i][j]==0 && copie_plateau_l[i-1][j]==0)
				{
					plateau[i][j] = plateau[i-1][j];
					pl_color[i][j] = pl_color[i-1][j];
				}
			}
			
		for(i = 1; i < 27; i++)
			for(j = 1; j < 29; j++){
				if(copie_plateau_l[i][j]==0 && copie_plateau_l[i-1][j]==0)
				{
					if(plateau[i][j] == 1){
						f.setPlan(i,5+j);
						f.setColor(pl_color[i][j]);
						f.printPoint();
					}
					if(plateau[i][j] == 0){
						f.setPlan(i,5+j);
						f.setColor(CLEAR);
						f.printPoint();
					}
				}
			}
	
	}
	//Cercle
	if (v >= 11 && v <= 15){
		int len = 25, start = 0;
		auto estDansLaZone_c = [&start, &len, &i, &j]() {
	  	return 	((i == start + 2 || i == len - 2) && (j > start + 6 && j < len - 6)) ||
	         	((i == start + 3 || i == len - 3) && (j > start + 5 && j < len - 5)) ||
        		((i == start + 4 || i == len - 4) && (j > start + 4 && j < len - 4)) ||
		        ((i == start + 5 || i == len - 5) && (j > start + 3 && j < len - 3)) ||
		        ((i == start + 6 || i == len - 6) && (j > start + 2 && j < len - 2)) ||
		        ((i == start + 7 || i == len - 7) && (j > start + 1 && j < len - 1)) ||
		        ((i >= start + 8 && i <= len - 8) && (j > start + 0 && j < len));
	    };

	for(i = niveau_ligne; i > 1; i--)
		for(j = 1; j < 25; j++){
			if(estDansLaZone_c()){
				plateau[i][j] = plateau[i-1][j];
				pl_color[i][j] = pl_color[i-1][j];
			}
		}
	for(i = 1;  i< 24 ; i++)
		for(j =1; j < 25; j++)
		{
			if(estDansLaZone_c()){
				if(plateau[i][j] == 1)
				{
					f.setPlan(i,5+j);
					f.setColor(pl_color[i][j]);
					f.printPoint();
				}
				if(plateau[i][j] == 0){
					f.setPlan(i,5+j);
					f.setColor(CLEAR);
					f.printPoint();
				}
		
			}
		}
	}
	//Rectangle
	if (v > 16){
		for(i = niveau_ligne; i > 1; i--)
			for(j = 1; j < 25; j++){
				plateau[i][j] = plateau[i-1][j];
				pl_color[i][j] = pl_color[i-1][j];
			}
				
		for(i = 1; i < 29; i++)
			for(j = 1; j < 25; j++){
				if(plateau[i][j] == 1){
					f.setPlan(i,5+j);
					f.setColor(pl_color[i][j]);
					f.printPoint();
				}
				if(plateau[i][j] == 0){
					f.setPlan(i,5+j);
					f.setColor(CLEAR);
					f.printPoint();
				}
			}
	}
}

//Les touches qui permettent de bouger les formes
void* liste_touche(void *ptr)
{
	Game* touch = (Game*)ptr;
	char key;
	while(1)
	{
		key = getchar();

		switch(key)
		{
			case 'q':
				touch->move(LEFT);break;
			case 'd':
				touch->move(RIGHT);break;
			case 'a':
				touch->rotation();break;
			case 's':
				touch->descends();break;
			case 'z':
				if(GAME_RUN == touch->getStart())
					touch->setStart(GAME_PAUSE);
				else 
					touch->setStart(GAME_RUN);
				break;
		}
	}
}
void SignalHandlerFunction (int sig)
{
	system("stty icanon echo");
	system("clear");
	fflush(stdout);
	kill(getpid(), SIGKILL);
}
void strat_jeux(int a){
	Game g = Game(a);
	pthread_t t1;
	g.gameInit();
	pthread_create(&t1,NULL,liste_touche,(void*)(&g));
	while(1)
	{
		fflush(stdout);
		usleep(SPEED);
		g.move(DOWN);
	}
}
int main()
{
	int v;
	std::cout<<"Saisissez la taille de plateau entre [5,10,15,20] : ";
	std::cin>>v;
	signal(SIGINT, SignalHandlerFunction);
	pthread_t t1;
	pthread_mutex_init(&mutex_lock, NULL);
	system("clear");
	system("stty -icanon -echo");
	strat_jeux(v);
	return 0;
}
