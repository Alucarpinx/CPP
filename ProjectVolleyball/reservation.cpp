#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "reservation.h"
#include "dodgeball.h"
#include <set>

using namespace std;

//reservation::reservations() {}
reservation::reservation(){
    name;
    pin = 0;
    carType;
    carColor ;
    seat;

}
reservation::reservation(string name_, string type, string color, int pin_, string seatt)
{
    name = name_;
    pin = pin_;
    carType = type;
    carColor = color;
    seat = seatt;

}
string reservation::getName() {
    return name;
}
string reservation::get_carType() {
    return carType;
}
string reservation::get_carColor() {
    return carColor;
}
//void reservation::setPin(int newPIN) {
//    pin = newPIN;
//}
string reservation::getSeat() {
    return seat;
}
void reservation::setName(string nameNew) {
    name = nameNew;
}
void reservation::setCarType(string type) {
    carType = type;
}
void reservation::setSeat(string seatNew) {
    seat = seatNew;
}
int reservation::getPin() {
    return pin;
}
//void reservation::delete(vector<>&,vector<>&, name, pin) {
//
//}