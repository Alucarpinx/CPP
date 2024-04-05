#include "dodgeball.h"
#include <vector>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

team_mem::team_mem()
{

}

team_mem::team_mem(string first, string last, int cred)
{
	first_name = first;
	last_name = last;
	credit = cred;
}

void team_mem::DisplayMemInfo()
{
	cout << first_name << " " << last_name << " " << credit;
}
string team_mem::getName()
{
	return first_name;
}
int team_mem::getCredit()
{
	return credit;
}