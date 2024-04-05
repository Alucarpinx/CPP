#include "Pickup.h"
#include <vector>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;


Pickup::Pickup() {
	string color;
	string driver;
	string car_Type = "Pickup";
	string Front_name = "X";
	int Front_val = 5;
}

void Pickup::displayPickup()
{
	cout << endl;
	cout << "    " << color << "           Pick up" << endl;
	cout << "----------------------------------------" << endl;
	cout << "      |   " << driver << "  |     " << "   | " << Front_name << " |" << endl;
	cout << "                        " << "Value:" << Front_val << endl << endl;
	cout << "-----------------     ---------------------" << endl << endl;
}
void Pickup::setFront(string name)
{
	Front_name = name;
}
string Pickup::getFront()
{
	return Front_name;
}
void Pickup::setColor(string colorNew)
{
	color = colorNew;
}
string Pickup::getColor()
{
	return color;
}
void Pickup::setDriver(string driverNew)
{
	driver = driverNew;
}
string Pickup::getcar()
{
	return(car_Type);
}
string Pickup::getDriver()
{
	return driver;
}
int Pickup::getFrontCredit()
{
	return Front_val;
}




