#include "Session.h"
#include<iostream>
using namespace std;
Session::Session()
{
	score = 0;
	Guesses = new Guess[6];//created total 6 guesses
	WordTobeGuessed = "\0";
	next = NULL;//for list purpose only

}
int Session::getScore()const
{
	return score;
}
void Session::setWord(std::string str)
{
	WordTobeGuessed = str;//setting the actual word to be guessed
}
void Session::OutputScore(int sc)const
{//output the result based on score
	if (sc == 1)
	{
		cout << "Impossible!\n";
	}
	else if (sc == 2)
	{
		cout << "Amazing\n";
	}
	else if (sc == 3)
	{
		cout << "Outstanding!\n";
	}
	else if (sc == 4)
	{
		cout << "Great!\n";
	}
	else if (sc == 5)
	{
		cout << "Nice One!\n";
	}
	else
	{
		cout << "You got there!\n";
	}
}
int Session::simulateSession()
{
	bool SessionOver = false;
	int GuessNumber = 1;
	while (SessionOver == false && GuessNumber<=6)
	{
		string guess = "\0";
		do
		{
			guess = "\0";
			cout << "Guess >";
			cin >> guess;
		} while (guess.length() < 0 || guess.length() > 5);//getting output within range
		for (int i = 0; i < 5; i++)
		{
			guess[i] = tolower(guess[i]);//setting capital letter to lower
		}
		Guesses[GuessNumber - 1].setGuess(guess);
		for (int i = 0; i < GuessNumber; i++)//prints all previous guesses each iteration
		{
			Guesses[i].printGuess(WordTobeGuessed);
		}
		if (Guesses[GuessNumber - 1].VerfiyGuess(WordTobeGuessed))//if string matches,output score and session is over
		{
			OutputScore(GuessNumber);
			score = GuessNumber;
			SessionOver = true;
			break;
		}
		GuessNumber++;
	}
	if (SessionOver == false)//if guesses are complete but word is not guessed right
	{
		score = GuessNumber;
		cout << "Correct answer: " << WordTobeGuessed << endl;
	}
	//cout << GuessNumber << endl;
	return GuessNumber;
}
Session::~Session()
{
	delete[] Guesses;
	delete next;
}
