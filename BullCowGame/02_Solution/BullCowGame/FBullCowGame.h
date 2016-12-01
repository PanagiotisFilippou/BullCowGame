#pragma once
#include <string>

using FString = std::string;
using int32 = int;

class FBullCowGame
{
public:
	FBullCowGame(); //constructor
	void Reset(); // TODO Make a rich return value
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGameValid(FString); // TODO Make a rich return value
	// provide a method for counting Bulls and Cows and increasing try number
private:
	int32 MyCurrentTry; //initialized in constructor
	int32 MyMaxTries;
	bool IsIsogram;
};