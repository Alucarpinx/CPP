#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;


string Karaka_Encrypt(string& word){
// reverse the order of the letters 
    string wrd = word; 
    reverse(wrd.begin(), wrd.end());
// replace vowels using the chart 
    for(char& c : wrd){
        switch(c){
            case 'a' :
                c = '0' ;
            break;
            case 'e' :
                c = '1' ;
            break;
            case 'i' :
                c = '2' ;
            break;
            case 'o' :
                c = '3' ;        
            break;
            case 'u' :
                c = '4' ;        
            break;
        }
    }
// add "aca" to the end of the word 
    wrd += "aca"; 
    return wrd;    
}

string Karaka_Decrypt(string& pass){

    string Aca_Removed = pass.substr(0, pass.size() -3);

    for(char& c : Aca_Removed){
        switch(c){
            case '0' :
                c = 'a' ;
            break;
            case '1' :
                c = 'e' ;
            break;
            case '2' :
                c = 'i' ;
            break;
            case '3' :
                c = 'o' ;        
            break;
            case '4' :
                c = 'u' ;        
            break;
        }
    }
    reverse(Aca_Removed.begin(), Aca_Removed.end());

    transform(Aca_Removed.begin(), Aca_Removed.end(), Aca_Removed.begin(), :: toupper);

    return Aca_Removed;

}

void OpenInputFile(){


}

void OpenOutputFile(){

    
}
int main(){
    ifstream inputFile; 
    ofstream outputFile; 
    string Input_File, Output_File;

    cout << "Enter the name of the input file: " << endl;
    cin >> Input_File;

    cout << "Enter the name of the output file: " << endl;
    cin >> Output_File;

   // ifstream inputFile; 
   // ofstream outputFile; 

    inputFile.open(Input_File);   
    if(!inputFile.is_open()){
        cout << "Unsuccessfully... Program Terminated" << endl;
        return 0;
    };

    outputFile.open(Output_File);
    if(!outputFile.is_open()){
        cout << "Unsuccessfully... Program Terminated" << endl;
        return 0;
    };


char deORen;
cout << "Encrypt or Decrypt [E/D]?" << endl;
cin >> deORen;
    string line;
    while(getline(inputFile, line)){
        if(deORen == 'E'){
            string encrypted = Karaka_Encrypt(line);
            outputFile << encrypted << endl;
            cout << "Encryption completed" << endl;
        }else if(deORen == 'D'){
            string decrypted = Karaka_Decrypt(line);
            outputFile << decrypted << endl;
            cout << "Decryption completed" << endl;
        }else{
            cout << "Invalid: Must ENTER E or D" << endl;
            break;
        } 
    };
    inputFile.close();
    outputFile.close();
    return 0;
};