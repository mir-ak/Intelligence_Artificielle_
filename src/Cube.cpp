#include "../include/Cube.h"
#include <unistd.h>

void Cube::printCube(int color)
{
    int i,j;
    Plan p;
    for(i = x; i < x+4; i++)
        for(j = y; j < y+4; j++)
        {
            if(a[i - x][j - y] == 1)
            {
                p.setPlan(i,5+j);
                p.setColor(color);
                p.printPoint();
            }
        }
}

int Cube::move(int dir)
{
	switch(dir)
	{
		case DOWN:x++;break;
		case LEFT:y--;break;
		case RIGHT:y++;break;
		default:
				break;
	}
    return 0;
}

int Cube::rotation()
{
    int i,j;
    int b[4][4];
    for(i = 0; i < 4; i++)
        for(j = 0; j < 4; j++)
        {
            b[3-j][i] = a[i][j];
        }
    for(i = 0; i < 4; i++)
        for(j = 0; j < 4; j++)
        {
            a[i][j] = b[i][j];
        }
}

int Icube::rotation()
{
    if (a[0][1] == 0)
    {
        a[0][1] = 1;
        a[1][0] = 0;
        a[1][2] = 0;
        a[1][3] = 0;
        a[2][1] = 1;
        a[3][1] = 1;
    }
    else
    {
        a[0][1] = 0;
        a[1][0] = 1;
        a[1][1] = 1;
        a[1][2] = 1;
        a[1][3] = 1;
        a[2][1] = 0;
        a[3][1] = 0;
    }
}