#pragma once
#include <string>
#include <iomanip>
#include <string>

using namespace std;

class Sedan {
private:
    int capacity = 4;

    string car_Type = "Sedan";

    string color;
    string driver;

    string Front_name = "X";
    string BackMid_name = "X";
    string BackLeft_name = "X";
    string BackRight_name = "X";

    int Front_val = 5;
    int BackMid_val = 1;
    int BackLeft_val = 2;
    int BackRight_val = 2;

public:
    // Sedan();
   //  Sedan(string, int);
    void setFront(string);
    string getFront();

    void setBackLeft(string);
    string getBackLeft();

    void setBackMid(string);
    string getBackMid();

    void setBackRight(string);
    string getBackRight();

    void setColor(string);
    string getColor();
    string getcar();

    void setDriver(string);
    string getDriver();

    int getFrontCredit();
    int getBackMidCredit();
    int getBackLeftCredit();
    int getBackRightCredit();

    void displaySedan();
};
