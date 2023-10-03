#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

/* Grant Ferris, CS 2010 1001, 10:30 - 11:20 AM
FerrisG_Pgm3.ccp, October 9 by 11:59 PM
Purpose: To play an automated game of Rock, Paper, Scissors with two named players randomly throwing rock, paper, and scissors over an 
inputed number of rounds.
Processing: Program calculates the random hand signal that either player does and who wins in each round over an inputed number of rounds.
It then calculates the total number of wins for each side and asks if the user wants to play again or not
Output: Program displays the names for both players and how many rounds they will play. It then outputs who wins (or ties) in each round until the
last one. Error outcomes for both the number of rounds and asking the user if they want to play again are accounted for with an outputted error
message and asking for the input again.
*/

int main() {
	//Variables
	const int ROCK = 0;
	const int PAPER = 1;
	const int SCISSORS = 2;
	string player1FirstN;
	string player2FirstN;
	string player1LastN;
	string player2LastN;
	string player1Name;
	string player2Name;
	char playerChoice1;
	char playerChoice2 = 'Y';
	int player1Val;
	int player2Val;
	int play1WinCount = 0;
	int play2WinCount = 0;
	int numRounds;
	
	//Seed for random hand sign
	srand(time(NULL));

	//loop for entire game
	while (playerChoice2 == 'Y' || playerChoice2 == 'y') {
		//Reset win counts for each subsequent game
		int play1WinCount = 0;
		int play2WinCount = 0;

		//Bonus: option for first name and last name for player names
		cout << "Want to use first name and last name? (Y/N) ";
		cin >> playerChoice1;

		while (playerChoice1 != 'Y' && playerChoice1 != 'y' && playerChoice1 != 'N' && playerChoice1 != 'n') {
			cout << "Invalid Answer" << endl;
			cout << "Want to use first name and last name? (Y/N) ";
			cin >> playerChoice1;
		}

		//Inputs: first initial and last name or normal name
		if (playerChoice1 == 'Y' || playerChoice1 == 'y') {

			cout << "Enter Player 1's name: ";
			cin >> player1FirstN >> player1LastN;

			cout << "Enter Player 2's name: ";
			cin >> player2FirstN >> player2LastN;

			player1Name = player1FirstN.at(0) + player1LastN;
			player2Name = player2FirstN.at(0) + player2LastN;
		}
		else {
			cout << "Enter Player 1's name: ";
			cin >> player1Name;

			cout << "Enter Player 2's name: ";
			cin >> player2Name;
		}

		//Input for rounds
		cout << "Enter number of rounds: ";
		cin >> numRounds;
		cout << "\n";

		//Error check
		while (numRounds <= 0) {
			cout << "Rounds must be > 0" << endl;

			cout << "Enter number of rounds: ";
			cin >> numRounds;
			cout << "\n";
		}

		//Bonus: set separator to header length
		int N = player1Name.length() + player2Name.length() + to_string(numRounds).length() + 20;
		
		//First output
		cout << player1Name << " vs. " << player2Name << " for " << numRounds << " round(s)" << endl;
		cout << setw(N) << setfill('-') << "\n";

		//main loop for processing and outputs
		for (int i = 0; i < numRounds; ++i) {

			//Randomly assigning hand signals and tieing when necessary
			do {
				player1Val = rand() % 3;
				player2Val = rand() % 3;

				if (player1Val == player2Val) {
					cout << "Tie" << endl;
				}

			} while (player1Val == player2Val);

			//Possible Outputs
			if (player1Val == ROCK) {

				if (player2Val == SCISSORS) {
					cout << player1Name << " wins with rock" << endl;
					++play1WinCount;
				}
				else {
					cout << player2Name << " wins with paper" << endl;
					++play2WinCount;
				}
			}
			if (player1Val == SCISSORS) {

				if (player2Val == PAPER) {
					cout << player1Name << " wins with scissors" << endl;
					++play1WinCount;
				}
				else {
					cout << player2Name << " wins with rock" << endl;
					++play2WinCount;
				}
			}
			if (player1Val == PAPER) {

				if (player2Val == ROCK) {
					cout << player1Name << " wins with paper" << endl;
					++play1WinCount;
				}
				else {
					cout << player2Name << " wins with scissors" << endl;
					++play2WinCount;
				}
			}
		}

		//Final output
		cout << setw(N) << setfill('-') << "\n";
		cout << player1Name << " wins " << play1WinCount << " and " << player2Name << " wins " << play2WinCount << endl;

		//User choice to end or continue
		cout << "Want to play again? (Y/N) " << endl;
		cin >> playerChoice2;
		
		//Error check
		while (playerChoice2 != 'Y' && playerChoice2 != 'y' && playerChoice2 != 'N' && playerChoice2 != 'n') {
			cout << "Invalid Answer" << endl;

			cout << "Want to play again? (Y/N) " << endl;
			cin >> playerChoice2;
		}

		if (playerChoice2 == 'N' || playerChoice2 == 'n') {
			exit(0);
		}
		
	}
		return 0;
}