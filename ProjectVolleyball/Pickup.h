#pragma once
#include <string>
#include <iomanip>
#include <string>

using namespace std;

class Pickup {
private:

    string color;
    string driver;

    string car_Type = "Pickup";

    string Front_name = "X";

    int Front_val = 5;

public:
    Pickup();
    //Pickup(string, int);
    void setFront(string);
    string getFront();
    void setColor(string);
    string getColor();
    void setDriver(string);
    string getDriver();
    string getcar();
    int getFrontCredit();
    //bool getSeat_val(int);
    //void Check_seats();
    //void resevered_seats(string);
    void displayPickup();
};