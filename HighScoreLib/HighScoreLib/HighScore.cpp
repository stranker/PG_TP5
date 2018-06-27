#include "HighScore.h"

bool compareScore(const Score* s1, const Score* s2)
{
	return s1->GetScore() > s2->GetScore();
}

HighScore::HighScore(int _length)
{
	lenght = _length;
	scoreList = new list<Score*>();
}


HighScore::~HighScore()
{
	delete scoreList;
}

void HighScore::AddScore(string _name, int _score)
{
	Score* add = new Score(_name, _score);
	scoreList->push_back(add);
	scoreList->sort(compareScore);
	if (scoreList->size() > lenght)
		scoreList->pop_back();
}

Score * HighScore::GetScore(int pos)
{
	Score* found = NULL;
	list<Score*>::iterator it;
	int cont = 1;
	for (it = scoreList->begin(); it != scoreList->end(); it++)
	{
		if (cont == pos)
			found = *it;
		cont++;
	}
	return found;
}

list<Score*>* HighScore::GetScoreList() const
{
	return scoreList;
}

void HighScore::ShowScores()
{
	cout << "**************************************" << endl;
	cout << "**************HIGHSCORES**************" << endl;
	cout << "**************************************" << endl;

	list<Score*>::iterator it;
	int count = 1;
	for (it = scoreList->begin(); it != scoreList->end(); it++)
	{
		Score* s = *it;
		cout << "N- " << count << " " << s->GetName().c_str() << "    " << s->GetScore() << endl;
		count++;
	}

	cout << "**************************************" << endl;
	cout << "**************************************" << endl;
	cout << "**************************************" << endl;
}


