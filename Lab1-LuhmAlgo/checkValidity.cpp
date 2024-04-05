#include "linker_header.h"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void checkValidity(int checksum) {
    //cheks if sum is divisible by 10
    if (checksum % 10 == 0) {
        cout << "Valid credit card numbers\n";
    }
    else {
        cout << "Invalid credit card numbers\n";
    }
}