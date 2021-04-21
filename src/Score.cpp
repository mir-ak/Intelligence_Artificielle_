#include "../include/Score.h"
#include "../include/Position.h"
#include "../include/Plan.h"

void Score::printSecor()
{
   Position p;

   p.save_position();
   p.place_cordonnee(1,36);
   cout<<"-------------";
   p.res_position();
   
   p.save_position();
   p.place_cordonnee(3,36);
   cout<<"-------------";
   p.res_position();

   p.save_position();
   p.place_cordonnee(2,37);
   cout<<"score : "<<score;
   p.res_position();

}
