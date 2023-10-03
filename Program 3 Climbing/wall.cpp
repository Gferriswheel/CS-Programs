// Program #3 – The Wall
// Programmer:  Grant Ferris
// Class:  CS 2020 1002, Spring 2023
// Due Date: Mar 5, 2023
// Purpose of program: Create a program that 
// will create a race between two players from a starting point. 
// Players can either radnomly climb or drop 1 to 3 numbers at a time. Whoever reaches 20 first wins the race.
//It will output the racing numbers and starting/ending lines along with updating positions of players in real time by clearing the screen and reoutputting
//everything each time.
//These are the functions used in the Climber class in the function.
#include <iostream>
#include "wall.h"
#include <cstdlib>
using namespace std;
const int TOP_OF_WALL = 20;

//constructor
Climber::Climber(string cName) {
	name = cName;
	position = 0;

}

//main climb function that randomly moves the player up 1 to 3 numbers
void Climber::Climb() {
	int addPos;

	addPos = rand() % 3;
	++addPos;

	if ((position + addPos) <= TOP_OF_WALL) {
		position += addPos;
	}
}

//main drop function that randomly moves the player down 1 to 3 numbers
void Climber::Drop() {
	int minPos;

	minPos = rand() % 3;
	++minPos;

	if ((position - minPos) > 0) {
		position -= minPos;
	}
}