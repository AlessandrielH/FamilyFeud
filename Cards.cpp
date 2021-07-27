#include "Cards.h"
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <iterator>

using namespace std;

Cards::Cards() {

	question[0] = {{"questions", "Name something you haven't done since high school gym class"}};
	answers[0] = { {"answers", {"Run a Mile","DodgeBall","Push-Ups","Sit-ups/Crunches","Lift Weights","Swim Laps", "Change in a Locker Room","Tennis","Exercise"}} };
	question[1] = { {"questions", "If Your Dog Ran Away, Name Something You’d Be Surprised He Took With Him"} };
	answers[1] = { {"answers", {"The Cat","Leash/Collar","Food/Bowl","His Bone","Clothes/Shoe","Bed/Pillow","Favorite Toy","Wallet/Money"}} };
	question[2] = { {"questions", "Name Something You Find in a Breakfast Buffet"} };
	answers[2] = { {"answers", {"Eggs","Bacon","Sausage","Potatoes/Hashbrowns","Juice", "Coffee", "Melon", "Cereal"}} };
	question[3] = { {"questions", "Name Marvel’s Avengers"} };
	answers[3] = { {"answers", {"Captain America","Iron Man","Black Panther","The Hulk","Thor","Black Widow","Spiderman","Hawkeye"}} };
	question[4] = { {"questions", "In Horror Movies, Name a Place Teenagers Go Where There’s Always a Killer On the Loose"} };
	answers[4] = { {"answers", {"Cabin/Camp/Woods","Graveyard","Movie Theater", "Basement/Cellar","Closet","Closet","Bathroom/Shower", "Bedroom/Bed", "A Party"}} };
	question[5] = { {"questions", "Name a Common Candy Bar Component"} };
	answers[5] = { {"answers", {"Chocolate", "Peanuts", "Caramel", "Almonds", "Nougat", "Coconut"}} };
	question[6] = { {"questions", "Name a Place Where if Her Husband Took Her There For Her Anniversary, a Wife Would Be Mad"} };
	answers[6] = { {"answers", {"Tacky Restaurant", "Strip Joint", "Sporting Event","Bar/Club", "Bowling Alley","His Parent's House", "The Movies","Car Show"}} };
	question[7] = { {"questions", "Other Than Letters, Name Something People Get in the Mail"} };
	answers[7] = { {"answers", {"Junk Mail","Magazines","Bills","Packages", "Postcards", "Checks"}} };
	question[8] = { {"questions", "Name Something That Grows Faster Than You Want it To"} };
	answers[8] = { {"answers", {"Hair/Unibrow", "Lawn/Weeds", "Kids/Babies", "Belly/Weight", "Nails", "Debt/Expenses"}} };
	question[9] = { {"questions", "When You Call in Sick to Work or School, Name Something You Do to Make it Believable"} };
	answers[9] = { {"answers", {"Cough", "Hoarse", "Fake Puke", "Moan","Fake Doctor's Note", "Sneeze"}} };
	question[10] = { {"questions", "Name a Reason People Might Change Their Name"} };
	answers[10] = { {"answers", {"Got Married", "Their Name is Lame ", "Witness Protection", "Divorce"}} };

	answerPoints = { {25,23,21,9,8,5,3,2,2}, {23,17,16,9,6,6,4,4}, {25,24,19,12,7,6,2,2}, {22,22,20,15,15,9,3,3}, {49,12,6,5,5,4,4,4}, {36,22,15,12,10,6}, {43,19,12,6,4,4,2,2}, {24,22,17,14,5,4},{48,14,13,13,6,4}, {68,18,3,3,2,2}, {60,16,13,6} };

}

string Cards:: getQuestion(int num) {
	return question[num]["questions"];
}

vector<string>Cards:: getAnswers(int num) {

	return answers[num]["answers"];
}


int Cards::getAnswerPoints(int questionNum, int answerNum) {

	return answerPoints[questionNum][answerNum];
}

bool Cards::checkSumPoints(int num) {

	int total = 0;

	for (int i = 0; i < answerPoints[num].size(); ++i)
	{
		total += answerPoints[num][i];
	}

	return (total == 100);

}

void Cards::setQuestion(string sentence) {

	question[question.size()]["questions"] = sentence;

}
void Cards::setAnswers(vector<string> ans) {

	answers[answers.size()]["answers"] = ans;

}
void Cards::setPoints(vector<int> point) {

    answerPoints.push_back(point);

	//answerPoints[answerPoints.size()] = point;

}

bool Cards::verifyCard(string sentence) {

	for (int i = 0; i < question.size(); i++) {
		if (sentence == question[i]["questions"]) {
			return true;
		}
	}
	return false;

}

bool Cards::isCorrect(int num, string ans) {
	bool correct = false;

	for (int i = 0; i < (answers[0]["answers"].size()); i++) {
		if (ans == answers[0]["answers"][i]) {
			correct = true;
			break;
		}
	}

	return correct;
}

int Cards::totalQuestions() {
	return question.size();
}

int Cards::totalAnswers(int i) {
	return (answers[i]["answers"].size());
}
