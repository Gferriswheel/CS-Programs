// Program #3 – The Wall
// Programmer:  Grant Ferris
// Class:  CS 2020 1002, Spring 2023
// Due Date: Mar 5, 2023
// Purpose of program: Create a program that 
// will create a race between two players from a starting point. 
// Players can either radnomly climb or drop 1 to 3 numbers at a time. Whoever reaches 20 first wins the race.
//It will output the racing numbers and starting/ending lines along with updating positions of players in real time by clearing the screen and reoutputting
//everything each time.

#include "wall.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include<windows.h>
using namespace std;
const int TOP_OF_WALL = 20;

int main() {
	Climber player1("Player 001");
	Climber player2("Player 002");
	int play1Turn;
	int Play2Turn;
	bool winner = false;

	unsigned seed = time(0); //use top get a different set of ramdom numbers
	srand(seed);

	while (!winner) {
		system("CLS"); //clears the screen each time to have the names look like there moving
		cout << "==================== Top of the World!! ======================= \n";
		play1Turn = (rand() % 2); //randomly generates a number from 0 to 1
		Play2Turn = (rand() % 2); // 1 means the player will climb, 0 means drop

		if (play1Turn == 1) {
			player1.Climb();
		}
		else {
			player1.Drop();
		}
		if (Play2Turn == 1) {
			player2.Climb();
		}
		else {
			player2.Drop();
		}

		//test for if player position goes below ground
		if (player1.GetPosition() < 0 || player2.GetPosition() < 0)
		{
			cout << "ERROR IN CODE" << endl;
			exit(1);
		}

		//racing output. Players' position is placed at the corresponding number on the left. 
		cout << "---------------------------------------------------------------\n";
		for (int k = TOP_OF_WALL; k >= 0; k--)
		{
			if (k == 0 || k == 19)
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<
				endl;
			cout << setw(5) << k;
			if (player1.GetPosition() == k || (k == TOP_OF_WALL &&
				player1.GetPosition() >= TOP_OF_WALL))
				cout << setw(15) << player1.GetName();
			else
				cout << setw(15) << " ";
			if (player2.GetPosition() == k || (k == TOP_OF_WALL &&
				player2.GetPosition() >= TOP_OF_WALL))
				cout << setw(15) << player2.GetName();
			cout << endl;
		}
		cout << "---------------------------------------------------------------\n";
		Sleep(400);


		//decide who the winner is. Player 1 wins in a tie
		if (player1.GetPosition() >= 20) {
			winner = true;
			cout << "Player 001 Wins!" << endl;
		}
		if (player2.GetPosition() >= 20) {
			winner = true;
			cout << "Player 002 Wins!" << endl;
		}
		if (player1.GetPosition() >= 20 && player2.GetPosition() >= 20) {
			winner = true;
			cout << "Player 001 Wins!" << endl;
		}
	}
	return 0;
}