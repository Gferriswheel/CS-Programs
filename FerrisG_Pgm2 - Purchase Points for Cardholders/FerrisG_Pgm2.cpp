#include <iostream>
using namespace std;

/* Grant Ferris, CS 2010 1001, 10:30 - 11:20 AM
FerrisG_Pgm2.ccp, September 25 by 11:59 PM
Purpose: To find the total number of points cardholders of the Adventure Campus Rewards have based off their purchases.
Then calculate what rewards they earned while giving preference to certain rewards based on their input and showing leftover points.
Input: Program uses the money used on entertainment, food, and other purchases as input. It also asks for user's preference of reward when 
calculating their available rewards.
Processing: Program calculates total number of points cardholders have based on adding up their converted points from their purchases. 
It then calcualtes what rewards they have earned including movie rentals, pizzas, or Itunes downloads while factoring in the user's preferred reward.
It also calculates leftover points at the end aswell.
Output: program displays the total points the cardholder has and the rewards they have earned based on their preference of reward. 
Also, it displays any leftover points left.
*/

int main() {
	//Variables
	int entPurch;
	int foodPurch;
	int otherPurch;
	int totalPoints;
	int movieRent = 0;
	int pizza = 0;
	int itunesDown = 0;
	int leftoverPoints = 0;
	char userPref;
	char placeholder; //placeholder to hold $ symbol in inputs
	const int ENTPOINTS = 5;
	const int FOODPOINTS = 2;
	const int OTHERPOINTS = 1;

	//Inputs for points
	cout << "Adventure Campus Rewards Program" << endl;
	cout << endl;

	cout << "Enter dollar amount of your Entertainment purchases (with $): ";
	cin >> placeholder >> entPurch;

	cout << "Enter dollar amount of your Food purchases:                   ";
	cin >> placeholder >> foodPurch;

	cout << "Enter dollar amount of any other purchases:                   ";
	cin >> placeholder >> otherPurch;

	//Processing for total points
	totalPoints = (entPurch * ENTPOINTS) + (foodPurch * FOODPOINTS) + (otherPurch * OTHERPOINTS);

	//Output for total points
	cout << "\nTotal number of points earned:                                " << totalPoints << "\n" << endl;

	//Inputs for rewards
	cout << "Enter your first choice for rewards - (M)ovies, (P)izzas or (I)tunes: ";
	cin >> userPref;

	//Error check for preference
	if (userPref != 'M' && userPref != 'P' && userPref != 'I') {
		cout << "Error: Invalid Input";
		exit(0);
	}

	//Processing for rewards based on user preference
	if (userPref == 'M') {
		movieRent = totalPoints / 150;
		totalPoints %= 150;

		itunesDown = totalPoints / 60;
		leftoverPoints = totalPoints % 60;
	}
	if (userPref == 'P') {
		pizza = totalPoints / 300;
		totalPoints %= 300;

		movieRent = totalPoints / 150;
		totalPoints %= 150;

		itunesDown = totalPoints / 60;
		leftoverPoints = totalPoints % 60;
	}
	if (userPref == 'I') {
		itunesDown = totalPoints / 60;
		leftoverPoints = totalPoints % 60;
	}

	//Output for rewards
	cout << "\nYou have earned the following rewards for your credit card purchases!\n" << endl;
	cout << pizza << " Pizzas (300 points each)" << endl;
	cout << movieRent << " Movie rentals (150 points each)" << endl;
	cout << itunesDown << " iTunes downloads (60 points each)" << endl;
	cout << leftoverPoints << " points leftover" << endl;

	return 0;
}