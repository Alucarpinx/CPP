#include "linker_header.h"
#include <fstream>

using namespace std;

ifstream openInputFile(string filename) {
    ifstream infile(filename);
    //if not open cout error and exit program
    if (!infile.is_open()) {
        cout << "Error opening file " << filename << endl;
        exit(1);
    }
    //return infile
    return infile;
}