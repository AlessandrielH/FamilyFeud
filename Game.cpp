#include "Cards.cpp"
#include "Team.cpp"

#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

class Game
{
public:
	Game();
	~Game();
	void startPlaying(); 
	void displayInstructions();
	void displayMenu();
	
	
	void startPlaying()
	{
		//initialize Cards Object
		Cards cards= new Cards;
		int menu;

		do {
			displayMenu();
			cin >> menu;
			if (menu == 1)
			{
				displayInstructions();
			}
			else if (menu == 2)//players start game
			{
				string answer;
				string team1, team2;
				map<string, int> points;

				cout << "Enter team 1's name: ";
				cin >> team1;
				cout << "Hello " << team1 << ". " << endl;
				cout << "Enter team 2's name: ";
				cin >> team2;
				cout << "Hello " << team2 << ". " << endl;
				
				points[team1] =  0;
				points[team2] = 0;

				for (int round = 0; round < cards.totalQuestions(); round++)
				{
					cout << "ROUND:" << round + 1 << endl;
					int wrong = 0;
					int correct = 0;
					do{
						cout << "There are " << cards.totalAnswers(round) << " possible answers." << endl;
						cards.getQuestion(round);
						cin >> answer;

						if (cards.isCorrect(round, answer))
						{
							cout << "Your answer is correct." << endl;
							//display answer
							//add points for answer
						}
						else
						{
							wrong++;
							cout << "Your answer is incorrect. " << endl;
							cout<<"You have been incorrect "<<wrong<<" times."<<endl;
						}
						
						if (wrong==3)
						{
							//The other team answers question
						}
					} while (wrong < 3 && correct < cards.totalAnswers(round));
					/*repeats question until team guesses all answers 
					or answers incorrectly 3 times*/
				}
			}
			else if (menu == 3)//adds Card
			{
				cards.setQuestion();
				cards.setAnswers();
				cards.setPoints();
				cards.verfiyCard();
				cards.displayCards();
			}
			else if (menu == 4)//quit game
			{
				cout << "You have QUIT the game\n" << endl;
				break;
			}
			else
			{
				cout << "Your choice was invalid. You must enter a value 1-4.\n";
				cin.clear();
				cin.ignore(10000, '\n');
				menu = -1;
			}
		} while (menu < 4);
		cout << "Thank you for playing!!" << endl;

	}
	
	void displayInstructions()
	{
		cout<< "INSTRUCTIONS\n\n";
    		
		cout<<"Play Game Instructions:"<<endl;
		cout<< "1. You will be presented with the number of possible answers.\n";
		cout<<"2. The question will be displayed. \n";
		cout<<"3. The team called will enter an answer to the question.\n";
		cout<<"4. Possible Responses:\n";
		cout<<"\t ~  If the team answers correctly, that team will receive the points\n";
		cout<<"\t for that answer and enter in a new guess.\n";
		cout<<"\t ~  If the answer is wrong, that team will get 2 more chances to\n";
		cout<<"\t correctly answer the question.\n";
		cout<<"\t ~  If the answer, is still wrong after 2 chances, the other team\n";
		cout<<"\t gets 1 chance to guess the answer.\n";
		cout<<"\t ~  If the other team guesses correctly, they receive all of the points\n";
		cout<<"\t from that round.\n";
		cout<<"\t ~  If the other team guesses incorrectly, the original team keeps all\n";
		cout<<"\t of their points.\n";
		cout<<"5. The players will be asked if they want to play another round.\n";
		cout<<"\t ~  If they answer yes, the points will be carried over to the next\n";
		cout<<"\t round.\n";
		cout<<"\t ~  If they answer no, the game will return to the Menu.\n"<<endl;
		
		cout<<"Add Card Instructions:"<<endl;
	    	cout<<"In this section, You will add questions to the game."<<endl;
	    	cout<<"1. Create a question.\n";
	    	cout<<"2. Add 4-8 possible answers\n";
	    	cout<<"3. Assign points to each answer\n";
	    	cout<<"***The total points for each question should be 100\n"<<endl;
	}

	void DisplayMenu()
	{
		cout << "****************************************" << endl;
		cout << "*           Family Feud Game           *" << endl;
		cout << "*                  By                  *" << endl;
		cout << "*   A. Harper, J. Minor, J. Minor,     *" << endl;
		cout << "*       P. Ndhlovu, &  K. Brown        *" << endl;
		cout << "****************************************" << endl;
		cout << "* 1. Instructions                      *" << endl;
		cout<<"* 2. Play game.                          *" << endl;
		cout << "* 3. Enter new cards.                  *" << endl;
		cout << "* 4. Exit game.                        *" << endl;
		cout << "****************************************" << endl;
	}
};
