#pragma once
#include <string>
class FBullCowGame
{
public:
	FBullCowGame(); //constructor
	void Reset(); // TODO Make a rich return value
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGameValid(std::string); // TODO Make a rich return value
private:
	int MyCurrentTry; //initialized in constructor
	int MyMaxTries;
	bool IsIsogram;
};