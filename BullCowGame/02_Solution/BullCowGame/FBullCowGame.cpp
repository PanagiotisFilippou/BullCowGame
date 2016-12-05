#include "FBullCowGame.h"
FBullCowGame::FBullCowGame()
{
	Reset();
}
int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}
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
void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "ant";
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}
EGuessStatus FBullCowGame::CheckGuessValitidy(FString Guess) const
{
	if (false)
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false)
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
