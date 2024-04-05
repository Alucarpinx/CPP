#pragma once
#include "Plant.h"
#include <vector>
#include <iomanip>
#include <iostream>


using namespace std;
// constains the function definitons and how they function 
Plant::Plant() {
	
	// assigns a default value to the variables plantName and plantCost
	plantName = "null";
	plantCost = 0.0;

}

void Plant::SetPlantName(string flowerName) {

	plantName = flowerName; // assigns the string variable "flowerName" the name of the plant

}
string Plant::GetPlantName() {

	return plantName; // returns plantname when calling function

}
void Plant::SetPlantCost(float flowerCost) {

	plantCost = flowerCost; // assigns the string variable "flowerCost" the cost of the plant

}
float Plant::GetPlantCost(){

	return plantCost; // returns plant cost when calling function

}
void Plant::PrintPlantInfo() {

	// prints out the name and cost of plant 
	cout << "   Name: " << plantName << endl;
	cout << "   Cost: " << setw(6) << setprecision(4) << plantCost << endl;

}
