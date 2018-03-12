/*
 * SecretDoor.h
 *
 * Author: Kevin Buffardi
 * Updated: Oct 8, 2015
 * Description: This class operates a "Monty Hall" like game
 *              where there are three doors.  The player guesses
 *              one door.  One of the doors NOT guessed that does
 *              NOT have the hidden prize behind it is revealed
 *              as a empty door.  Then, the player has the choice
 *              of either keeping their original guess, or changing
 *              to the other unrevealed door.
 *
 */
#ifndef SECRETDOOR_H_
#define SECRETDOOR_H_

class SecretDoor
{
	private:
	char winner;
	char open;
	int guesses;
	bool won;


	protected:
	char randDoor();
	void guessDoor(char);
	void revealWrong(char);
	void evaluate(char);

	public:
	//Sets initial values...
	SecretDoor();
  void newGame();
  
	//guesses the different doors...
	void guessDoorA();
	void guessDoorB();
	void guessDoorC();

	//tests to see if the doors are open...
	bool isAopen();
	bool isBopen();
	bool isCopen();

	//tests to see if the second guess was a winning guess
	bool isWinner();

	
};

#include "SecretDoor.cpp"

#endif /* SECRETDOOR_H_ */
