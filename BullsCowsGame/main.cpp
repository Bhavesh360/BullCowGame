#include <iostream>
#include <string>
using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
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
	string guess = "";
	constexpr int NUMBER_OF_TURNS = 5;
	for (int i = 0; i < NUMBER_OF_TURNS; i++) {
		guess = GetGuess();
		//print the users guess 
		cout << endl << "your guess is " << guess << endl;
		cout << endl;
	}

}


// introduce the game
void PrintIntro() 
{
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bhavesh's Bulls and Cows Game" << endl;
	cout << "can you guess the word of length " << WORD_LENGTH << " that I am thinking of?" << endl;
	cout << std::endl;
	return;
}

// get a guess from the player:
string GetGuess()
{
	cout << "please enter your Guess" << endl;
	string guess = "";
	getline(cin, guess);
	return guess;
}

bool AskToPlayAgain()
{	
	cout << "Do you want to play again buoy (y/n)?";
	string response="";
	getline(cin, response);
	return (response[0] == 'y' || response[0] == 'Y');

}
