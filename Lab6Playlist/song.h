#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Song {
private:
	string name, artist, URL;
public:
	Song();
	Song(string, string, string);
	void DisplaySongInfo();
	void PlaySong();

};