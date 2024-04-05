#include "line.h"
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <iomanip>

using namespace std;
//default coefficient values
lineType :: lineType() {
	a = 1.0;
	b = 1.0;
	c = 1.0;
}
//assigns new coefficient values
void lineType :: setCoefficient(float nA, float nB, float nC) {
	a = nA;
	b = nB;
	c = nC;
}
//displays a line in standard form
void lineType :: displayline() {
	cout << endl << setw(6) << fixed << setprecision(2) << a << " x ";
	//if b is positive prints "+", otherwise b is negative and not needed
	if (b >= 0) {
		cout << "+ ";
	}
	cout << b << " y = " << c << endl;
}
//calculates slope of line
void lineType :: lineSlope() {
	if (a == 0) {
		cout << setw(6) << "The line is horizontal and the slope is 0." << endl;
	}
	else if (b == 0) {
		cout << setw(6) << "The line is vertical and the slope is infinite." << endl;
	}
	else{// if (!(b == 0)) {
		cout << setw(6) << "The slope = " << - a / b << endl;
	};
}
//overload operand to check equality between two lines
bool lineType :: operator==(lineType& line2) {
	//checks if all coefficients match
	if (a == line2.a && b == line2.b && c == line2.c) {
		return true;
	}
	//else checks if coefficients are proportional
	if (a != 0 && line2.a != 0 && b != 0 && line2.b != 0) {
		float k = a / line2.a;
		if (b / line2.b == k && c / line2.c == k) {
			return true;
		}
	}
	return false;
}
//overload operand to check if two lines are parallel
bool lineType :: operator||(lineType& line2) {
	//Checks if both lines are horizontal
	if (a == 0 && line2.a == 0) {
		return true;
	}
	//Checks if both lines are vertical
	else if (b == 0 && line2.b == 0) {
		return true;
	}
	//Check if both lines have the same slope
	else if (b != 0 && line2.b != 0 && -a / b == -line2.a / line2.b) {
		return true;
	}
	//else lines aren't parallel
	else {
		return false;
	}
}
//overload operand to check if two lines are perpendicular
bool lineType :: operator&&(lineType& line2) {
	//checks if Either line is horizontal and the other is vertical
	if ((a == 0 && line2.b == 0) || (b == 0 && line2.a == 0)) {
		return true;
	}
	//of if the product of the lines’ slopes is equal to -1
	if ((-a / b) * (-line2.a / line2.b) == -1) {
		return true;
	}
	//else lines aren't perpendicular
	else {
		return false;
	}
}
//calculates intersection point between two lines
void lineType::lineIntersection(lineType& line2) {
	//checks if lines are parallel, if so no intersection point
	if ((a == 0 && a == line2.a) || (b == 0 && b == line2.b) || (-a / b == -line2.a / line2.b)) {
		cout << setw(6) << "Lines are parallel. Lines do not intersect" << endl;
	} 
	//else calculate the x and y of intersection point
	else {
		float x = (((c * line2.b) - (line2.c * b)) / ((a * line2.b) - (line2.a * b))) ;
		float y = (((c - a) / b) * x);
		cout << setw(6) << "Intersection Point: (" << x << ", " << y << ")" << endl;
	}
}