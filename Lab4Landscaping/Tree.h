#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include "Plant.h"

using namespace std;

class Tree : public Plant {  //new class with class plant as parent to be able to access info from 
private: 
	// bool variable declaration
	bool isDeciduous;

public:
	//function declarations
	Tree();
	void SetTreeType(bool);
	bool GetTreeType();
	void PrintTreeInfo();

};