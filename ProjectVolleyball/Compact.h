#pragma once
#include <string>
#include <iomanip>
#include <string>

using namespace std;

class Compact {
private:
    int capacity = 3;

    string color;
    string driver;

    string car_Type = "Compact";

    string Front_name = "X";
    string BackLeft_name = "X";
    string BackRight_name = "X";

    int Front_val = 5;
    int BackLeft_val = 3;
    int BackRight_val = 3;

public:
    //Compact();
    //Compact(string, int);
    void setFront(string);
    string getFront();

    void setBackLeft(string);
    string getBackLeft();

    void setBackRight(string);
    string getBackRight();
    string getcar();
    void setColor(string);
    string getColor();
    void setDriver(string);
    string getDriver();

    int getFrontCredit();
    int getBackLeftCredit();
    int getBackRightCredit();

    void displayCompact();
};
