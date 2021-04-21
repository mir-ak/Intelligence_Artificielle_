#ifndef Plan_H_
#define Plan_H_

#include <iostream>
#include "Position.h"
using namespace std;

enum color{
	CLEAR = 0,
	BLACK = 30,
	RED,
	GREEN,
	YELLOW,
	BLUE,
	PURPLE,
	DEEP_GREEN,
	WHITE,
	BoldRED
};

class Plan{
protected:
	int color;
	int x;
	int y;
public:
	Plan()
	{
		color = CLEAR;
		x = 0;
		y = 0;
	}
	Plan(int a,int b,int c)
	{
		color = a;
		x = b;
		y = c;
	}

	void setPlan(const int x,const int y){this->x = x;this->y = y;}
	void setColor(const int color){this->color = color;}
	
	int getColor(){return color;}
	void getPlan(int&x,int &y){x = this->x;y = this->y;}
	void printPoint();
};

#endif
