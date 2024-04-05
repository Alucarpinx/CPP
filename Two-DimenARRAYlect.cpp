#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
//method one
int data[3][4];

//method two
int const ROWS = 3;
int const COLS = 4;
int data2[ROWS][COLS];

//declaring and statis initialization 
//method one 
int data3[3][4] = { {12, 4, 20, 0},
                    {17, 22, 19, 11},
                    { 3, 9, 21, 44} };

//method 2
int data4[3][4] =   {12, 4, 20, 0, 
                     17, 22, 19, 11,
                     3, 9, 21, 44 };

//method 3
int data5[3][4] = {12, 4, 28, 8, 17, 22, 19, 11, 3, 9, 21, 44};

//method 4 dynamic intialization 
//data5[0][0] = 12;
//data5[0][1] = 4;
//data5[0][2] = 28;
//data5[0][3] = 8;

int main(){
    int arr[2][3] = {0, 1, 2, 3, 4, 5 };
    cout << arr << endl; 
    cout << arr[0] << endl;
    cout << arr[0][0] << endl;

for (i = 0; i < ROWS; ++i){
    for (j = 0; j < COLS; ++j){
        cout << setw(4) << arr[i][j];
    }
    cout << endl;
}
}