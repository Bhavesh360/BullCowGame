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
bool FBullCowGame::IsGameWon() const { return isGameWon; }



void FBullCowGame::Reset()
{
	constexpr int MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;
	const std::string HIDDEN_WORD = "planet";
	myHiddenWord = HIDDEN_WORD;
	isGameWon = false;
	return;
}



EGuessStatus FBullCowGame::CheckGuessValidity(std::string guess) const
{	
	if (!IsIsoGram(guess)) {
		return EGuessStatus::Not_Isogram;
	}

	else if (!IsLowerCase(guess)) {
		return EGuessStatus::Not_LowerCase;
	}
	
	else if (guess.length() != GetWordLength() ) {
		return EGuessStatus::Wrong_Length;
	}
	else {
		return EGuessStatus::OK;
	}
	
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
	if (bullCowCount.Bull == GetWordLength()) {
		isGameWon = true;
	}
	else {
		isGameWon = false;
	}
		// and compare against the hidden string increment the appropriate bulls and cows

	return bullCowCount;

}

bool FBullCowGame::IsIsoGram(std::string word) const 
{	
	if (word.length() <= 1) {
		return true;
	}
	std::map<char,bool> charMap;

	for (int i = 0; i < word.length(); i++) {
		word[i] = tolower(word[i]);
		if (!charMap[word[i]]) {	
			charMap[word[i]] = true;
		}
		else {
			return false;
		}
	}

	return true; 
}

bool FBullCowGame::IsLowerCase(std::string word) const
{
	for (auto letter : word) {
		return islower(letter);
	}
}
