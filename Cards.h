#pragma once
#ifndef CARDS
#define CARDS
#include <map>
#include <vector>
#include <string>

using namespace std;

class Cards {

private:
	//map<int, map<string, vector<string> >  > quiz;
	//map<int, map< map<string, string>, map<string, vector<string> > > > quizy;
	map<int, map<string, string> > question;
	map<int, map<string, vector<string> > > answers;
	map<string, int> points;
	vector< vector<int> > answerPoints;

public:

	Cards();
	void setQuestion(string);
	string getQuestion(int num);
	vector<string> getAnswers(int);
	bool isCorrect(int,string);
	int totalQuestions();
	int totalAnswers(int);
	int getAnswerPoints(int , int );
	bool checkSumPoints(int);
	bool verifyCard(string);
	void setAnswers(vector<string>);
	void setPoints(vector<int>);
	void displayCards();
};
#endif 
