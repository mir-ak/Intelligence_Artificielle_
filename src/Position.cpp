#include "../include/Position.h"
#include <cstdio>
#include <cstdlib>

void Position::place_cordonnee(const int x,const int y)
{
	int i;
	for(i = 0; i < y; i++)
		printf("\33[2C");
	for(i = 0; i < x; i++)
		printf("\33[1B");
}
void Position::save_position()
{
	printf("\33[s");	
}
void Position::res_position()
{
	printf("\33[u");
}
