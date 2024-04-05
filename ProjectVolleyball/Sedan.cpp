#include "Sedan.h"
#include <vector>
#include <iomanip>
#include <fstream>
#include <iostream>	
#include <string>

using namespace std;

void Sedan::setFront(string name)
{
	Front_name = name;
}
string Sedan::getFront()
{
	return (Front_name);
}

void Sedan::setBackLeft(string name)
{
	BackLeft_name = name;
}
string Sedan::getBackLeft()
{
	return(BackLeft_name);
}

void Sedan::setBackMid(string name)
{
	BackMid_name = name;
}
string Sedan::getBackMid()
{
	return(BackMid_name);
}

void Sedan::setBackRight(string name)
{
	BackRight_name = name;
}
string Sedan::getBackRight()
{
	return(BackRight_name);
}

void Sedan::setColor(string colorNew)
{
	color = colorNew;
}
string Sedan::getColor()
{
	return(color);
}
void Sedan::setDriver(string name)
{
	driver = name;
}
string Sedan::getDriver()
{
	return(driver);
}
string Sedan::getcar()
{
	return(car_Type);
}
int Sedan::getFrontCredit()
{
	return(Front_val);
}
int Sedan::getBackMidCredit()
{
	return(BackMid_val);
}
int Sedan::getBackLeftCredit()
{
	return(BackLeft_val);
}
int Sedan::getBackRightCredit()
{
	return(BackRight_val);
}
void Sedan::displaySedan()
{
	cout << endl;
	cout << "    " << color << "           Sedan" << endl;
	cout << "----------------------------------------------" << endl;
	cout << "|   " << driver << "  |               " << "  | " << Front_name << " |" << endl;
	cout << "                              " << "Value:" << Front_val << endl << endl;
	cout << "| " << BackLeft_name << " |          | " << BackMid_name << " |          | " << BackRight_name << " |" << endl;
	cout << "value:" << BackLeft_val << "       " << "value:" << BackMid_val << "       " << "value:" << BackRight_val << endl << endl;
	cout << "------------------     -----------------------" << endl << endl;
}