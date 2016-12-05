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
int32 FBullCowGame::GetHiddenWordLenght() const
{
	return MyHiddenWord.length();
}
bool FBullCowGame::IsGameWon() const
{
	return false;
}
FBullCowCount FBullCowGame::SubmitGuess(FString Guess) // Receives a VALID guess, incriments turn, returns count. 
{
	//incriment the turn number
	MyCurrentTry++;
	//setup reset variable
	FBullCowCount BullCowCount;
	//loop all letters in guess
	int32 HiddenWordLenght = MyHiddenWord.length();
	for (int32 MyHiddenWordChar = 0; MyHiddenWordChar < HiddenWordLenght; MyHiddenWordChar++)
	{
		//compare letters against the hidden word
		for (int32 GuessChar = 0; GuessChar < HiddenWordLenght; GuessChar++)
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
	return BullCowCount;
}
EGuessStatus FBullCowGame::CheckGuessValitidy(FString Guess) const
{
	if (false)
	{
		return EGuessStatus::Not_LowerCase;
	}
	else if (false)
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (Guess.length() != GetHiddenWordLenght())
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;

	}
}
void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	const FString HIDDEN_WORD = "ant";
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return;
}
