#ifndef SCORE_H
#define SCORE_H
#include <iostream>
#include <string>
using namespace std;

class Score{
private:
    int score;	

public:
    Score(){
    	score = 0;
    };
    void setScore(int s){
    	score = s;
    };
    void printSecor();
};

#endif
