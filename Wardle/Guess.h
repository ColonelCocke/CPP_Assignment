#pragma once
#include <string>
class Guess
{
private:
	std::string UserGuess;
public:
	Guess();
	bool VerfiyGuess(std::string)const;
	void setGuess(std::string);
	void printGuess(std::string)const;
	int* findInword(std::string)const;
	int IsOccur(std::string, int)const;
};

