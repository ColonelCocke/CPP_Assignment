#include <iostream>
using namespace std;
#include "Game.h"

int main()
{
    Game G;//only game object 
    int menuChoice = 0;
    while (1)
    {
        menuChoice = 0;
        do
        {
            cout << "\nWelcome to WERDLE.\n";
            cout << "Select an option :\n\n1. Play a game\n2. View statistics\n3. View Help\n> ";
            cin >> menuChoice;
        } while (menuChoice < 1 || menuChoice>3);//menu choice within range
        if (menuChoice == 1)//if user wants to play game
        {
            G.playGame();
        }
        else if (menuChoice == 2)//if user wants to know stats
        {
            G.ShowStats();
        }
        else if (menuChoice == 3)//if user needs help
        {
            G.PrintHelp();
        }
        else
            continue;
    }
}