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
FText GetValidGuess();
bool AskToPlayAgain();
void PrintWinOrLose();


int main()
{
	bool playAgain = false;
	do {
		
		PrintIntro();
		PlayGame();
		playAgain = AskToPlayAgain();
	}while (playAgain != false);

	return 0; //exit the application
}



void PlayGame()
{
	BCGame.Reset();
	int maxTries = BCGame.GetMaxTries();

	FText guess = "";
	constexpr int NUMBER_OF_TURNS = 5;

	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= maxTries) {
		guess = GetValidGuess();
		//print the users guess 
		std::cout << std::endl << "your guess is " << guess << std::endl;
		
		BullCowCount bullCowCount = BCGame.SubmitGuess(guess);
		std::cout << "Bulls: " << bullCowCount.Bull << " Cows: " << bullCowCount.Cow << std::endl;

		std::cout << std::endl;
	}
	PrintWinOrLose();
}


// introduce the game
void PrintIntro() 
{
	int wordLength = BCGame.GetWordLength();
	std::cout << "Welcome to FText's Bulls and Cows Game" << std::endl;
	std::cout << "can you guess the word of length " << wordLength << " that I am thinking of?" << std::endl;
	std::cout << std::endl;
	return;
}

// get a guess from the player:
FText GetValidGuess()
{
	EGuessStatus response = EGuessStatus::Invalid_response;
	do{
		int myCurrentTry = BCGame.GetCurrentTry();
		std::cout <<"Try "<< myCurrentTry << " please enter your Guess" << std::endl;
		myCurrentTry++;
		FText guess = "";
		getline(std::cin, guess);
		response = BCGame.CheckGuessValidity(guess);
		switch (response)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "please enter a word with correct word length\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "please enter a word without repeating letters\n";
			break;

		case EGuessStatus::Not_LowerCase:
			std::cout << "please make syre all the letters are lower case\n";
			break;
		default:
			return guess;;
		}
		std::cout << std::endl;
	} while (response != EGuessStatus::OK);
	
}

bool AskToPlayAgain()
{	
	std::cout << "Do you want to play again buoy (y/n)?";
	FText response="";
	getline(std::cin, response);
	return (response[0] == 'y' || response[0] == 'Y');

}

void PrintWinOrLose()
{
	if (BCGame.IsGameWon()) {
		std::cout << " YOU DID IT !!! \n\n";
	}
	else {
		std::cout << "wooops. Better luck next time friend!\n\n";
	}
}
