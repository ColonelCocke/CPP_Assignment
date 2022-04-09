#include<iostream>
#include"Game.h"
using namespace std;
Game::Game()
{
	head = NULL;
	dict = new Dictionary();//creating a new dictionary for game play
	currentIndexInDict = 0;
	CurrentStreak = 0;
	maxStreak = 0;
	gamePlayed = 0;
	winGames = 0;
	winPercent = 0;
	for (int i = 0; i < 6; i++)
	{
		Guessdistribution[i] = { 0 };
	}
}
string Game::getGuess()
{
	if (currentIndexInDict < dict->WORD_COUNT)//if it is a valid dictionary index
	{
		
		currentIndexInDict++;
		return dict->words[currentIndexInDict - 1];
	}
	else//if currentindex crosses th length of dictionary
	{
		currentIndexInDict = 0;
		return dict->words[currentIndexInDict];
	}
}
void Game::addNewSession(Session* newSession)//function to store each  new session in a linkedlist of sessions.just for record purposes
{
	if (head == NULL)
	{
		//head = new Session();
		head = newSession;
	}
	else
	{
		Session* curr = head;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = newSession;
	}
}
void Game::playGame()
{
	Session* newSession = new Session();//creating a new session
	newSession->setWord(getGuess());//setting a word to be guessed
	newSession->simulateSession();//simulate the session
	gamePlayed++;//count a game played
	addNewSession(newSession);//add to list
	int sc = newSession->getScore();
	if ( sc < 7)//if player guessed it correctly in valid attempts
	{
		Guessdistribution[sc - 1] += 1;//update GD
		CurrentStreak += 1;//update current streak
		winGames++;//count a win
		if (maxStreak < CurrentStreak)//update max streak
			maxStreak = CurrentStreak;
		
	}
	else//if player fails to guess in valid tries
	{
		CurrentStreak = 0;
	}
	winPercent = (winGames / gamePlayed) * 100;//calculating win percentage
	newSession = NULL;
}
void Game::PrintHelp()const//printing help
{
	cout<<"Guess the WERDLE in six tries.\n\n";
	cout << "Each guess ust be a five-letter word. Hit the enter button to submit.\n\n";
	cout << "Examples\n";
	cout << "[A] P P L E\n";
	cout << "The letter A is in the correct position\n";
	cout << " D |E| A L T\n";
	cout << "The letter E is in the word but in the wrong position.\n";
}
void Game::ShowStats()const//priniting statistics
{
	cout << "Played: " << gamePlayed << "  Win%: " << winPercent;
	cout << "  Current streak: " << CurrentStreak << "  Max streak: " << maxStreak << endl << endl;
	cout << "Guess Distribution:\n";
	for (int i = 0; i < 6; i++)
	{
		cout << i + 1 << ": " << Guessdistribution[i] << endl;
	}
}
Game::~Game()
{
	delete dict;
	Session* current = head;
	while (current != NULL) {
		Session* next = current->next;
		delete current;
		current = next;
	}
	head = NULL;
}
//end of code