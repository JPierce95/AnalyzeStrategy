#include "SecretDoor/SecretDoor.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>

using namespace std;

int stayWins = 0; //Initialized as zero just to be safe.
int changeWins = 0;
int blindWins = 0;
int random;

bool chooseA, chooseB, chooseC;

string chosenDoor;

char input;

int staller = 0; //USed to stall program at to not end.

stay() { //Will simulate when a person stays on the same door.
	game.newGame();
	srand(time(0));
	random = (rand() % 3);
	if (random = 0) {
		game.guessDoorA();
		game.guessDoorA();
	}
	else if (random = 1) {
		game.guessDoorB();
		game.guessDoorB();
	}
	else {
		game.guessDoorC();
		game.guessDoorC();
	}
	if (game.isWinner()) {
		stayWins++;
	}
}

change{ //Will simulate what happens when a person always changes their door.
	chooseA = true; //Initializes it so that any door is viable to be picked.
	chooseB = true;
	chooseC = true;

	srand(time(0));
	random = (rand() % 3);
	if (random = 0) {  //Chooses a random door and eliminates it from being chosen as the final door.
		game.guessDoorA();
		chooseA = false;
	}
	else if (random = 1) {
		game.guessDoorB();
		chooseB = false;
	}
	else {
		game.guessDoorC();
		chooseC = false;
	}

	if(game.isAopen()) { //Determines which door has been opened, and eliminates it as a possibility to be chosen
		chooseA = false;
	}	
	else(game.isBopen()) {
		chooseB = false;
	}
	else(game.isCopen()) {
		chooseC = false;
	}

	if (chooseA) { //Chooses the final door based on previous information.
		game.guessDoorA()
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

}

blind{ //Will simulate what happens when a person predetermines their guesses. This will use a file with prefilled letters for guesses.

}

int main()
{
  SecretDoor game;

  for (int i = 0; i < 10; i++) {
	  stay();
  }
  for (int i = 0; i < 10; i++) {
	  change();
  }

  cout << "Using the 'stay' method, the correct door was guessed " << stayWins << " times." << endl;
  cout << "Using the 'change' method, the correct door was guessed " << changeWins << " times." << endl;
  cout << "Using the 'blind' method, the correct door was guessed " << blindWins << " times." << endl;


  cin >> staller;
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
