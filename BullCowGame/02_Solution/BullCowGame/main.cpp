#include <iostream>
#include <string>
#include "FBullCowGame.h"
void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();
FBullCowGame BCGame; //New Game Instance
int main()
{
	std::cout << BCGame.GetCurrentTry();

	bool bPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
	return 0;
}
void PrintIntro()
{
	// Introduce the game
	constexpr int WORD_LENGHT = 666; // Apofygh "magic numbers", eukolh allagh metavliths se olo to programma.
	std::cout << "Welcome to BullCowGame game!\n"
		<< "Can you guess the " << WORD_LENGHT
		<< "th letter isogram I'm thinking of? \n";
	return;
}
void PlayGame()
{
	BCGame.Reset();
	FBullCowGame BCGame; //New Game Instance
	int MaxTries = BCGame.GetMaxTries();
	std::cout << "The Maximum number of tries is: " << MaxTries << std::endl;
	for (int count = 1; count <= MaxTries; count++)
	{
		std::string Guess = GetGuess();
		std::cout <<"Your Guess Is: "<< Guess << std::endl;
	}
}
std::string GetGuess()
{
	int ThisCurrentTry = BCGame.GetCurrentTry();
	std::cout << "The current try is: " << ThisCurrentTry << std::endl;
	// Get a guess from the player.
	std::cout << "Please enter your Guess: ";
	std::string Guess = "";
	getline(std::cin, Guess);
	return Guess;
}
bool AskToPlayAgain()
{
	std::cout << "Do You Want To Play Again? (y,n)\n";
	std::string Response = "";
	getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');


}
