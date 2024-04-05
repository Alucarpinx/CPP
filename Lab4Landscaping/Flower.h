#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include "Plant.h"

using namespace std;

class Flower : public Plant { //new class with class plant as parent to be able to access info from 

private:

	string color;
	bool isAnnual;
public:
	//function declarations
	Flower();
	void SetFlowerColor(string);
	string GetFlowerColor();
	void SetFlowerType(bool);
	bool Getflowertype();
	void PrintFlowerInfo();
};