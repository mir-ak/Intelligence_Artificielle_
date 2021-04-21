#include "../include/Rand.h"
#include <ctime>
#include <stdlib.h>
#include <iostream>

Rand::Rand()
{
    srand(unsigned(time(0)));
}

int Rand::randNum(int x,int y)
{
    int randNum;
    double random(double,double);
    randNum = int(random(x,y));
    return randNum;
}

double random(double start,double end)
{
    return start + (end - start)*rand()/(RAND_MAX + 1.0);
}