#include "linker_header.h"
#include <iostream>
#include <iomanip>

using namespace std;

//checks if all characters are numbers
bool isNum(string& cardNumber) {
	//compares every character in string to check if it's a number between 0 and 9
	for (char c : cardNumber) {
		if (c < '0' || c > '9') {
			return false; //not a number
		}
	}
	return true; // All characters are number
}


bool readCardNUM(vector<int>& cardDigits) {
	//empty string for user input
	string cardNumber;
	cout << "Enter a 10 or 11 - digit credit card number : \n";
	//saves user's input
	cin >> cardNumber;
	//checks if user input is 10 or 11 digits and if they're all digits
	if ((cardNumber.length() == 10 || cardNumber.length() == 11) && (isNum(cardNumber))) {
		//Parse the string into an array of integers
		for (char digit : cardNumber) {
			cardDigits.push_back(digit - '0');
		}
		return true; //Input is valid
	}
	else {
		cout << "Invalid input. \n"; //Please enter a 10 or 11 - digit credit card number :
		cardNumber = '0';
		return false; //Input is invalid
	}
}

