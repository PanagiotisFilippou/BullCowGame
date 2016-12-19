#pragma once
#include "FBullCowGame.h"
#include<map>
#define TMap std::map
FBullCowGame::FBullCowGame()
{
	Reset();
}// default constructor
int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}
int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}
bool FBullCowGame::IsGameWon() const
{
	return bGameIsWon;
}
int32 FBullCowGame::GetMaxTries() const
{
	TMap<int32, int32> WordLenghtToMaxTries{ {3, 4}, {4, 7}, {5, 10}, {6, 16}, {7, 25} };
	return WordLenghtToMaxTries[MyHiddenWord.length()];//returns the matching no. of tries with word lenght
}
void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 7;
	const FString HIDDEN_WORD = "ant"; // this MUST be an isogram
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}
EGuessStatus FBullCowGame::CheckGuessValitidy(FString Guess) const
{
	if (!IsIsogram(Guess)) // if the quess is not an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowerCase(Guess))
	{
		return EGuessStatus::Not_LowerCase;
	}
	else if (Guess.length() != GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;

	}
}
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess) // Receives a VALID guess, incriments turn, returns count. 
{
	MyCurrentTry++;
	//setup reset variable
	FBullCowCount BullCowCount;
	//loop all letters in hidden word
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 MyHiddenWordChar = 0; MyHiddenWordChar < HiddenWordLength; MyHiddenWordChar++)
	{
		//compare letters against the hidden word
		for (int32 GuessChar = 0; GuessChar < HiddenWordLength; GuessChar++)
		{
			// if they match then:
			if (Guess[GuessChar] == MyHiddenWord[MyHiddenWordChar])
			{
				if (MyHiddenWordChar == GuessChar)
				{
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++;
				}

				// if in same place
					// incriment bulls
				// incriment cows if not ath the same place
					// incriment cows
			}
		}
	}
	if (BullCowCount.Bulls == HiddenWordLength)
	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;

	}
	return BullCowCount;
}
bool FBullCowGame::IsIsogram(FString Word) const
{
	if (Word.length() <= 1) // all 0 and 1 words are isogram obviously 
	{
		return true;
	}

	TMap<char, bool> LetterSeen; // map setup
	for (auto Letter : Word) // ranged based for loop, for all letters of word
	{
		Letter = tolower(Letter); // handle mixed case
		if (LetterSeen[Letter]) // if letter is in the map
		{
			return false; // we do not have an isogram
		}
		else
		{
			LetterSeen[Letter] = true; // add letter to map as seen
		}
	}

	return true;
}

bool FBullCowGame::IsLowerCase(FString Word) const
{
	for (auto Letter : Word)
	{
		if (!islower(Letter))// if not a lower case letter 
		{
			return false;
		}
	}
	return true;
}
