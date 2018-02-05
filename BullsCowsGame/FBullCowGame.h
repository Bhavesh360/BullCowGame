#pragma once
#include <string>

enum class EGuessStatus {
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_LowerCase
};



struct BullCowCount {
	int Bull = 0;
	int Cow = 0;
};


class FBullCowGame {
public:
	FBullCowGame();
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(std::string guess) const;
	int GetWordLength() const;

	bool FBullCowGame::CheckLowerCase(std::string guess);
	void Reset();
	BullCowCount SubmitGuess(std::string guess);

private:
	int MyCurrentTry;
	int MyMaxTries;
	std::string myHiddenWord;
};