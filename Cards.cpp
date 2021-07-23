#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std; 

class Cards{

private:
	//map<int, map<string, vector<string> >  > quiz;
	//map<int, map< map<string, string>, map<string, vector<string> > > > quizy;
	map<int, map<string, string> > question;
    map<int, map<string, vector<string> >> answers;
    map<string, int> points;

public:
	 
	Cards();
	void setQuestion();
	string getQuestion(int num);
	vector<string> getAnswers(int); 
	bool isCorrect(int,string);
	int totalQuestions();
	int totalAnswers(int);
	vector< vector<int> > answerPoints; 
}; 

Cards::Cards(){

	question[0] = {{"questions", "Name a Reason People Might Change Their Name"}};
	answers[0] = {{"answers", {"Got Married", "Their Name is Lame ", "Witness Protection", "Divorce"}}};
	question[1] = {{"questions", "Name Something That Grows Faster Than You Want it To"}};
	answers[1] = {{"answers", {"Hair/Unibrow", "Lawn/Weeds", "Kids/Babies", "Belly/Weight", "Nails", "Debt/Expenses"}}};
	question[2] = {{"questions", "Name a Reason People Might Change Their Name"}};
	answers[2] = {{"answers", {"Got Married", "Their Name is Lame ", "Witness Protection", "Divorce"}}};
	question[3] = {{"questions", "Name a Reason People Might Change Their Name"}};
	answers[3] = {{"answers", {"Got Married", "Their Name is Lame ", "Witness Protection", "Divorce"}}};
	question[4] = {{"questions", "Name a Reason People Might Change Their Name"}};
	answers[4] = {{"answers", {"Got Married", "Their Name is Lame ", "Witness Protection", "Divorce"}}};
	question[5] = {{"questions", "Name a Reason People Might Change Their Name"}};
	answers[5] = {{"answers", {"Got Married", "Their Name is Lame ", "Witness Protection", "Divorce"}}};
	question[6] = {{"questions", "Name a Reason People Might Change Their Name"}};
	answers[6] = {{"answers", {"Got Married", "Their Name is Lame ", "Witness Protection", "Divorce"}}};
	question[7] = {{"questions", "Name a Reason People Might Change Their Name"}};
	answers[7] = {{"answers", {"Got Married", "Their Name is Lame ", "Witness Protection", "Divorce"}}};
	question[8] = {{"questions", "Name a Reason People Might Change Their Name"}};
	answers[8] = {{"answers", {"Got Married", "Their Name is Lame ", "Witness Protection", "Divorce"}}};
	question[9] = {{"questions", "Name a Reason People Might Change Their Name"}};
	answers[9] = {{"answers", {"Got Married", "Their Name is Lame ", "Witness Protection", "Divorce"}}};
	question[10] = {{"questions", "Name a Reason People Might Change Their Name"}};
	answers[10] = {{"answers", {"Got Married", "Their Name is Lame ", "Witness Protection", "Divorce"}}};

	answerPoints = { {60, 16, 13, 6}, {48,14,13,13,6,4}, {}, {}, {}, {}, {}, {},{}, {}, {} };

}

string Cards::getQuestion(int num){
	return question[num]["questions"];
}

vector<string> Cards::getAnswers(int num){

	return answers[num]["answers"];
}

int Cards::getAnswerPoints(int questionNum,int answerNum){

	return answerPoints[questionNum][answerNum]; 
}

bool Cards:: isCorrect(int num,string ans){
	bool correct = false;

	for(int i =0; i < (answers[0]["answers"].size()); i++){
		if(ans == answers[0]["answers"][i]){
			correct = true;
			break;
		}
	} 

	return correct; 
}

int Cards::totalQuestions(){
	return question.size();
}

int Cards::totalAnswers(int i){
	 return (answers[i]["answers"].size());
}
