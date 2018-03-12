/*
 * SecretDoor.cpp
 *
 * Author: Kevin Buffardi
 * Date: Feb 18, 2018
 * Description: Method and member definitions for SecretDoor class;
 *              see .h file for class description
 */

#include "SecretDoor.h"
#include <ctime>
#include <cstdlib>

static bool seed_once = false;
/*
 * SecretDoor()
 *
 * Constructor for a SecretDoor instance, and initiates 
 */
SecretDoor::SecretDoor()
{
	if(!seed_once)
	{
		srand(time(NULL)); 
		seed_once=true;
	}
	newGame();
}

/*
 * newGame()
 *
 * Begins a new game with a new door selection and cleared guesses 
 */
void SecretDoor::newGame()
{
	guesses = 0;
	open = ' ';
	won = false;
	winner = randDoor();
}


void SecretDoor::guessDoorA(){guessDoor('A');}
void SecretDoor::guessDoorB(){guessDoor('B');}
void SecretDoor::guessDoorC(){guessDoor('C');}
bool SecretDoor::isAopen(){return (open == 'A');}
bool SecretDoor::isBopen(){return (open == 'B');}
bool SecretDoor::isCopen(){return (open == 'C');}

/*
 * randDoor()
 *
 * Chooses a pseudo-random letter: A, B, or C
 *
 * @return: char randomly generated 'A' 'B' or 'C'
 */
char SecretDoor::randDoor()
{
	char chosen;
	int secret = rand() % 3;
	switch(secret)
	{
		case 0:
			chosen = 'A';
			break;
		case 1:
			chosen = 'B';
			break;
		default:
			chosen = 'C';
			break;
	}

	return chosen;
}

/*
 * guessDoor()
 *
 * Evaluates door guesses; the first guess opens a door
 * that was NOT chosen that does not hold the prize; the
 * second guess will evaluate whether or not the prize
 * has been discovered
 *
 * @param door - a letter ('A' 'B' or 'C') representing
 *               the door chosen
 */
void SecretDoor::guessDoor(char door)
{
	guesses++;
	if( guesses == 1 )
	{
		revealWrong(door);
	}
	else if ( guesses == 2 )
	{
		evaluate(door);
	}
	else
	{
		won = false;
	}
}

/*
 * revealWrong()
 *
 * Based on the door guessed, reveals a random door
 * that is NOT the one guessed, and is NOT the prize-
 * winning door
 *
 * @param door - the last door guessed
 */
void SecretDoor::revealWrong(char door)
{
	char wrong;
	do{
		wrong = randDoor();
	}while( wrong == door || wrong == winner );
	open = wrong;
}

/*
 * evaluate()
 *
 * Determines if a door guessed is correct or not
 *
 * @param door - the door letter guessed
 */
void SecretDoor::evaluate(char door)
{
	if( door == winner )
	{
		won = true;
	}
	else
	{
		won = false;
	}
}

/*
 * isWinner()
 *
 * Determines if the player has won the game or not
 *
 * @return bool - true or false if the player has won
 */
bool SecretDoor::isWinner()
{
	return won;
}
