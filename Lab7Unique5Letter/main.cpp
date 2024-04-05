#include "linker_header.h"
#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {
    //Calls function to open words.txt and returns infile for reference
    ifstream infile = openInputFile("words.txt");

    //creates multimap to store encoded words
    multimap<int, string> wordsEncoded;
    //cout << "creates map\n";
    //read the file and pass the words to the encoding function
    string word;
    while (infile >> word) {
        //encode the word
        int key = encodeWord(word);
        //insert the key and word into the map
        wordsEncoded.insert({ key, word });
    }
    //cout << "Printing map....\n";
    printMultimap(wordsEncoded);
    cout << "\nclosing file....\n";
    //print all the map contaning the key and all the words associated with the key 
    infile.close();
    cout << "\nExiting...\n";
    return 0;
}