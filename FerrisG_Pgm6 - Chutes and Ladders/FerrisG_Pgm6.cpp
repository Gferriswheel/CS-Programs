#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

/* Grant Ferris, CS 2010 1001, 10:30 - 11 : 20 AM
FerrisG_Pgm6.ccp, October 13 by 11:59 PM
Purpose: To play a modified children's game, “Chutes and Ladders”. The game is played 
on a board which contains 100 squares. Two Players start at square 1 and roll an octahedron for how many spaces. If they reach 100 or above they win
but there are special chutes and ladder spaces that will move a player's position up or down if they hit them.
Input: Only the names of the two players.
Processing: calculates a random number from 1 to 8 to roll the dice and updates player's position with it. It then checks if new position is on chute or 
ladder and then calculates the same for the other player. Calculates the winner of the game depending on who reaches 100 or above first
Output: creates borders and separators along with accounting for the length of names and numbers when formatting the output. It outputs names, move number,
current position, dice number, and new position of each player. Also, outputs winner of the game.
*/

//function declarations (function definitions after main)
void printHeader();
bool checkWin(int player1Position, int player2Position);
int rollDice();
void checkChutes(int& playPosition);
void checkLadders(int& playPosition);
void movePlayer(int& playPosition, int diceNumber);
void printOneMove(string playName1, string playName2, int playPos1, int playPos2, int moveCount, int prevPos1, int prevPos2, int dieNum1, int dieNum2);

//global variables used in different variables that aren't specific to the program but to formatting
const string PRINTSPACES = "           ";
int nameleftoverSpace;


int main() {
	string player1Name;
	string player2Name;
	int play1Pos = 1;
	int play2Pos = 1;
	int play1PrevPos;
	int play2PrevPos;
	int dieNum1;
	int dieNum2;
	int moveCount = 1;
	

	srand(time(NULL));

	//names input
	cout << "Player 1 Name: ";
	cin >> player1Name;
	cout << "Player 2 Name: ";
	cin >> player2Name;
	
	//accounting for differences in name sizes + printing header
	if (player1Name.size() >= player2Name.size()) {
		nameleftoverSpace = player1Name.size();
	}
	else {
		nameleftoverSpace = player2Name.size();
	}
	printHeader();

	//main loop where dice is rolled for each player along with calculating new positions and printing table out. Ends when a player reaches 100+
	while (checkWin(play1Pos, play2Pos) == false) {

		//holds original position before die number
		play1PrevPos = play1Pos;
		play2PrevPos = play2Pos;

		dieNum1 = rollDice();
		movePlayer(play1Pos, dieNum1);
		dieNum2 = rollDice();
		movePlayer(play2Pos, dieNum2);
		printOneMove(player1Name, player2Name, play1Pos, play2Pos, moveCount, play1PrevPos, play2PrevPos, dieNum1, dieNum2);
		++moveCount;
	}

	cout << endl;

	//detecting who won
	if (play1Pos >= 100) {
		cout << "The winner is " << player1Name << "!";
	}
	else {
		cout << "The winner is " << player2Name << "!";
	}

	return 0;
}

//prints main header before table
void printHeader() {

	cout << "Player     Move Number     Curr Position        Die      New Position\n";
	cout << setw(70) << setfill('*') << "" << endl;;

}

//checks if a player has reached 100 or higher 
bool checkWin(int player1Position, int player2Position) {

	if (player1Position >= 100 || player2Position >= 100) {
		return true;
	}
	return false;
}

//generates random number for dice roll for a player
int rollDice() {

	int numOfSpaces;
	
	numOfSpaces = rand() % 8;

	return numOfSpaces;
}

// determines if player lands on a chute
void checkChutes(int& playPosition) {

	if (playPosition == 8) {
		playPosition = 1;
	}
	if (playPosition == 13) {
		playPosition = 3;
	}
	if (playPosition == 24) {
		playPosition = 18;
	}
	if (playPosition == 36) {
		playPosition = 29;
	}
	if (playPosition == 51) {
		playPosition = 37;
	}
	if (playPosition == 64) {
		playPosition = 54;
	}
	if (playPosition == 86) {
		playPosition = 44;
	}
}

// determines if player lands on a ladder
void checkLadders(int& playPosition) {
	
	if (playPosition == 7) {
		playPosition = 19;
	}
	if (playPosition == 12) {
		playPosition = 27;
	}
	if (playPosition == 28) {
		playPosition = 41;
	}
	if (playPosition == 39) {
		playPosition = 50;
	}
	if (playPosition == 53) {
		playPosition = 62;
	}
	if (playPosition == 66) {
		playPosition = 78;
	}
	if (playPosition == 75) {
		playPosition = 91;
	}
}

//updates player position along with calling to check if they landed on a shoot or ladder
void movePlayer(int& playPosition, int diceNumber) {

	playPosition += diceNumber;
	checkChutes(playPosition);
	checkLadders(playPosition);

}

//prints both player's information along with formatting for differences in name size and number of digits in each variable
void printOneMove(string playName1, string playName2, int playPos1, int playPos2, int moveCount, int prevPos1, int prevPos2, int dieNum1, int dieNum2) {

	cout << left << setw(nameleftoverSpace) << setfill(' ') << playName1;
	cout << PRINTSPACES << left << setw(2) << setfill(' ') << moveCount;
	cout << PRINTSPACES + "   " << left << setw(2) << setfill(' ') << prevPos1;
	cout << PRINTSPACES + "   " << left << setw(2) << setfill(' ') << dieNum1;
	cout << PRINTSPACES + " " << left << setw(2) << setfill(' ') << playPos1 << endl;

	if (playPos1 < 100) {
		// if statement stops the 2nd player from being printed if player 1 already won
		cout << left << setw(nameleftoverSpace) << setfill(' ') << playName2;
		cout << PRINTSPACES << left << setw(2) << setfill(' ') << moveCount;
		cout << PRINTSPACES + "   " << left << setw(2) << setfill(' ') << prevPos2;
		cout << PRINTSPACES + "   " << left << setw(2) << setfill(' ') << dieNum2;
		cout << PRINTSPACES + " " << left << setw(2) << setfill(' ') << playPos2 << endl;
		cout << setw(70) << setfill('-') << "" << endl;
	}
}