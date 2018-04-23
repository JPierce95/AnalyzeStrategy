//Author: Joshua E. Pierce
#include "SecretDoor/SecretDoor.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstring>

using namespace std;

int stay() { //Will simulate when a person stays on the same door.
        int stayWins = 0;
        SecretDoor game;

        game.newGame();
        game.guessDoorA();
        game.guessDoorA();
        if (game.isWinner()) {
                stayWins++;
        }
        return stayWins;
}

int change(){ //Will simulate what happens when a person always changes their door.
        bool chooseA = true; //Initializes it so that any door is viable to be picked.
        bool chooseB = true;
        bool chooseC = true;
        int changeWins = 0;
	
        SecretDoor game;
        game.newGame();
	
        game.guessDoorA();
        chooseA = false;
	
        if(game.isAopen()) { //Determines which door has been opened, and eliminates it as a possibility to be chosen
                chooseA = false;
        }
        else if(game.isBopen()) {
                chooseB = false;
        }
        else {
                chooseC = false;
        }

        if(chooseA) { //Chooses the final door based on which door is still set to true.
                game.guessDoorA();
        }

        else if (chooseB) {
                game.guessDoorB();
        }
        else {
                game.guessDoorC();
        }

        if (game.isWinner()) {
                changeWins++;
        }
        return changeWins;
}

int blind(){ //Will simulate what happens when a person predetermines their guesses. This will use a file with prefilled letters for guesses.
        SecretDoor game;
        fstream inFile;
        int wins = 0;
        int length = 0;
        int timesToRun = 0;
        char temp;
        vector <char> guesses;

        inFile.open("guess.data");
        if(inFile.fail()){
                cout << "Failed to open file" << endl;
        }
        else{

                while(!inFile.eof()){ //Inserts all of the letters into the guesses vector.
                        inFile >> temp;
                        guesses.push_back(temp);
                        length++;
                }

                timesToRun = guesses.size(); //If the number of letters in the file is odd, this will make sure to only run it
                if((guesses.size() % 2) != 0){
                        timesToRun--;
                }

                for(int i = 0; i < timesToRun; i++){ //Uses two letters per run to make a blind run.
			game.newGame();
                        if(guesses.at(i) == 'a' || guesses.at(i) == 'A'){
                                game.guessDoorA();
                        }
                        else if(guesses.at(i) == 'b' || guesses.at(i) == 'B'){
                                game.guessDoorB();
                        }
                        else if(guesses.at(i) == 'c' || guesses.at(i) == 'C'){
                                game.guessDoorC();
                        }
                        else{
                                cout << "The letter " << guesses.at(i) << " at vectr position " << i << " is not valid."<< endl;
                                break; // Exits the loop to avoid complications later down the line.
                        }
                        i++; //Moves on to the next piece of data in the vector.
                        if(guesses.at(i) == 'a' || guesses.at(i) == 'A'){
                                game.guessDoorA();
                        }
                        else if(guesses.at(i) == 'b' || guesses.at(i) == 'B'){
                                game.guessDoorB();
                        }
                        else if(guesses.at(i) == 'c' || guesses.at(i) == 'C'){
                                game.guessDoorC();
                        }
                        else{
                                cout << "The letter " << guesses.at(i) << " at vector position " << i << " is not valid." << endl;
                                break;
                        }
                        if(game.isWinner()){
                                wins++;
                        }
                }
        }
        return wins;
}

void fileEditor(int average, string file){
        ifstream inFile;
        ofstream outFile;
        string build = "";

        stringstream ss; //Converts the int average into a string so that it can be inserted to the file.
        ss << average;
        string num = ss.str();

        char *cString;
        cString = new char[file.length()]; // Converts string file into cstring so it can be read by the file opener.
        for (int i = 0; i < file.length(); i++){
                cString[i] = file[i];
        }
        cString[file.length()] = '\0';

        inFile.open(cString); //Opens file for reading.

        while(!inFile.eof()){   //Takes all of the information from the file and puts it into a string.
                getline(inFile, build);
        }

        build += " "; //Adds a space between the old numbers and new numbers.
        build += num; //Adds the current average to the end of the string.

        outFile << build;
        inFile.close();

        outFile.open(cString); //Opens the file for writing and inserts the build string into the file.
        outFile << build;
        outFile.close();
}

int fileReader(string file){
        ifstream inFile;
        vector <int> data;
        int temp = 0;
        int average = 0;

        char *cString; // Converts the file string into a cstring so that it can open the file.
        cString = new char[file.length()];
        for (int i = 0; i < file.length(); i++){
                cString[i] = file[i];
        }
        cString[file.length()] = '\0';

        inFile.open(cString);
        while(!inFile.eof()){ //Reads all of the data from the file and puts it into a vector.
                inFile >> temp;
                data.push_back(temp);
        }
        inFile.close();
        for(int i = 0; i < data.size(); i++){ // Adds all the data together and divides by number of values to get average.
                average += data.at(i);
        }
        average /= data.size();
        return average;
}

int main(){
        SecretDoor game;
        int stayWins = 0;
        int changeWins = 0;
        int blindWins = 0;
        int average = 0;
        int average2 = 0;

        cout << "\n\n" << endl; //Seperates the program from the terminal.

        for(int i = 0; i < 100; i ++){//Runs each method 100 (or 99) times and records how many times were a success.
                stayWins += stay();
        }
        for(int i = 0; i < 100; i++){
                changeWins += change();
        }
	blindWins += blind();

        cout << "Using the 'stay' method, the correct door was guessed " << stayWins << " times out of 100." << endl;
        cout << "Using the 'change' method, the correct door was guessed " << changeWins << " times out of 100." << endl;
        cout << "Using the 'blind' method, the correct door was guessed " << blindWins << " times." << endl;

        cout << endl;

        for(int i = 0; i < 100; i++){ // Gets the average of how many times it takes to get 10 doors correct in a row out of 100 successful times.
                int timesRan = 0;
                do{     //Runs through the methods until it succeeds 10 times in a row.
                        stayWins = 0;
                        for(int i = 0; i < 10; i++){//Will continue to run this block until all 10 attempts are succesful while recording how many times the block has run.
                                stayWins += stay();
                        }
                        timesRan++;
                }
                while(stayWins != 10);
                average += timesRan; // Records total times ran to be divided by 100 later for the average attempts.
        }
        average = average / 100;  // Divides by 100 to find the average.

        cout << "On average it took " << average << " attempts to get 10 doors correct in a row out of a sample size of 100 using the stay method." << endl;

        fileEditor(average, "stay.txt"); // Adds this run's data to the file.
        average = fileReader("stay.txt"); // Reads from the file to find the average of all attemps ever ran.
        cout << "The average of all known data in order to get 10 doors correct in a row with the stay method is " << average << "." <<endl;
        cout << endl;


        for(int i = 0; i < 100; i++){ //Same thing as the last for loop, but with the change method.
                int timesRan = 0;
                do{
                        changeWins = 0;
                        for(int i = 0; i < 10; i++){
                                changeWins += change();
                        }
                        timesRan++;
                }
                while(changeWins != 10);
                average2 += timesRan;
        }
        average2 = average2 / 100; // change back to 100

        cout << "On average, it took " << average2 << " attempts to get 10 doors correct in a row out of a sample size of 100 using the change method." << endl;
        fileEditor(average2, "change.txt");
        average2 = fileReader("change.txt");
        cout << "The average of all known data in order to get 10 doors correct in a row with the change method is " << average2 << "." <<endl;

        //Recall the SecretDoor functions you may need:
        // game.newGame(); //indicates the start to a new game
        // game.guessDoorA(); //tells host the player guesses Door A
        // game.guessDoorB(); //tells host the player guesses Door B
        // game.guessDoorC(); //tells host the player guesses Door C
        // game.isAopen(); //returns whether A is revealed to NOT have prize
        // game.isBopen(); //returns whether B is revealed to NOT have prize
        // game.isCopen(); //returns whether C is revealed to NOT have prize
        // game.isWinner(); //returns whether the player's second guess had the prize
        return 0;
}
