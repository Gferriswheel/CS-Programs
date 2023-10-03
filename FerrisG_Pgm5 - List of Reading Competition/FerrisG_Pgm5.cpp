#include <iostream>
#include <fstream>
using namespace std;

/* Grant Ferris, CS 2010 1001, 10:30 - 11:20 AM
FerrisG_Pgm5.ccp, October 30 by 11:59 PM
Purpose: To list the readers in the reading competition with their names and books read while also displaying who read the most, who read the least, and how many
books were read in total by everyone. 
Input: Data is taken from pgm5.txt
Processing: caclulates highest read reader (including name, # of books, and reader #), lowest read reader (including name, # of books, and reader #), and
total books read along with accounting for negative values and checking for opening input file.
Output: Lists readers with their names and number of books they read. Also outputs the person who read the most and who read the least along with the total
books read by everyone.
*/

int main() {
	ifstream inFS;
	const int MAX_BOOKS = 25;
	string readerArray[MAX_BOOKS];
	int bookArray[MAX_BOOKS];
	string readerName;
	int bookNum;
	int numReaderCount = 0;
	
	string highestName;
	int highestBooks;
	int highestNum;
	string lowestName;
	int lowestBooks;
	int lowestNum;
	int totalBooks = 0;
	int i;
	
	inFS.open("pgm5.txt");

	//error check for opening input file
	if (!inFS.is_open()) {
		cout << "ERROR: could not open input file";
		return 1;
	}

	//main while loop for reading and storing inputs
	while (!inFS.eof()) {
		
		inFS >> readerName;
		readerArray[numReaderCount] = readerName;
		inFS >> bookNum;
		bookArray[numReaderCount] = bookNum;
		numReaderCount++;
	}
	inFS.close();

	//setting highest and lowest variables
	highestBooks = bookArray[0];
	lowestBooks = bookArray[0];

	/*Processing for negative values, highest reader(including name, # of books, and reader #), lowest reader(including name, # of books, and reader #), and
	total books read*/
	for (i = 0; i < numReaderCount; ++i) {
		if (bookArray[i] < 0) {
			bookArray[i] = -1 * bookArray[i];
		}
		if (bookArray[i] > highestBooks) {
			highestBooks = bookArray[i];
			highestName = readerArray[i];
			highestNum = i + 1;
		}
		if (bookArray[i] < lowestBooks) {
			lowestBooks = bookArray[i];
			lowestName = readerArray[i];
			lowestNum = i + 1;
		}
		totalBooks += bookArray[i];
	}

	//Main output
	for (i = 0; i < numReaderCount; ++i) {
		cout << "Reader " << i + 1 << " who is named " << readerArray[i] << " read " << bookArray[i] << " books." << endl;
	}

	//Variable outputs
	cout << "The winner is Reader " << highestNum << " who is named " << highestName << " by reading " << highestBooks << " books." << endl;
	cout << "Reader " << lowestNum << " who is named " << lowestName << " read the least number of books: " << lowestBooks << "." << endl;
	cout << "And in total all Readers read " << totalBooks << " books." << endl;


	return 0;
}



