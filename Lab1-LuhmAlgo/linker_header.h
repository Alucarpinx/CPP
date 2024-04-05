#pragma once
#include <vector>
#include <string>
#include <iostream>


using namespace std;
//Function to read a 10 or 11 digit card
bool readCardNUM(vector<int>&);
//Luhn's algorithm, calculates the sum
int calculateSUM(vector<int>&);
//Function to check if card is valid, divisible by 10
void checkValidity(int);
