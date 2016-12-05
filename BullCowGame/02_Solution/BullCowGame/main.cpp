/*
Console executable. Uses BullCowGame class
Acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
FBullCowGame BCGame; //New Game Instance
int main()
{
	bool bPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		//TODO add a game summarize
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
	return 0;
}
void PrintIntro()
{
	// Introduce the game
	std::cout << "Welcome to BullCowGame game!\n"
		<< "Can you guess the " << BCGame.GetHiddenWordLenght()
		<< "th letter isogram I'm thinking of? \n";
	return;
}
void PlayGame()
{
	BCGame.Reset();
	FBullCowGame BCGame; //New Game Instance ??????????
	int32 MaxTries = BCGame.GetMaxTries();
	// loop for the number of turns asking for quesses
	std::cout << "The Maximum number of tries is: " << MaxTries << std::endl << std::endl;
	for (int32 count = 1; count <= MaxTries; count++)// TODO change from FOR to WHILE loop ince we are validating tries
	{
		FText Guess = GetValidGuess(); // TODO make loop checking valid guesses

		// Submit valid guess to the game, receive count
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		std::cout << "Bulls = " << BullCowCount.Bulls << std::endl;
		std::cout << "Cows = " << BullCowCount.Cows << "\n\n";
		std::cout << "Your Guess Is: " << Guess << std::endl;
	}
	// TODO summarise game
}
// loop continually until the user gives a valid guess
FText GetValidGuess()
{
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do
	{
		// Get a guess from the player.
		int32 ThisCurrentTry = BCGame.GetCurrentTry();
		std::cout << "The current try is: " << ThisCurrentTry << std::endl;
		std::cout << "\nPlease enter your Guess: " << std::endl;
		FText Guess = "";
		getline(std::cin, Guess);

		Status = BCGame.CheckGuessValitidy(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLenght() << " letter word.\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word withoutt repeating letters.\n";
			break;
		case EGuessStatus::Not_LowerCase:
			std::cout << "Please anter all lower case letters.\n";
			break;
		default:
			return Guess;
		} 
		std::cout << "\n";
	} while (Status != EGuessStatus::OK); // Keep looping until we get no errors
}
bool AskToPlayAgain()
{
	std::cout << "Do You Want To Play Again? (y,n)\n";
	FText Response = "";
	getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');


}
