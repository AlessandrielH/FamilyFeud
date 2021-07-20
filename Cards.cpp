#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std; 

class Cards{

private:

	map<int, map<string, vector<string> >  > quiz;
	map<string, int> points;

public:
	map<int, map<string, string>  > getCard(); 
	void setQuestion();
	vector<string> getAnswers(); 


};