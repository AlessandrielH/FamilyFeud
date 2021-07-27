#pragma once
#include "Cards.h"
#include <string>
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
};
#endif
