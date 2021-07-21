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
	map<string, int> points;//why is this a map and not an integer


public:
	Team();
	~Team();
	string getName();
	void setName(string);
	void addPoints(int);

	string getName()
	{
		return name;
	}
	
	void setName(string n)
	{
		name=n;
	}
	
	void addPoints(int p)
	{
		points[name]+=p;
	}
	
	Team()
	{
		name="Please enter a name";
		points[name]=0;
	}
};
