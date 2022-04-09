#include "Guess.h"
using namespace std;
#include<iostream>
Guess::Guess()
{
	UserGuess = "\0";
}
void Guess::setGuess(std::string userguess)//setting the user guess
{
	UserGuess = userguess;
}
bool Guess::VerfiyGuess(std::string ActualWord)const//if guess is correct 
{
	if (UserGuess == ActualWord)
	{
		return true;
	}
	return false;
}
int Guess::IsOccur(string str, int loc)const//check the location of character in the user guess
{
	for (int i = 0; i < 5; i++)
	{
		if (UserGuess[loc] == str[i])
		{
			return i;
		}
	}
	return -1;
}
int* Guess::findInword(string Word)const
{
	string Word1;//using a new string to prevent modification of original string 
	int* output=new int[5];
	for (int i = 0; i<5; i++)
	{
		output[i] = -1;
	}
	Word1 = Word;//copying actual string to new string for iteration and modification purposes
	int iterator = 0;
	while (Word1[iterator] != '\0')
	{
		if (Word[iterator] == UserGuess[iterator])//if character exist at right location, marked it 1
		{
			output[iterator] = 1;
			Word1[iterator] = ' ';
		}
		else//-1 represent not exist
		{
			output[iterator] = -1;
		}
		iterator++;
	}
	iterator = 0;
	while (Word1[iterator] != '\0')
	{
		int iterator2 = IsOccur(Word1, iterator);
		if (iterator2 > -1 && output[iterator] != 1)//if character exist but not at location, marked it 0
		{
			output[iterator] = 0;
			Word1[iterator2] = ' ';
		}
		iterator++;
	}
	return output;
}
void Guess::printGuess(string ActualWord)const
{
	int* arr = new int[5];
	arr = findInword(ActualWord);
	for (int i = 0; i < 5; i++)
	{

			if (arr[i] == 1)
			{
				cout << "[" << UserGuess[i] << "] ";
			}
			else if(arr[i] ==0)
			{
				cout << "|" << UserGuess[i] << "| ";
			}
			else
			{
				cout << " " << UserGuess[i] << "  ";
			}
	}
	cout << endl;
}
