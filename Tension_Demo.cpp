#include <iostream> //required for cin and cout
#include <cmath>    //required for all math functions
#include <iomanip>  //required for i/o formatting

using namespace std;

int main(){
    const double SIGN_WEIGHT = 100.0;
    const double CABLE_LENGTH = 6.0;
    const double POLE_LENGTH = 6.0;
    const INC = 0.001;

    double tension; 
    double new_tension;

    double x = 1.0;
    void tensionFun(){
    tension = (SIGN_WEIGHT * CABLE_LENGTH * POLE_LENGTH / (x * sqrt (CABLE_LENGTH * POLE_LENGTH - pow(x, 2.0)));
// increment x by 0.1 //
    }
    for (x >= 1.0; x <= 5.9){
        tensionFun();
        cout << "x = " << x << " " << "tension = " << tension << endl;
        continue; 
        }if (x == 5.9){
            tensionFun();
            cout << "x = " << x << " " << "tension = " << tension << endl;
            break;
    }












}