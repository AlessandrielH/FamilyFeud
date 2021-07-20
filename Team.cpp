#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std; 

class Team
{

private:
	string name;
	map<string, int> points;
	


public:
	Team();
	~Team();
	string getName();
	void setName(string);
	void addPoints(int);

	
};