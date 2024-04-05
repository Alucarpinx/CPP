#pragma once
#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <map>
#include <set>

using namespace std;

ifstream openInputFile(string filename);

int encodeWord(string word);

void printMultimap(multimap<int, string> wordsEncoded);