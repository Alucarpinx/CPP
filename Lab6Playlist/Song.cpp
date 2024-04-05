#include "song.h"
#include <iostream> // cin & cout 
#include <string>   // strings

using namespace std;


Song::Song() {
	//default values for attributes
	name = "NA";
	artist = "NA";
	URL = "NA";
}
//assigns actual values to attributes
Song::Song(string song_Name, string song_artist, string song_URL) {
	name = song_Name;
	artist = song_artist;
	URL = song_URL;
}
//member funbction to display song info
void Song::DisplaySongInfo() {
	cout << name << " by " << artist << endl;
}
//member function to play song
void Song::PlaySong() {
	//empty string for command
	string command;

	cout << "Playing : " << name;
	cout << " by " << artist << endl;

	// Create Command line and call it
	command = "start chrome --window-size=250,675 " + URL;
	const char* system_command = command.c_str();
	system(system_command);

	// Close the Brower window to continue 
	cout << "\nClose the Brower window to continue, then..." << endl;
	system("pause");

}

