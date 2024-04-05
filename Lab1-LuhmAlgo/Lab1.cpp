#include "linker_header.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
	//creates empty vector array
	vector<int> cardDigits;
	//variable controls if user wants to check multiple cards
	char cake = 'y';
	//cycles through code as long as user desires
	do {
		//Gets user input until a valid card number
		//negated so if true then false and stops
		while (!readCardNUM(cardDigits));
		//calculates the sum and saves into int var sum
		int sum = calculateSUM(cardDigits);
		//cout << "Calculated sum: " << sum << endl;
		//checks if card numbers are valid
		checkValidity(sum);
		cout << "Check a different credit card?[y/n]\n";
		cin >> cake;
	}
	while (cake == 'y');
	return 0;
	};