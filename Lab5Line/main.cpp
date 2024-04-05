#include "line.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	//instantiates 4 objects of the class, therefore four lines
	lineType lines[4];
	//char to hld user's choice
	char menuPick;
	//menu layout
	do {
		cout << "\n Please choose a menu option\n" << "*****************************" << endl;
		cout << " " << setw(5) << "\n1. Set\n";
		cout << " " << setw(6) << "\n2. Display\n";
		cout << " " << setw(6) << "\n3. Display All\n";
		cout << " " << setw(6) << "\n4. Slope\n";
		cout << " " << setw(6) << "\n5. Equal\n";
		cout << " " << setw(6) << "\n6. Parallel\n";
		cout << " " << setw(6) << "\n7. Perpendicular\n";
		cout << " " << setw(6) << "\n8. Intersection\n";
		cout << " " << setw(6) << "\n9. Quit\n";
		cout << "\n****************************\n" << " " << setw(6) << " Enter a Menu Option: ";
		cin >> menuPick;
		//holds the index value to specify line
		int index;
		//switch case to pick menu option 
		switch (menuPick) {
			case '1':
				cout << "\n    Menu Option 1: Set";
				cout << "\nEnter line index from 0 - 3: ";
				cin >> index;
				if (index >= 0 && index < 4) {
					float a, b, c;
					cout << "\nEnter the coefficents a, b, c : \n";
					cin >> a >> b >> c;
					lines[index].setCoefficient(a, b, c);
					cout << "Coefficients set for line " << index << endl;
				}
				else {
					cout << "\nInvalid index. Enter a number between 0 and 3.\n";
				};
				break;
			case '2':
				cout << "\n   Menu Option 2: Display";
				cout << "\nEnter line index from 0 - 3: ";
				cin >> index;
				if (index >= 0 && index < 4) {
					cout << "Line: " << index;
					lines[index].displayline();
				}
				else {
					cout << "\nInvalid index. Enter a number between 0 and 3.\n";
				};
				break;
			case '3':
				cout << "\n   Menu Option 3: Display All";
				for(int i = 0; i < 4; ++i) {
					cout << "\nLine: " << i;
					lines[i].displayline();
				}
				break;
			case '4':
				cout << "\n   Menu Option 4: Slope";
				cout << "\nEnter line index from 0 - 3: ";
				cin >> index;
				if (index >= 0 && index < 4) {
					cout << "\nSlope of line: " << index << endl;
					lines[index].lineSlope();      
				}
				else {
					cout << "\nInvalid index. Enter a number between 0 and 3.\n";
				};
				break;
			case '5':
				int index1, index2;
				cout << "\n   Menu Option 5: Equal";
				cout << "\nEnter first line index from 0 - 3: ";
				cin >> index1;
				cout << "\nEnter second line index from 0 - 3: ";
				cin >> index2;
				if (index1 >= 0 && index1 < 4 && index2 >= 0 && index2 < 4) {
					if (lines[index1] == lines[index2]) {
						cout << "\nLines "<< index1 << " and " << index2 << " are equal\n";
					} else {
						cout << "\nLines " << index1 <<  " and " << index2 << " are not equal\n";
					};
				} 
				else {
					cout << "\nInvalid index. Enter a number between 0 and 3.\n";
				};
				break;
			case '6':
				cout << "\n   Menu Option 6: Parallel";
				cout << "\nEnter first line index from 0 - 3: ";
				cin >> index1;
				cout << "\nEnter second line index from 0 - 3: ";
				cin >> index2;
				if (index1 >= 0 && index1 < 4 && index2 >= 0 && index2 < 4) {
					if (lines[index1] || lines[index2]) {
						cout << "\nLines " << index1 << " and " << index2 << " are parallel\n";
					} else {
						cout << "\nLines " << index1 << " and " << index2 << " are not parallel\n";
					};
				} 
				else {
					cout << "\nInvalid index. Enter a number between 0 and 3.\n";
				};
				break;
			case '7':
				cout << "\n   Menu Option 7: Perpendicular";
				cout << "\nEnter first line index from 0 - 3: ";
				cin >> index1;
				cout << "\nEnter second line index from 0 - 3: ";
				cin >> index2;
				if (index1 >= 0 && index1 < 4 && index2 >= 0 && index2 < 4) {
					if (lines[index1] && lines[index2]) {
						cout << "\nLines " << index1 << " and " << index2 << " are perpendicular\n";
					}
					else {
						cout << "\nLines " << index1 << " and " << index2 << " are not perpendicular\n";
					};
				}
				else {
					cout << "\nInvalid index. Enter a number between 0 and 3.\n";
				};
				break;
			case '8':
				cout << "\n   Menu Option 8: Intersection";
				cout << "\nEnter first line index from 0 - 3: ";
				cin >> index1;
				cout << "\nEnter second line index from 0 - 3: ";
				cin >> index2;
				if (index1 >= 0 && index1 < 4 && index2 >= 0 && index2 < 4) {
					lines[index1].lineIntersection(lines[index2]);
				}
				else {
					cout << "\nInvalid index. Enter a number between 0 and 3.\n";
				};
				break;
			case '9':
				cout << "\n    Menu Option 9: Quitting Program.......";
				break;
			default:
				cout << "\nInvalid choice. Please enter a number between 1 and 9\n";
		}
	// cycles thru the code until user choices to exit program
	} while (menuPick != '9');
	// return 0 to exit
	return 0;
}