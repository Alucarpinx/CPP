#pragma once
#include <string>
#include <iostream>

using namespace std;

class Plant {
protected:
	//variable declarations that won't need to change
	string plantName;
	float plantCost;

public:
	//function declarations
	Plant();
	void SetPlantName(string);
	string GetPlantName();
	void SetPlantCost(float);
	float GetPlantCost();
	void PrintPlantInfo();

};