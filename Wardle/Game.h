#include "Session.h"
#include "Dictionary.h"
class Game
{
private:
	Session* head;
	Dictionary* dict;
	int currentIndexInDict;
	int CurrentStreak;
	int maxStreak;
	float gamePlayed;
	float winGames;
	float winPercent;
	int Guessdistribution[6];
public:
	Game();
	void playGame();
	std::string getGuess();
	void PrintHelp()const;
	void ShowStats()const;
	void addNewSession(Session*);
	~Game();
};