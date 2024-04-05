#include "linker_header.h"
#include <string>

using namespace std;

int encodeWord(string word) {
    //iterate through characters in word and swap the letters into numbers
    for (char& c : word) {
        switch (c) {
        case 'a':
        case 'b':
        case 'c':
            c = '2';
            break;
        case 'd':
        case 'e':
        case 'f':
            c = '3';
            break;
        case 'g':
        case 'h':
        case 'i':
            c = '4';
            break;
        case 'j':
        case 'k':
        case 'l':
            c = '5';
            break;
        case 'm':
        case 'n':
        case 'o':
            c = '6';
            break;
        case 'p':
        case 'q':
        case 'r':
        case 's':
            c = '7';
            break;
        case 't':
        case 'u':
        case 'v':
            c = '8';
            break;
        case 'w':
        case 'x':
        case 'y':
        case 'z':
            c = '9';
            break;
        }
    }
    //convert the new string of number into int
    int encoded = stoi(word);
    // << encoded;
    return encoded;
}
