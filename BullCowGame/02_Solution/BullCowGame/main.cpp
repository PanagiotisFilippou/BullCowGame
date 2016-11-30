#include <iostream>
#include <string>

using namespace std;

//Functions
void PrintIntro();
string GetGuessAndPrintBack();

int main()
{
	PrintIntro();
	GetGuessAndPrintBack();
	return 0;
}

void PrintIntro()
{
	// Introduce the game
	constexpr int WORD_LENGHT = 5; // Apofygh "magic numbers", eukolh allagh metavliths se olo to programma.
	cout << "Welcome to BullCowGame game!\n"
		 << "Can you guess the " << WORD_LENGHT
		 << "th letter isogram I'm thinking of? \n";
	return;
}
string GetGuessAndPrintBack()
{
	// Get a guess from the player.
	cout << "Please enter your Guess: ";
	string Guess = "";
	getline(cin, Guess);
	cout << "Your quess was: " << Guess << endl;
	return Guess;
}