#pragma once
#include "Score.h"
#include <algorithm>
#include <list>
#include <iostream>
using namespace std;
class HighScore
{
public:
	HighScore(int lenght);
	~HighScore();
	void AddScore(string _name, int _score);
	Score* GetScore(int pos);
	list<Score*>* GetScoreList() const;
	void SortScores();
	void ShowScores();
private:
	list<Score*>* scoreList;
	int lenght;
};

