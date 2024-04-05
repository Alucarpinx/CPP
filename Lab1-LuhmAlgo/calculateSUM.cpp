#include "linker_header.h"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int calculateSUM(vector<int>& cardDigits) {
    //iniatlizes the sum to equal 0
    int sum = 0;
    //checker for second digit, first is false
    bool second = false;
    //luhns algorithm 
    for (int i = (cardDigits.size() - 1); i >= 0; --i) {
        //converts interget at index i from vector array into a single int
        int digit = cardDigits[i];
        //checks if its every second digit
        if (second) {
            //seconds digits are multiplied by 2
            digit *= 2;
            // if digit greater than 9 subtract 9
            // results in the two digit addition
            if (digit > 9) {
                digit -= 9;
            }
        }
        //adds digit to total sum
        sum += digit;
        //toggles between first and second
        second = !second;
    }
    // cout << sum;
    //returns the calculated sum
    return sum;
}
