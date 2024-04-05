/**********************************************************/
/*** Title: Landscaping.cpp    					        ***/
/*** Description: CPET-321 Labs #4 - Fall 2023         	***/
/**********************************************************/
#include "Plant.h"
#include "Flower.h"
#include "Tree.h"
#include <vector>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <cstdlib>		

using namespace std;

ifstream OpenInputFile()
{
    //**** Step #1 ****/
    // Opens the input file yard_plants.txt reate a vector
    // of object Flower that contains all the flowers
    // that are (i) Annuals and (ii) Cost Less-Than $10.00
    // 
    // Once created, print-out all the flowers in the vector
    string inFileName = "yard_plants.txt";
    ifstream temp;

    temp.open(inFileName.c_str());

    if (!temp.is_open()) {
        cout << "\nUnsuccessfully... Program Terminated\n" << endl;
        exit(1);
    }
    return (temp);
}

int main()
{

    //**** Step #1 ****/
    // Opens the input file yard_plants.txt, read the plant information
    // and builds the two vectors myFlowers and myTrees.
    // 
    // After the two vectors are build, the information all the flowers,
    // and then all the trees, will be printed
    //   
    // If the files does not exist, the program terminates.

    ifstream inFile;
    inFile = OpenInputFile();

    vector<Flower> myFlowers;
    string flowerName;
    float flowerCost;
    string flowerColor;
    bool isAnnual;

    vector<Tree> myTrees;
    string treeName;
    float treeCost;
    bool isDeciduous;

    char flower_or_tree;

    Flower tempFlower;
    Tree tempTree;

    while (inFile.good()) {
        inFile >> flower_or_tree;
        if (tolower(flower_or_tree) == 'f')
        {
            inFile >> flowerName >> flowerCost >> flowerColor >> isAnnual;
            tempFlower.SetPlantName(flowerName);
            tempFlower.SetPlantCost(flowerCost);
            tempFlower.SetFlowerColor(flowerColor);
            tempFlower.SetFlowerType(isAnnual);
            myFlowers.push_back(tempFlower);
        }
        else if (tolower(flower_or_tree) == 't')
        {
            inFile >> treeName >> treeCost >> isDeciduous;
            tempTree.SetPlantName(treeName);
            tempTree.SetPlantCost(treeCost);
            tempTree.SetTreeType(isDeciduous);
            myTrees.push_back(tempTree);
        }
    }

    /** Prints the information on all the flowers **/
    cout << "**** ALL THE FLOWERS ****" << endl;
    for (int i = 0; i < myFlowers.size(); ++i) {
        myFlowers.at(i).PrintFlowerInfo();
    }

    /** Prints the information on all the tree **/
    cout << "**** ALL THE TREES ****" << endl;
    for (int i = 0; i < myTrees.size(); ++i) {
        myTrees.at(i).PrintTreeInfo();
    }


    //**** Step #2 ****/
    // Create a vector of object Flower that contains all the flowers
    // that are (i) Annuals and (ii) Cost Less-Than $10.00
    // 
    // Once created, print-out all the flowers in the vector

    // YOUR CODE GOES HERE
    vector<Flower> annualFlowers10; // creates empty vector of the class flower

    for (int i = 0; i < myFlowers.size(); ++i) { // loops through all the flowers in the "myflowers" vector

        if (myFlowers.at(i).Getflowertype() == 1 && myFlowers.at(i).GetPlantCost() < 10.00 ) {
            // verifies if the given flower at index 'i' meets the criteria of being annual and costing less than $10
            annualFlowers10.push_back(myFlowers.at(i)); // adds the flowers that meet criteria to the new vector "annualFlowers10"
        }
    }

    cout << "**** ANNUAL FLOWERS UNDER $10.00 ****" << endl; // prins label so we know what we're looking at

    for (int i = 0; i < annualFlowers10.size(); ++i) { // loops through the "annualFlowers10" vector
 
        cout << annualFlowers10.at(i).GetPlantName() << endl; // prints name of flower at index 'i'
    }
    cout << endl << endl;

    //**** Step #3 ****/
    // Create a vector of object Flower that contains all the flowers
    // that are (i) Perennials and (ii) Cost More-Than $20.00
    // 
    // Once created, print-out all the flowers in the vector

    // YOUR CODE GOES HERE
    vector<Flower> perennialFlowers20; // creates empty vector of the class flower

    for (int i = 0; i < myFlowers.size(); ++i) {  // loops through all the flowers in the "myflowers" vector

        if (myFlowers.at(i).Getflowertype() == 0 && myFlowers.at(i).GetPlantCost() > 20.00) {
        // verifies if the given flower at index 'i' meets the criteria of being perennial and costing more than $20
        // adds to perennialFlowers20 vector
           perennialFlowers20.push_back(myFlowers.at(i));
        }
    }
    cout << "**** ANNUAL FLOWERS MORE THAN $20.00 ****" << endl; // prins label so we know what we're looking at
    // loops through the "perennialFlowers20" vector and prints out the flower names
    for (int i = 0; i < perennialFlowers20.size(); ++i) {

        cout << perennialFlowers20.at(i).GetPlantName() << endl;
    }
    cout << endl << endl;

    //**** Step #4 ****/
    // Create a vector of object Flower that contains all the flowers
    // that are (i) RED or (ii) PINK
    // 
    // Once created, print-out all the flowers in the vector

    // YOUR CODE GOES HERE
    vector<Flower> RedPinkFlowers;// creates empty vector of the class flower

    for (int i = 0; i < myFlowers.size(); ++i) {
        // verifies if the given flower at index 'i' meets the criteria of being red and pink
        // adds to RedPinkFlowers vector
        if (myFlowers.at(i).GetFlowerColor() == "red" || myFlowers.at(i).GetFlowerColor() == "pink") {

            RedPinkFlowers.push_back(myFlowers.at(i));
        }
    }
    cout << "**** RED And PINK FLOWERS ****" << endl; // prins label so we know what we're looking at
    // loops through the "RedPinkFlowers" vector and prints out the flower names
    for (int i = 0; i < RedPinkFlowers.size(); ++i) {

        cout << RedPinkFlowers.at(i).GetPlantName() << endl;
    }
    cout << endl << endl;


    //**** Step #5 ****/
    // Create a vector of object Trees that contains all the 
    // Deciduous trees that cost between $100 and $200 
    // 
    // Once created, print-out all the Trees in the vector

    // YOUR CODE GOES HERE
    vector<Tree> deciduousTrees100200;// creates empty vector of the class flower

    for (int i = 0; i < myTrees.size(); ++i) {
        // verifies if the given flower at index 'i' meets the criteria of being deciduous and costing between $100 and $200
        // adds to deciduousTrees100200 vector
        if (myTrees.at(i).GetTreeType() == 1 && myTrees.at(i).GetPlantCost() > 100 && myTrees.at(i).GetPlantCost() < 200) {

            deciduousTrees100200.push_back(myTrees.at(i));
        }
    }
    cout << "**** DECIDUOUS TREES BETWEEN S100 and $200 ****" << endl;
    // loops through the "deciduousTrees100200" vector and prints out the flower names
    for (int i = 0; i < deciduousTrees100200.size(); ++i) {

        cout << deciduousTrees100200.at(i).GetPlantName() << endl;
    }
    cout << endl << endl;

    return 0;
}