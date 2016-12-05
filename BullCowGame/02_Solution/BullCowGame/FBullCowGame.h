#pragma once
#include <string>
using FString = std::string;
using int32 = int;
//All values initialized to 0
struct FBullCowCount 
{
	int32 Bulls = 0;
	int32 Cows = 0;

};
enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_LowerCase
};
class FBullCowGame
{
public:
	FBullCowGame(); //constructor
	void Reset(); // TODO Make a rich return value
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLenght() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValitidy(FString) const; // TODO Make a rich return value
	// Counts Bulls And Cows And Increases Try Number, Assuming That Guess Is Valid
	FBullCowCount SubmitGuess(FString);
private:
	int32 MyCurrentTry; //initialized in constructor
	int32 MyMaxTries;
	bool IsIsogram;
	FString MyHiddenWord;
};