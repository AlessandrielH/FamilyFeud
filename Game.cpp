#include "Game.h"
#include "Cards.h"
#include "Team.h"

#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <iterator>
#include <stdlib.h>
#include <time.h>

using namespace std;

	void Game::startPlaying()
	{
		int menu;

		do {
			displayMenu();
			cin >> menu;
			cout<< endl;
			if (menu == 1) //shows players game instructions
			{
				displayInstructions();
			}
			else if (menu == 2)//players start game
			{
				string answer;
				string team1, team2;
				map<string, int> points;

				cout << "Enter team 1's name: ";
				cin >>team1;
				cout << "Hello, " << team1 << ". " << endl;
				cout << "Enter team 2's name: ";
				cin>>team2;
					cin.clear();
					cin.ignore(10000, '\n');
				cout << "Hello, " << team2 << ". " << endl;
				cout << "*****************************************" << endl;

				points[team1] = 0;
				points[team2] = 0;
				int pointsPool = 0;
				string turn = team1;
				vector <string> foundAnswers;
				vector<int>answerPts;
				vector<int>UsedQuestions;
				srand(time(0));
				int currQuestion;
				bool newQ;
				bool steal = false;

				for (int round = 0; round < cards.totalQuestions(); round++)
				{
					//gets random Question
					do 
					{ 
						newQ = true;
						currQuestion = (rand() % (cards.totalQuestions() )+ 1) ;
						
						for (int i = 0; i < UsedQuestions.size(); i++)
						{
							if (currQuestion == UsedQuestions[i])//checks to see if question has been called already
								newQ = false;
						}
					} while (newQ==false);
					UsedQuestions.push_back(currQuestion);

					cout << "ROUND:" << round + 1 << endl;
					int wrong = 0;
					int correct = 0;
					pointsPool = 0;
					
					int ansLeft=cards.totalAnswers(currQuestion);
					
					do {
						cout << "Team " << turn << ", it is your turn."<<endl;
						cout << "Question " << round+1 << ": "<<cards.getQuestion(currQuestion) << endl;
						cout << "There are " << cards.totalAnswers(currQuestion) << " possible answers." << endl;
						cout << "Enter your answers below: " << endl;
						getline(cin, answer);
							cin.clear();
							cin.ignore(10000, '\n');
						if (cards.isCorrect(currQuestion, answer))
						{
							correct++;
							cout << "Your answer is CORRECT." << endl;
							foundAnswers.push_back(answer);
							answerPts.push_back(cards.getAnswerPoints(currQuestion, cards.getAnswerKey(currQuestion, answer)));
							ansLeft--;
							
							pointsPool += cards.getAnswerPoints(currQuestion, cards.getAnswerKey(currQuestion, answer));//adds points
						}
						else
						{
							wrong++;
							cout << "Your answer is INCORRECT. " << endl;
							cout << "This is strike " << wrong << "! " << endl; //shows user how many wrong answers (or strikes) they have
						}

						if (wrong == 3)
						{
							cout <<endl<< "*****************************************" << endl;
							//The other team answers question
							turn = changeTeam(turn, team1, team2);
							cout << "Team " << turn << " can now steal!!" << endl;
							//steal process
								// ask question
							cout << "Question " << round + 1 << ": " << cards.getQuestion(currQuestion) << endl;
							cout << "There are " << cards.totalAnswers(currQuestion) << " possible answers." << endl;
							cout << "Enter your answers below " << endl;
								// guess 
							getline(cin, answer);
									cin.clear();
									cin.ignore(10000, '\n');
							if (cards.isCorrect(currQuestion, answer))
							{
								correct++;
								steal = true;
								cout << "Your answer is CORRECT." << endl;
								//display answer
								foundAnswers.push_back(answer);
								answerPts.push_back(cards.getAnswerPoints(currQuestion, cards.getAnswerKey(currQuestion, answer)));
								ansLeft--;
								displayBoard(foundAnswers, answerPts,currQuestion, ansLeft);
								//add points
								pointsPool += cards.getAnswerPoints(currQuestion, cards.getAnswerKey(currQuestion, answer));
								cout << turn << " stole the round!!" << endl;
							}
							else
							{
								cout << "Your answer is INCORRECT. " << endl;
								turn = changeTeam(turn, team1, team2);
							}	
						}
						displayBoard(foundAnswers, answerPts, currQuestion, ansLeft);
						cout << endl << "*****************************************" << endl;
					} while ((wrong < 3) && (correct < cards.totalAnswers(currQuestion)));
					/*repeats question until team guesses all answers
					or answers incorrectly 3 times*/

					//assign points to winner
					if (turn == team1)
					{
						cout << team1 << " wins the round!" << endl;
						cout << team1 << " wins " << pointsPool << " points!!" << endl;
						points[team1] += pointsPool;
					}
					else {
						cout << team2 << " wins the round!!" << endl;
						cout << team2 << " wins " << pointsPool << " points!!" << endl;
						points[team2] += pointsPool;
					}

					//allows other team to answer first in the event of a steal
					if (steal)
					{
						turn = changeTeam(turn, team1, team2);
						steal = false;
					}

					foundAnswers.clear();
					answerPts.clear();

					cout << endl << "*****************************************" << endl;
					cout << team1 << " has " << points[team1] << " points!!" << endl;
					cout << team2 << " has " << points[team2] << " points!!" << endl;
					cout << endl << "*****************************************" << endl;

					turn = changeTeam(turn, team1, team2);
					cout << "Do you want to play another round? (Yes/No)" << endl;
					cin >> answer;
					if(answer=="yes"||answer=="Yes"||answer=="YES")
					{
						cout << "*****continue to next round*****" << endl;
					}
					else if (answer == "no"||answer=="No"||answer=="NO")
					{
						break;
					}
				}
				cout << team1 << " has " << points[team1] << " total points." << endl;
				cout << team2 << " has " << points[team2] << " total points. " << endl;
				UsedQuestions.clear();
			}
			else if (menu == 3)//adds Card
			{
				createCards();
				cards.displayCards();//needs to be defined
			}
			else if (menu == 4)//quit game
			{
				cout << "You have QUIT the game.\n" << endl;
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

	void Game::createCards() {
		int numCard;
		int numAns;
		int numPoint;
		string sentence;
		string ans;

		vector<int> inpoints;
		vector<string> inanswr;

		cout << endl<< "How many cards do you want to create? " << endl;
		cin >> numCard;
        	cin.clear();
        	cin.ignore(10000, '\n');


		for (int i = 0; i < numCard; i++) {
			do {
				cout <<endl<< "Enter question number " << i + 1 << "." << endl;
				getline(cin, sentence);
                	//cin.clear();
                	//cin.ignore(10000, '\n');
			} while (cards.verifyCard(sentence) == true);
			cards.setQuestion(sentence);

			cout << endl<< "How many possible answers do you want to add for this question? " << endl;
			cin >> numAns;
            		cin.clear();
            		cin.ignore(10000, '\n');

			cout << endl << "Enter " << numAns << " possible answers below: " << endl;
			for (int i = 0; i < numAns; i++) {
				cout << "Answer " << i + 1<<":";
				getline(cin, ans);
                		cin.clear();
                		cin.ignore(10000, '\n');
				inanswr.push_back(ans);
			}
			cards.setAnswers(inanswr);
			inanswr.clear();

			cout << "Assign " << numAns << " point(s) for each answer below: " << endl;
			for (int i = 0; i < numAns; i++) {
				cout << "Points " << i+1 << ": ";
				cin >> numPoint;
                		cin.clear();
                		cin.ignore(10000, '\n');
				inpoints.push_back(numPoint);
			}
			cards.setPoints(inpoints);
			inpoints.clear();

		}

	}

	void Game:: displayInstructions()
	{
		cout << "INSTRUCTIONS\n\n";

		cout << "Play Game Instructions:" << endl;
		cout << "1. You will be presented with the number of possible answers.\n";
		cout << "2. The question will be displayed. \n";
		cout << "3. The team called will enter an answer to the question.\n";
		cout << "4. Possible Responses:\n";
		cout << "\t ~  If the team answers correctly, that team will receive the points\n";
		cout << "\t for that answer and enter in a new guess.\n";
		cout << "\t ~  If the answer is wrong, that team will get 2 more chances to\n";
		cout << "\t correctly answer the question.\n";
		cout << "\t ~  If the answer, is still wrong after 2 chances, the other team\n";
		cout << "\t gets 1 chance to guess the answer.\n";
		cout << "\t ~  If the other team guesses correctly, they receive all of the points\n";
		cout << "\t from that round.\n";
		cout << "\t ~  If the other team guesses incorrectly, the original team keeps all\n";
		cout << "\t of their points.\n";
		cout << "5. The players will be asked if they want to play another round.\n";
		cout << "\t ~  If they answer yes, the points will be carried over to the next\n";
		cout << "\t round.\n";
		cout << "\t ~  If they answer no, the game will return to the Menu.\n" << endl;

		cout << "Add Card Instructions:" << endl;
		cout << "In this section, You will add questions to the game." << endl;
		cout << "1. Create a question.\n";
		cout << "2. Add 4-8 possible answers.\n";
		cout << "3. Assign points to each answer.\n";
		cout << "***The total points for each question should be 100.\n" << endl;
	}

	void Game::displayMenu()
	{
		cout << endl<< "****************************************" << endl;
		cout << "*           Family Feud Game           *" << endl;
		cout << "*                  By                  *" << endl;
		cout << "*   A. Harper, J. Minor, J. Minor,     *" << endl;
		cout << "*       P. Ndhlovu, &  K. Brown        *" << endl;
		cout << "****************************************" << endl;
		cout << "* 1. Instructions                      *" << endl;
		cout << "* 2. Play game                         *" << endl;
		cout << "* 3. Enter new cards                   *" << endl;
		cout << "* 4. Exit game                         *" << endl;
		cout << "****************************************" << endl;
	}

string Game::changeTeam(string turn, string t1, string t2)
	{
		if (turn == t1)
		{
			turn = t2;
		}
		else if (turn == t2)
		{
			turn = t1;
		}
		return turn;
	}

void Game::displayBoard(vector<string> foundAnswers, vector<int>answerPts,int currQuestion, int ansLeft)
{
	cout << endl << "*****************************************" << endl;
	cout << cards.getQuestion(currQuestion) << endl;
	cout << endl << ansLeft << " out of " << cards.totalAnswers(currQuestion) << " left." << endl;
	cout << endl << "FOUND ANSWERS" << endl;
	cout<<  "Points"  << "\t\t"<<"Answers"<< endl;
	if (foundAnswers.empty())
	{
		cout << "***EMPTY***" << endl;
	}
	else
	{
		for (int i = 0; i < foundAnswers.size(); i++)
		{
			cout << answerPts[i]  << "\t\t" <<  foundAnswers[i] << endl;//display found answers
		}
	}
	cout << "*****************************************" << endl;
}

/*void Game::sortFoundAns(vector<string> answers, vector <int> pts, vector<int> rank)
{
	for (int i = 0; i < answers.size(); i++)
	{
		string tempAns;
		int  ptemp;
		int current = pts[0];
		current = pts[i];
		if (current > pts[i+1])
		{
			ptemp = pts[i + 1];
			tempAns = answers[i + 1];
			pts[i + 1] = pts[i];
			pts[i] = ptemp;
			answers[i] = tempAns;
			rank[i] = i;
		}
	}
}*/
