// Program #3 – The Wall
// Programmer:  Grant Ferris
// Class:  CS 2020 1002, Spring 2023
// Due Date: Mar 5, 2023
// Purpose of program: Create a program that 
// will create a race between two players from a starting point. 
// Players can either radnomly climb or drop 1 to 3 numbers at a time. Whoever reaches 20 first wins the race.
//It will output the racing numbers and starting/ending lines along with updating positions of players in real time by clearing the screen and reoutputting
//everything each time.
//This is the header file for the Climber class used in the program
#ifndef WALLH
#define WALLH
#include <string>
#include <cstdlib>
using namespace std;

//main class containing a cosntructor, accessors, and the main climb and drop functions
class Climber {
private:

	string name;
	int position;

public:

	Climber(string cName);
	string GetName() const { return name; }
	int GetPosition() const { return position; }
	void Climb();
	void Drop();

	};


#endif