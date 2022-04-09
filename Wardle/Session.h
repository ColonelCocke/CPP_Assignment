#pragma once
#include "Guess.h"
class Session
{
private:
	Guess* Guesses;
	std::string WordTobeGuessed;
	int score;
public:
	Session* next;
	Session();
	void setWord(std::string);
	int simulateSession();
	void OutputScore(int)const;
	int getScore()const;
	~Session();
};

