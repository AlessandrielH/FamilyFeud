#include "Team.h"
#include <string>
using namespace std;

string Team::getName()
{
	return name;
}

void Team::setName(string n)
{
	name = n;
}

void Team::addPoints(int p)
{
	points[name] += p;
}

Team::Team()
{
	name = "Please enter a name";
	points[name] = 0;
}
