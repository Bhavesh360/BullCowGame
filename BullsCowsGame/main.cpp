#include <iostream>
#include <string>
#include "FBullCowGame.h"
//using namespace std;\

/* This is the console executable, that makes use of the BullCow class.
This acts as the view in a MVC patternn, and is responsible for all user interaction.
For game logic see the FBullCowGame class*/


using FText = std::string;
//instantiating BCGame
FBullCowGame BCGame;



void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();


int main()
{
	do {
		PrintIntro();
		PlayGame();
	}while (AskToPlayAgain() != false);

	return 0; //exit the application
}



void PlayGame()
{
	int maxTries = BCGame.GetMaxTries();

	FText guess = "";
	constexpr int NUMBER_OF_TURNS = 5;
	for (int i = 0; i < maxTries; i++) {
		guess = GetGuess();
		//print the users guess 
		std::cout << std::endl << "your guess is " << guess << std::endl;
		std::cout << std::endl;
	}

}


// introduce the game
void PrintIntro() 
{
	constexpr int WORD_LENGTH = 5;
	std::cout << "Welcome to FText's Bulls and Cows Game" << std::endl;
	std::cout << "can you guess the word of length " << WORD_LENGTH << " that I am thinking of?" << std::endl;
	std::cout << std::endl;
	return;
}

// get a guess from the player:
FText GetGuess()
{
	int myCurrentTry = BCGame.GetCurrentTry();
	std::cout <<"Try "<< myCurrentTry << " please enter your Guess" << std::endl;
	myCurrentTry++;
	FText guess = "";
	getline(std::cin, guess);
	return guess;
}

bool AskToPlayAgain()
{	
	std::cout << "Do you want to play again buoy (y/n)?";
	FText response="";
	getline(std::cin, response);
	return (response[0] == 'y' || response[0] == 'Y');

}
