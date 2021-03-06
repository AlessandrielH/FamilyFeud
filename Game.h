#pragma once
#include "Cards.h"
#include <string>
#include <vector>
#ifndef GAME
#define GAME

class Game
{

	private:
		//initialize Cards Object
		Cards cards;

	public:
		//Game();
		//~Game();
		void startPlaying(); 
		void displayInstructions();
		void displayMenu();
		void createCards();
		string changeTeam(string, string, string);
		void sortFoundAns(vector<string>, vector <int>, vector<int>);
		void displayBoard(vector<string>, vector<int>,int, int);
};
#endif
