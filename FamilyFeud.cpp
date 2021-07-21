// FamilyFeud.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Game.cpp"
using namespace std;

int main()
{
    Game myGame = new Game; 
    myGame.startPlaying();
    return 0;
}
