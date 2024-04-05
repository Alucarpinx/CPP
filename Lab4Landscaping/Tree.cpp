#include <string>
#include <iostream>
#include <iomanip>
#include "Plant.h"
#include "Tree.h"

using namespace std;

// constains the function definitons and how they function 
Tree::Tree() {}
void Tree:: SetTreeType(bool type) {
	// True or False variable to determine if tree is deciduous or not
	isDeciduous = type;

}
bool Tree:: GetTreeType() {
	// returns if plant is deciduous
	return isDeciduous;

}
void Tree:: PrintTreeInfo() {
	// calls plant print function for name and cost. in additiom prints if tree is deciduous 
	cout << "**** TREE ****" << endl;
	PrintPlantInfo();
	cout << "	Deciduous:	" << boolalpha << isDeciduous << endl << endl;

}
