#pragma once
#include <string>
#include <vector>

using namespace std;


class team_mem
{
private:
	string first_name;
	string last_name;
	int credit;

public:
	team_mem();
	team_mem(string, string, int);
	void DisplayMemInfo();
	string getName();
	int getCredit();
};