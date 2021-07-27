#ifndef TEAM
#define TEAM
#include <string>
#include <map>
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
#endif
