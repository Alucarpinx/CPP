#include "linker_header.h"
#include <iostream>
#include <iterator>
#include <map>
#include <set>

using namespace std;

void printMultimap(multimap<int, string> wordsEncoded) {
    //set of keys to prevent multiple couts of the same key when more than one element
    set<int> printedKeys;

    for (auto it = wordsEncoded.begin(); it != wordsEncoded.end(); ++it) {
        //sets key to first element
        int key = it->first;
        //how many elements
        int count = wordsEncoded.count(key);

        // Check if words for this key have already been printed
        if (printedKeys.find(key) == printedKeys.end()) {
            //if one element 
            if (count == 1) {
                cout << "The key " << key << " mapped to " << count << " word : ";
                cout << it->second << ";" << endl;
            }
            //if mpre than one element
            else if (count > 1) {
                // Print the key, count, and words 
                cout << "The key " << key << " mapped to " << count << " words : ";

                //gets the bounds for the key with multiple elements
                auto range = wordsEncoded.equal_range(key);
                //links to first element
                auto itr = range.first;
                //cout elements
                while (itr != range.second) {
                    cout << itr->second;
                    //more than 2 elements
                    if (++itr != range.second) {
                        cout << "; ";
                    }
                }
                cout << ";" << endl;
            }
            // Set the flag to true since words have been printed for this key
            printedKeys.insert(key);
        }
    }
}
