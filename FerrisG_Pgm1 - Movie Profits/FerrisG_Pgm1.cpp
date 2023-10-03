#include <iostream>
#include <iomanip>
using namespace std;

/* Grant Ferris, CS 2010 1001, 10:30 - 11:20 AM
FerrisG_Pgm1.ccp, September 12 by 11:59 PM
Purpose: to calculate the gross ticket sales, theater net profits, and distributor profits for a certain movie at a local movie theater
Input: program uses the movie name (not used for calculations), number of adult tickets sold, and number of child tickets sold for said movie
Processing: program calculates the gross ticket sales by multiplying adult and child ticket numbers by their respective prices. Then, calculates the
theater net profits and distributor profits based on their percentage of the movie revenue which are 20% and 80% respectively
Output: program displays the gross ticket sales and the profits of the theater and distributor of the movie
*/

int main() {
	// variables
	const double ADULTTICKETPRICE = 10.00;
	const double CHILDTICKETPRICE = 6.00;
	string movieName;
	int numTicketAdult;
	int numTicketChild;
	double grossTicketSales;
	double theaterNetProfits;
	double distributorProfits;

	// input questions for movie name and adult/child ticket numbers
	cout << "Enter the movie name: ";
	cin >> movieName;

	cout << "How many adult tickets were sold: ";
	cin >> numTicketAdult;

	cout << "How many children's tickets were sold: ";
	cin >> numTicketChild;

	// calculations for gross ticket sales, theater net profits, and distributor profits
	grossTicketSales = (numTicketAdult * ADULTTICKETPRICE) + (numTicketChild * CHILDTICKETPRICE);
	theaterNetProfits = grossTicketSales * 0.20;
	distributorProfits = grossTicketSales * 0.80;

	// output for previous calculations
	cout << fixed << setprecision(2) << endl;

	cout << "Gross Ticket Sales: $" << grossTicketSales << endl;
	cout << "Theater Net Profit: $" << theaterNetProfits << endl;
	cout << "Amount Paid to Distributor: $" << distributorProfits << endl;

	return 0;
}