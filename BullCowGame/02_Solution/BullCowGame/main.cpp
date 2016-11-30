#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();
int main()
{
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
	constexpr int WORD_LENGHT = 2; // Apofygh "magic numbers", eukolh allagh metavliths se olo to programma.
	cout << "Welcome to BullCowGame game!\n"
		<< "Can you guess the " << WORD_LENGHT
		<< "th letter isogram I'm thinking of? \n";
	return;
}
void PlayGame()
{
	constexpr int NUM_GUESSES = 5;
	for (int count = 1; count <= NUM_GUESSES; count++)
	{
		string Guess = GetGuess();
		cout <<"Your Guess Is: "<< Guess << endl;
	}
}
string GetGuess()
{
	// Get a guess from the player.
	cout << "Please enter your Guess: ";
	string Guess = "";
	getline(cin, Guess);
	return Guess;
}
bool AskToPlayAgain()
{
	cout << "Do You Want To Play Again? (y,n)\n";
	string Response = "";
	getline(cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');


}
