/*********************************************************************************************/
/*** Title: youtube_song.cpp                                                               ***/
/*** Course: Computational Problem solving CPET-II                                         ***/
/*** Developer: Hector Garcia                                                              ***/
/*** Description: Play a song from youtube url                                             ***/
/*********************************************************************************************/
#include <iostream> // cin & cout 
#include <string>   // strings
#include <vector>
#include <fstream>
#include "song.h"

using namespace std;

//Function to oepn playlist text file
ifstream Opensongfile()
{
	string inFileName = "cake.txt";//"my_playlist.txt";
	ifstream temp;

	temp.open(inFileName.c_str());

	//check if it was open
	if (!temp.is_open()) {
		cout << "\nUnable to open file... Program Terminated\n" << endl;
		exit(1);
	}
	return (temp);
}

int main() {
	//initializes ifstream for file
	ifstream inFile;
	//calls function to open file, returns command
	inFile = Opensongfile();
	//empty strings to hold song attributes
	string song_Name, song_Artist, song_URL;
	//empty vector array to store songs
	vector<Song> playList;
	//while there is data in file get info, else exit
	while (!inFile.eof()) {
		getline(inFile, song_Name);
		getline(inFile, song_Artist);
		getline(inFile, song_URL);
		Song temp(song_Name, song_Artist, song_URL);
		playList.push_back(temp);
	
	}

	/*for (int i = 0; i < 13; ++i) {
		getline(inFile, song_Name);
		getline(inFile, song_Artist);
		getline(inFile, song_URL);
		Song temp(song_Name, song_Artist, song_URL);
		playList.push_back(temp);
	}*/
	//variable to store user choice, random value because error if uninitialized
	int choice = 80;
	//(while loop to cycle as long as choice isn't -1)
	while (choice != -1) {
		//prints out menu header
		cout << setfill('*') << setw(100);
		//cout << "*********************************************************************************************";
		cout << "\n   *************** My Playlist ***************   \n";
		cout << "  *********************************************   ";
		cout << "\nSong Menu : ";
		//for loop prints songs
		for (int j = 0; j < playList.size(); ++j) {
			cout << endl << "  ( " << j << " ) : ";
			playList[j].DisplaySongInfo();
		}
		cout << "\n  ( -1 ) : QUIT\n";
		cout << setfill('*') << setw(60);
		//cout << "*********************************************************************************************";
		cout << "\nSelect => ";
		cin >> choice;
		//if valid song option play
		if (choice >= 0 && choice <= playList.size()) {
			playList[choice].PlaySong();
			cout << "Now Playing: \n";
			playList[choice].DisplaySongInfo();
		}
		//else if -1 exit program
		else if (choice == -1) {
			cout << "Bye, Thanks For Playing\n";
		}
		// else option not recognized
		else {
			cout << "Sorry, Not a Song Option\n";
		}
	}
	return 0;
}