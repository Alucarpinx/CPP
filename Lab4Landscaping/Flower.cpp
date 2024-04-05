#include <string>
#include <iostream>
#include "Flower.h"
#include "Plant.h"

using namespace std;
// constains the function definitons and how they function 
Flower::Flower() {
}
void Flower:: SetFlowerColor(string flowerColor) {
	// assigns the variable color the color of the flower 
	color = flowerColor;

}
string Flower:: GetFlowerColor() {
	// retuns the assigned color of flowerColor
	return color;

}
void Flower:: SetFlowerType(bool type) {
	// assigns the type of flower to a bool that determines if the flower is annual 
	isAnnual = type;

}
bool Flower:: Getflowertype() {
	// retruns flower type when called
	return isAnnual;

}
void Flower:: PrintFlowerInfo() {
	// calls plant print function for name and cost. in additiom prints if flower is annual and the color
	cout << "**** FLOWER ****" << endl;
	PrintPlantInfo();
	cout << "	Annual: " << boolalpha << isAnnual << endl;
	cout << "	Color: " << color << endl << endl;

}