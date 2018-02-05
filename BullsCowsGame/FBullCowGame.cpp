#include "FBullCowGame.h"

//constructor:
FBullCowGame::FBullCowGame() 
{
	Reset();
}


//Getters
int FBullCowGame::GetMaxTries() const{ return MyMaxTries; }
int FBullCowGame::GetCurrentTry() const{ return MyCurrentTry; }
int FBullCowGame::GetWordLength() const { return myHiddenWord.length(); }

void FBullCowGame::Reset()
{
	constexpr int MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;
	const std::string HIDDEN_WORD = "Bhavesh";
	myHiddenWord = HIDDEN_WORD;
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(std::string guess) const
{	
	if (false) {
		return EGuessStatus::Not_Isogram;
	}

	else if (false) {
		return EGuessStatus::Not_LowerCase;
	}
	
	else if (guess.length() != GetWordLength() ) {
		return EGuessStatus::Wrong_Length;
	}
	else {
		return EGuessStatus::OK;
	}
	
}

bool FBullCowGame::CheckLowerCase(std::string guess)
{

}

BullCowCount FBullCowGame::SubmitGuess(std::string guess) {

	//increment the number of tries:
	MyCurrentTry++;

	//Initialize BullCowCount object
	BullCowCount bullCowCount;

	int myHiddenWordLen = myHiddenWord.length();
	int guessLen = guess.length();
	//loop through the input string
	for (int i = 0; i < myHiddenWordLen; i++) {
		for (int j = 0; j < myHiddenWordLen; j++) {
			if (guess[j] == myHiddenWord[i]) {
				if (i == j) {
					bullCowCount.Bull++;
				}
				else {
					bullCowCount.Cow++;
				}
			}
		}
	}
		// and compare against the hidden string increment the appropriate bulls and cows

	return bullCowCount;

}