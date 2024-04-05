#include <iostream>
#include <set>
using namespace std;

int main() {
	//creates and populates set1
	set<int> set1 = { 10, 13, 14, 17, 19 };
	//creates and populates set2
	set<int> set2 = { 11, 13, 14, 16, 20 };
	//empty sets to store comparisons and results
	set<int> Union, Intersection, Symmetic, Ds1, Ds2 = {};

	//loop prints out elements in set1
	cout << "Set #1 :\n";
	for (int i : set1) {
		cout << i << ", ";
	}
	//loop prints out elements in set2
	cout << "\n\nSet #2 :" << endl;
	for (int i : set2) {
		cout << i << ", ";
	}

	//populates empty union set as equal to set1
	Union = set1;

	//loops through set2 an dinserts into union set, does not duplicate
	for (int i : set2) {
		Union.insert(i);
	}

	//prints out the combine set
	cout << "\n\nUnion :" << endl;
	for (int i : Union) {
		cout << i << ", ";
	}

	//loops throough set1 and set2, if count == 1, 
	//means the elements at i are the same therefore insert into intersection set
	for (int i : set1) {
		if (set2.count(i) == 1) {
			Intersection.insert(i);
		}
	}

	//prints out intersection set
	cout << "\n\nIntersection :" << endl;
	for (int i : Intersection) {
		cout << i << ", ";
	}

	//loops throough set1 and set2, compares both to each other. If count == 0, 
	//means the elements at i are different therefore insert into symmetic set
	for (int i : set1) {
		if (set2.count(i) == 0) {
			Symmetic.insert(i);
		}
	}
	for (int i : set2) {
		if (set1.count(i) == 0) {
			Symmetic.insert(i);
		}
	}

	//prints out Symmetic set
	cout << "\n\nSymmeteric Difference :" << endl;
	for (int i : Symmetic) {
		cout << i << ", ";
	}
	
	//loops throough set1 compares to set2. If count == 0, 
	//means the elements at i are different therefore insert into ds1 set
	for (int i : set1) {
		if (set2.count(i) == 0) {
			Ds1.insert(i);
		}
	}

	//prints out set
	cout << "\n\nDifference Set #1 -> Set #2 :" << endl;
	for (int i : Ds1) {
		cout << i << ", ";
	}

	//loops throough set2 compares to set1. If count == 0, 
	//means the elements at i are different therefore insert into ds1 set
	for (int i : set2) {
		if (set1.count(i) == 0) {
			Ds2.insert(i);
		}
	}

	//prints out set
	cout << "\n\nDifference Set #2 -> Set #1 :" << endl;
	for (int i : Ds2) {
		cout << i << ", ";
	}
}