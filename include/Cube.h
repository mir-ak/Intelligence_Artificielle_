#ifndef CUBE_H_
#define CUBE_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Plan.h"
#define DOWN 0
#define LEFT 1
#define RIGHT 2

using namespace std;

class Cube{
protected:
	int x;
	int y;	
	int a[4][4];
public:
	Cube(){
		int i,j;
		x = 0;
		y = 0;
		for(j = 0; j < 4; j++)
		for(i = 0; i < 4; i++)
		a[i][j] = 0;
	}
	int move (int dir);
	virtual int rotation();
	virtual void draw(){}
	virtual void setLocate(int a,int b){x = a;y = b;}
	void getLocate(int* a,int* b){*a = x;*b = y;}
	void printCube(int color);
	void* getArray(){return (void*)a;}
};

class Zcube : public Cube{
public:
	void draw(){
		a[0][0] = 1;
		a[0][1] = 1;
		a[0][2] = 0;
		a[0][3] = 0;
		a[1][0] = 0;
		a[1][1] = 1;
		a[1][2] = 1;
		a[1][3] = 0;
		a[2][0] = 0;
		a[2][1] = 0;
		a[2][2] = 0;
		a[2][3] = 0;
		a[3][0] = 0;
		a[3][1] = 0;
		a[3][2] = 0;
		a[3][3] = 0;
	}
};

class Scube : public Cube{
public:
	void draw(){
		a[0][0] = 0;
		a[0][1] = 1;
		a[0][2] = 1;
		a[0][3] = 0;
		a[1][0] = 1;
		a[1][1] = 1;
		a[1][2] = 0;
		a[1][3] = 0;
		a[2][0] = 0;
		a[2][1] = 0;
		a[2][2] = 0;
		a[2][3] = 0;
		a[3][0] = 0;
		a[3][1] = 0;
		a[3][2] = 0;
		a[3][3] = 0;
	}
};

class Tcube : public Cube{
public:
	void setLocate(int a,int b){x = --a;y = b;}
	void draw(){
		a[0][0] = 0;
		a[0][1] = 0;
		a[0][2] = 0;
		a[0][3] = 0;
		a[1][0] = 1;
		a[1][1] = 1;
		a[1][2] = 1;
		a[1][3] = 0;
		a[2][0] = 0;
		a[2][1] = 1;
		a[2][2] = 0;
		a[2][3] = 0;
		a[3][0] = 0;
		a[3][1] = 0;
		a[3][2] = 0;
		a[3][3] = 0;
	}
};

class Ocube : public Cube{
public:
	void draw(){
		a[0][0] = 1;
		a[0][1] = 1;
		a[0][2] = 0;
		a[0][3] = 0;
		a[1][0] = 1;
		a[1][1] = 1;
		a[1][2] = 0;
		a[1][3] = 0;
		a[2][0] = 0;
		a[2][1] = 0;
		a[2][2] = 0;
		a[2][3] = 0;
		a[3][0] = 0;
		a[3][1] = 0;
		a[3][2] = 0;
		a[3][3] = 0;
	}
	virtual int rotation(){}
};

class Icube : public Cube{
public:
	void draw(){
		a[0][0] = 0;
		a[0][1] = 1;
		a[0][2] = 0;
		a[0][3] = 0;
		a[1][0] = 0;
		a[1][1] = 1;
		a[1][2] = 0;
		a[1][3] = 0;
		a[2][0] = 0;
		a[2][1] = 1;
		a[2][2] = 0;
		a[2][3] = 0;
		a[3][0] = 0;
		a[3][1] = 1;
		a[3][2] = 0;
		a[3][3] = 0;
	}
	virtual int rotation();
};

class Lcube : public Cube{
public:
	void draw(){
		a[0][0] = 0;
		a[0][1] = 1;
		a[0][2] = 0;
		a[0][3] = 0;
		a[1][0] = 0;
		a[1][1] = 1;
		a[1][2] = 0;
		a[1][3] = 0;
		a[2][0] = 0;
		a[2][1] = 1;
		a[2][2] = 1;
		a[2][3] = 0;
		a[3][0] = 0;
		a[3][1] = 0;
		a[3][2] = 0;
		a[3][3] = 0;
	}
};

class Jcube : public Cube{
public:
	void draw(){
		a[0][0] = 0;
		a[0][1] = 1;
		a[0][2] = 0;
		a[0][3] = 0;
		a[1][0] = 0;
		a[1][1] = 1;
		a[1][2] = 0;
		a[1][3] = 0;
		a[2][0] = 1;
		a[2][1] = 1;
		a[2][2] = 0;
		a[2][3] = 0;
		a[3][0] = 0;
		a[3][1] = 0;
		a[3][2] = 0;
		a[3][3] = 0;
	}
};
//Triangle
class ZTriangle : public Cube{
public:
	void draw(){
		a[0][0] = 1;
		a[0][1] = 0;
		a[0][2] = 0;
		a[0][3] = 0;
		a[1][0] = 1;
		a[1][1] = 1;
		a[1][2] = 1;
		a[1][3] = 0;
		a[2][0] = 0;
		a[2][1] = 0;
		a[2][2] = 1;
		a[2][3] = 0;
		a[3][0] = 0;
		a[3][1] = 0;
		a[3][2] = 0;
		a[3][3] = 0;
	}
};



class NTriangle : public Cube{
public:
	void draw(){
		a[0][0] = 1;
		a[0][1] = 1;
		a[0][2] = 0;
		a[0][3] = 0;
		a[1][0] = 0;
		a[1][1] = 1;
		a[1][2] = 0;
		a[1][3] = 0;
		a[2][0] = 0;
		a[2][1] = 1;
		a[2][2] = 1;
		a[2][3] = 0;
		a[3][0] = 0;
		a[3][1] = 0;
		a[3][2] = 0;
		a[3][3] = 0;
	}
};


class VTriangle : public Cube{
public:
	void draw(){
		a[0][0] = 0;
		a[0][1] = 0;
		a[0][2] = 1;
		a[0][3] = 0;
		a[1][0] = 0;
		a[1][1] = 1;
		a[1][2] = 0;
		a[1][3] = 0;
		a[2][0] = 1;
		a[2][1] = 0;
		a[2][2] = 0;
		a[2][3] = 0;
		a[3][0] = 0;
		a[3][1] = 0;
		a[3][2] = 0;
		a[3][3] = 0;
	}
};




class ITriangle : public Cube{
public:
	void draw(){
		a[0][0] = 0;
		a[0][1] = 1;
		a[0][2] = 0;
		a[0][3] = 0;
		a[1][0] = 0;
		a[1][1] = 1;
		a[1][2] = 0;
		a[1][3] = 0;
		a[2][0] = 0;
		a[2][1] = 1;
		a[2][2] = 0;
		a[2][3] = 0;
		a[3][0] = 0;
		a[3][1] = 0;
		a[3][2] = 0;
		a[3][3] = 0;
	}
};



class TTriangle : public Cube{
public:
	void draw(){
		a[0][0] = 0;
		a[0][1] = 1;
		a[0][2] = 0;
		a[0][3] = 0;
		a[1][0] = 0;
		a[1][1] = 1;
		a[1][2] = 0;
		a[1][3] = 0;
		a[2][0] = 0;
		a[2][1] = 0;
		a[2][2] = 0;
		a[2][3] = 0;
		a[3][0] = 0;
		a[3][1] = 0;
		a[3][2] = 0;
		a[3][3] = 0;
	}
};


class Triangle : public Cube{
public:
	void draw(){
		a[0][0] = 0;
		a[0][1] = 1;
		a[0][2] = 0;
		a[0][3] = 0;
		a[1][0] = 1;
		a[1][1] = 1;
		a[1][2] = 1;
		a[1][3] = 0;
		a[2][0] = 0;
		a[2][1] = 1;
		a[2][2] = 0;
		a[2][3] = 0;
		a[3][0] = 0;
		a[3][1] = 0;
		a[3][2] = 0;
		a[3][3] = 0;
	}
};

//Losange


class CLosange  : public Cube{
public:

	//coins du losange
	void draw(){
		a[0][0] = 0;
		a[0][1] = 0;
		a[0][2] = 1;
		a[0][3] = 1;
		a[1][0] = 0;
		a[1][1] = 1;
		a[1][2] = 1;
		a[1][3] = 0;
		a[2][0] = 1;
		a[2][1] = 1;
		a[2][2] = 0;
		a[2][3] = 0;
		a[3][0] = 1;
		a[3][1] = 0;
		a[3][2] = 0;
		a[3][3] = 0;
	}
};


class TTLosange : public Cube{
public:
	//Gros T
	void draw(){
		a[0][0] = 1;
		a[0][1] = 1;
		a[0][2] = 1;
		a[0][3] = 1;
		a[1][0] = 0;
		a[1][1] = 1;
		a[1][2] = 1;
		a[1][3] = 0;
		a[2][0] = 0;
		a[2][1] = 1;
		a[2][2] = 1;
		a[2][3] = 0;
		a[3][0] = 0;
		a[3][1] = 1;
		a[3][2] = 1;
		a[3][3] = 0;
	}
};

class  XLosange : public Cube{
public:
	//X
	void draw(){
		a[0][0] = 1;
		a[0][1] = 0;
		a[0][2] = 0;
		a[0][3] = 1;
		a[1][0] = 0;
		a[1][1] = 1;
		a[1][2] = 1;
		a[1][3] = 0;
		a[2][0] = 0;
		a[2][1] = 1;
		a[2][2] = 1;
		a[2][3] = 0;
		a[3][0] = 1;
		a[3][1] = 0;
		a[3][2] = 0;
		a[3][3] = 1;
	}
};
class WLosange  : public Cube{
public:
	// barre droite 
	void draw(){
		a[0][0] = 1;
		a[0][1] = 1;
		a[0][2] = 1;
		a[0][3] = 1;
		a[1][0] = 1;
		a[1][1] = 1;
		a[1][2] = 1;
		a[1][3] = 1;
		a[2][0] = 1;
		a[2][1] = 1;
		a[2][2] = 1;
		a[2][3] = 1;
		a[3][0] = 1;
		a[3][1] = 1;
		a[3][2] = 1;
		a[3][3] = 1;
	}
};

class Losange  : public Cube{
public:
	//L
	void draw(){
		a[0][0] = 1;
		a[0][1] = 1;
		a[0][2] = 0;
		a[0][3] = 0;
		a[1][0] = 0;
		a[1][1] = 1;
		a[1][2] = 0;
		a[1][3] = 0;
		a[2][0] = 0;
		a[2][1] = 1;
		a[2][2] = 0;
		a[2][3] = 0;
		a[3][0] = 0;
		a[3][1] = 1;
		a[3][2] = 0;
		a[3][3] = 0;
	}
};


class VLosange : public Cube{
public:
	//Triangle
	void draw(){
		a[0][0] = 1;
		a[0][1] = 1;
		a[0][2] = 1;
		a[0][3] = 0;
		a[1][0] = 0;
		a[1][1] = 1;
		a[1][2] = 0;
		a[1][3] = 0;
		a[2][0] = 0;
		a[2][1] = 0;
		a[2][2] = 0;
		a[2][3] = 0;
		a[3][0] = 0;
		a[3][1] = 0;
		a[3][2] = 0;
		a[3][3] = 0;
	}
};
class TLosange : public Cube{
public:
	//T
	void draw(){
		a[0][0] = 0;
		a[0][1] = 1;
		a[0][2] = 1;
		a[0][3] = 1;
		a[1][0] = 0;
		a[1][1] = 0;
		a[1][2] = 1;
		a[1][3] = 0;
		a[2][0] = 0;
		a[2][1] = 0;
		a[2][2] = 1;
		a[2][3] = 0;
		a[3][0] = 0;
		a[3][1] = 0;
		a[3][2] = 1;
		a[3][3] = 0;
	}
};
class GLosange : public Cube{
public:
	//Gros cube
	void draw(){
		a[0][0] = 1;
		a[0][1] = 1;
		a[0][2] = 1;
		a[0][3] = 1;
		a[1][0] = 1;
		a[1][1] = 1;
		a[1][2] = 1;
		a[1][3] = 1;
		a[2][0] = 1;
		a[2][1] = 1;
		a[2][2] = 1;
		a[2][3] = 1;
		a[3][0] = 1;
		a[3][1] = 1;
		a[3][2] = 1;
		a[3][3] = 1;
	}
};


//Cercle

class lcube : public Cube{
public:
	//figure 10 (L)
	void draw(){
		a[0][0] = 1;
		a[0][1] = 0;
		a[0][2] = 0;
		a[0][3] = 0;
		a[1][0] = 1;
		a[1][1] = 0;
		a[1][2] = 0;
		a[1][3] = 0;
		a[2][0] = 1;
		a[2][1] = 0;
		a[2][2] = 0;
		a[2][3] = 1;
		a[3][0] = 1;
		a[3][1] = 1;
		a[3][2] = 1;
		a[3][3] = 1;
	}
};

class Gcube : public Cube{
public:
	//figure 9
	void draw(){
		a[0][0] = 1;
		a[0][1] = 1;
		a[0][2] = 1;
		a[0][3] = 1;
		a[1][0] = 1;
		a[1][1] = 0;
		a[1][2] = 0;
		a[1][3] = 1;
		a[2][0] = 0;
		a[2][1] = 0;
		a[2][2] = 0;
		a[2][3] = 0;
		a[3][0] = 0;
		a[3][1] = 0;
		a[3][2] = 0;
		a[3][3] = 0;
	}
};


class _8cube : public Cube{
public:
	//figure 8 (I)
	void draw(){
		a[0][0] = 0;
		a[0][1] = 0;
		a[0][2] = 1;
		a[0][3] = 0;
		a[1][0] = 0;
		a[1][1] = 0;
		a[1][2] = 1;
		a[1][3] = 0;
		a[2][0] = 0;
		a[2][1] = 0;
		a[2][2] = 1;
		a[2][3] = 0;
		a[3][0] = 0;
		a[3][1] = 0;
		a[3][2] = 1;
		a[3][3] = 0;
	}
};

class _7cube : public Cube{
public:
	//figure 7 (II)
	void draw(){
		a[0][0] = 0;
		a[0][1] = 1;
		a[0][2] = 1;
		a[0][3] = 0;
		a[1][0] = 0;
		a[1][1] = 1;
		a[1][2] = 1;
		a[1][3] = 0;
		a[2][0] = 0;
		a[2][1] = 1;
		a[2][2] = 1;
		a[2][3] = 0;
		a[3][0] = 0;
		a[3][1] = 1;
		a[3][2] = 1;
		a[3][3] = 0;
	}
};



class Ccube : public Cube{
public:
	//figure 6 (C)
	void draw(){
		a[0][0] = 1;
		a[0][1] = 1;
		a[0][2] = 1;
		a[0][3] = 0;
		a[1][0] = 0;
		a[1][1] = 0;
		a[1][2] = 1;
		a[1][3] = 0;
		a[2][0] = 0;
		a[2][1] = 0;
		a[2][2] = 1;
		a[2][3] = 0;
		a[3][0] = 1;
		a[3][1] = 1;
		a[3][2] = 1;
		a[3][3] = 0;
	}
};
class _5cube : public Cube{
public:
	//figure 5
	void draw(){
		a[0][0] = 0;
		a[0][1] = 0;
		a[0][2] = 0;
		a[0][3] = 0;
		a[1][0] = 1;
		a[1][1] = 1;
		a[1][2] = 1;
		a[1][3] = 1;
		a[2][0] = 1;
		a[2][1] = 1;
		a[2][2] = 1;
		a[2][3] = 0;
		a[3][0] = 0;
		a[3][1] = 0;
		a[3][2] = 0;
		a[3][3] = 0;
	}
};

class _4cube : public Cube{
public:
	// figure 4
	void draw(){
		a[0][0] = 1;
		a[0][1] = 1;
		a[0][2] = 1;
		a[0][3] = 1;
		a[1][0] = 0;
		a[1][1] = 0;
		a[1][2] = 0;
		a[1][3] = 1;
		a[2][0] = 0;
		a[2][1] = 0;
		a[2][2] = 0;
		a[2][3] = 1;
		a[3][0] = 0;
		a[3][1] = 0;
		a[3][2] = 0;
		a[3][3] = 1;
	}
};


class Ucube : public Cube{
public:
	//U
	void draw(){
		a[0][0] = 1;
		a[0][1] = 0;
		a[0][2] = 0;
		a[0][3] = 1;
		a[1][0] = 1;
		a[1][1] = 0;
		a[1][2] = 0;
		a[1][3] = 1;
		a[2][0] = 1;
		a[2][1] = 0;
		a[2][2] = 0;
		a[2][3] = 1;
		a[3][0] = 1;
		a[3][1] = 1;
		a[3][2] = 1;
		a[3][3] = 1;
	}
};

class Xcube : public Cube{
public:

	//Croix
	void draw(){
		a[0][0] = 0;
		a[0][1] = 1;
		a[0][2] = 1;
		a[0][3] = 0;
		a[1][0] = 1;
		a[1][1] = 1;
		a[1][2] = 1;
		a[1][3] = 1;
		a[2][0] = 1;
		a[2][1] = 1;
		a[2][2] = 1;
		a[2][3] = 1;
		a[3][0] = 0;
		a[3][1] = 1;
		a[3][2] = 1;
		a[3][3] = 0;
	}
};

class cube_cube : public Cube{
public:
	void draw(){
		a[0][0] = 1;
		a[0][1] = 1;
		a[0][2] = 1;
		a[0][3] = 1;
		a[1][0] = 1;
		a[1][1] = 1;
		a[1][2] = 1;
		a[1][3] = 1;
		a[2][0] = 1;
		a[2][1] = 1;
		a[2][2] = 1;
		a[2][3] = 1;
		a[3][0] = 1;
		a[3][1] = 1;
		a[3][2] = 1;
		a[3][3] = 1;
	}
};


class Forme
{
private:
	Cube* cube;
	color clr;

public:
	~Forme()
	{
		delete cube;
	}
	Forme(char type)
	{
		switch(type)
		{
			case 'Z':
				cube = new Zcube();clr = YELLOW;
				break;
			case 'S':
				cube = new Scube();clr = PURPLE;
				break;
			case 'T':
				cube = new Tcube();clr = BLACK;
				break;
			case 'O':
				cube = new Ocube();clr = PURPLE;
				break;
			case 'I':
				cube = new Icube();clr = DEEP_GREEN;
				break;
			case 'L':
				cube = new Lcube();clr = WHITE;
				break;
			case 'J':
				cube = new Jcube();clr = DEEP_GREEN;
				break;
			case 'l':
				cube = new lcube();clr = DEEP_GREEN;
				break;
			case 'G' : 
				cube = new Gcube();clr = PURPLE;
				break;
			case 'Q' : 
				cube = new _8cube();clr = WHITE;
				break;
			case 'Y': 
				cube = new _7cube();clr = GREEN;
				break;
			case 'C' : 
				cube = new Ccube();clr = YELLOW;
				break;
			case 'H' : 
				cube = new _5cube();clr = DEEP_GREEN;
				break;
			case 'A' : 
				cube = new _4cube();clr = DEEP_GREEN;
				break;
			case 'U' : 
				cube = new Ucube();clr = YELLOW;
				break;
			case 'X' : 
				cube = new Xcube();clr = GREEN;
				break;
			case 'B' : 
				cube = new cube_cube();clr = PURPLE;
				break;


			case 'z':
				cube = new ZTriangle();clr = YELLOW;
				break;
			case 'N':
				cube = new NTriangle();clr = PURPLE;
				break;
			case 'V':
				cube = new VTriangle();clr = BLACK;
				break;
			case 'i':
				cube = new ITriangle();clr = PURPLE;
				break;
			case 'R':
				cube = new TTriangle();clr = DEEP_GREEN;
				break;
			case 't':
				cube = new Triangle();clr = WHITE;
				break;
			case 'c':
				cube = new CLosange();clr = DEEP_GREEN;
				break;
			case 'u':
				cube = new TTLosange();clr = YELLOW;
				break;
			case 'x' : 
				cube = new XLosange();clr = PURPLE;
				break;
			case 'W' : 
				cube = new WLosange();clr = WHITE;
				break;
			case 'P': 
				cube = new Losange();clr = BLACK;
				break;
			case 'v' : 
				cube = new VLosange();clr = BLACK;
				break;
			case 'y' : 
				cube = new TLosange();clr = DEEP_GREEN;
				break;

			case 'g' : 
				cube = new GLosange();clr = DEEP_GREEN;
				break;

			default:
				printf("no %c type\n",type);
				break;
		}

	}
	int move_cube(int dir){return cube->move(dir);}
	int rotation_cube(){return cube->rotation();}
	void draw_cube(){cube->draw();}

	void setLocate(int a,int b){cube->setLocate(a,b);}
	void getLocate(int *a,int* b){cube->getLocate(a,b);}
	void* getArray(){cube->getArray();}

	void printCube(int color){
		if(color == CLEAR)
			cube->printCube(CLEAR);
		else cube->printCube(clr);
	}

	void setColor(color clr){
		this->clr = clr;
	}

	color getColor(){
		return clr;
	}

};

#endif
