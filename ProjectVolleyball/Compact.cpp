#include "Compact.h"
#include <vector>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <cstdlib>	
#include <string>

using namespace std;


void Compact::setFront(string name)
{
	Front_name = name;
}
string Compact::getFront()
{
	return (Front_name);
}

void Compact::setBackLeft(string name)
{
	BackLeft_name = name;
}
string Compact::getBackLeft()
{
	return(BackLeft_name);
}

void Compact::setBackRight(string name)
{
	BackRight_name = name;
}
string Compact::getBackRight()
{
	return(BackRight_name);
}

void Compact::setColor(string colorNew)
{
	color = colorNew;
}
string Compact::getColor()
{
	return(color);
}
void Compact::setDriver(string name)
{
	driver = name;
}
string Compact::getDriver()
{
	return(driver);
}
string Compact::getcar()
{
	return(car_Type);
}
int Compact::getFrontCredit()
{
	return(Front_val);
}
int Compact::getBackLeftCredit()
{
	return(BackLeft_val);
}
int Compact::getBackRightCredit()
{
	return(BackRight_val);
}
void Compact::displayCompact()
{
	cout << endl;
	cout << "    " << color << "           Compact" << endl;
	cout << "----------------------------------------" << endl;
	cout << "      |   " << driver << "  |     " << "  | " << Front_name << " |" << endl;
	cout << "                        " << "Value:" << Front_val << endl << endl;
	cout << "      | " << BackLeft_name << " |  " << "      | " << BackRight_name << " |" << endl;
	cout << "       Value:" << BackLeft_val << "        Value:" << BackRight_val << endl << endl;
	cout << "-----------------     ---------------------" << endl << endl;

}