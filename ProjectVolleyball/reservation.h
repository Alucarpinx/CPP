#pragma once
#include <string>
#include <vector>

using namespace std;


class reservation
{
private:
    string name;
    string carType;
    string carColor;
    int pin = 0;
    string seat;
 

public:
    reservation();
    reservation(string, string, string, int, string);
    string getName();
    string get_carType();
    string get_carColor();
    string getSeat();
    void setName(string);
    void setCarType(string);
    void setSeat(string);
    int getPin();
    //void delete(vector<>&, vector<>&, vector<>&, vector<>&, string, int);
};