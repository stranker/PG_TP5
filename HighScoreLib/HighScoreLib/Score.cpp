#include "Score.h"



Score::Score(string _name, int _score)
{
	name = _name;
	score = _score;
}


Score::~Score()
{
}

int Score::GetScore() const{
	return score;
}

string Score::GetName() const{
	return name;
}

void Score::SetScore(int newScore){
	score = newScore;
}

void Score::SetName(string newName){
	name = newName;
}
