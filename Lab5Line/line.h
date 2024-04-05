#include <iostream>
#include <cmath>

using namespace std;

class lineType {
private:
	float a, b, c;
public:
	//default value constructor
	lineType(); //: a(1.0), b(1.0), c(1.0) {}
	//member function setCoefficient
	void setCoefficient(float a, float b, float c);
	//member function that display a line in standard form
	void displayline();
	//calculates slope
	void lineSlope();
	//operand overload functions
	bool operator==(lineType&);
	bool operator||(lineType&);
	bool operator&&(lineType&);
	//calculates intersection point of two lines
	void lineIntersection(lineType&);
};
