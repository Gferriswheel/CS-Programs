#include <iostream>
#include <windows.h>
#include <fstream>
#include <iomanip>
using namespace std;

/* Grant Ferris, CS 2010 1001, 10:30 - 11 : 20 AM
FerrisG_Pgm4.ccp, October 19 by 11:59 PM
Purpose: To create a bar graph based on data in separate text documents that stops at the sentinel value 9999. 
Also to to show the number of invalid values in the documents and the 3 smallest and 3 biggest values in them. Negative values 
are turned positive and their bar is colored blue and too high values are capped and colored red. Also checks for invalid inputs and error file opening.
Processing: caclulates the bars of the bar graph using the values in the text documents to make them out of X's and checks if the
value is negative or too high which is corrected and increases the invalid value count at the end. Also calculates the 3 smallest
and 3 biggest values. Also checks for invalid inputs and error file opening.
Output: Creates a bar graph with blue colors for values that were negative before and red for too high values. Also outputs the 
3 smallest, 3 biggest, and invalid numbers in the documents. Also outputs error messages for opening the input file (also the output file) and missing.txt.
*/

int main() {
	ifstream inFS;
	ofstream outFS; //BONUS: output file
	const string SPACE = "        ";
	const char X = 'X';
	string fileName;
	int userFileChoice;
	int fileInput = 0;
	int big1 = 0; //biggest
	int big2 = 0;
	int big3 = 0;
	int small1 = 0; //smallest
	int small2 = 0;
	int small3 = 0;
	int invalidCount = 0;
	int xAxis = 1;
	int inputCount = 1;
	HANDLE hConsole;
	//setting up colors
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	const int WHITE = 7;

	//loop for file input
	do {
		cout << "select file to process:\n" << "1. mixed.txt\n" << "2. valid.txt\n" << "3. three.txt\n" << "4. missing.txt\n\nChoice: ";
		cin >> userFileChoice;

		if ((!(userFileChoice >= 1 && userFileChoice <= 4))) { /*input being a letter causes a error state and failbit
			is set and cin is not declared again. To fix this I  cleared the error state and then ignore the wrong input until \n.*/
			system("cls");
			cin.clear();
			cin.ignore(256, '\n');
			
		}
	} while (!(userFileChoice >= 1 && userFileChoice <= 4));

	//switch for which file to open + error message
	switch (userFileChoice) {
	case 1:
		inFS.open("mixed.txt");
		fileName = "mixed.txt";
		break;
	case 2:
		inFS.open("valid.txt");
		fileName = "valid.txt";
		break;
	case 3:
		inFS.open("three.txt");
		fileName = "three.txt";
		break;
	case 4:
		cout << "ERROR: Data file not found";
		return 1;
	}
	//BONUS: open to output file
	outFS.open("bar-graph.txt");

	//BONUS: error check for opening output file
	if (!outFS.is_open()) {
		cout << "ERROR: could not open output file";
		return 1;
	}
	//error check for input file opening
	if (!inFS.is_open()) {
		cout << "ERROR: could not open input file";
		return 1;
	}
	cout << "Bar graph for data contained in " << fileName << " file.\n";
	outFS << "Bar graph for data contained in " << fileName << " file.\n";

	//main loop for file input and bar graph output
	while (fileInput != 9999) {
		inFS >> fileInput;

		//breaks the loop before program tries to graph 9999 X's
		if (fileInput == 9999) {
			break;
		}

		// setup for smallest and biggest values
		if (big1 == 0) {
			big1 = fileInput;
			big2 = fileInput;
			big3 = fileInput;
			small1 = fileInput;
			small2 = fileInput;
			small3 = fileInput;
		}

		//processing for smallest and biggest values
		if (fileInput > big1) {
			big3 = big2;
			big2 = big1;
			big1 = fileInput;
		}
		else if (fileInput > big2) {
			big3 = big2;
			big2 = fileInput;
		}
		else if (fileInput > big3) {
			big3 = fileInput;
		}

		if (fileInput < small1) {
			small3 = small2;
			small2 = small1;
			small1 = fileInput;
		}
		else if (fileInput < small2) {
			small3 = small2;
			small2 = fileInput;
		}
		else if (fileInput < small3) {
			small3 = fileInput;
		}

		//start of bar graph output with number count and separators (separate so this part doesn't change colors)
		if (inputCount < 10) {
			cout << " " << inputCount << " || ";
			outFS << " " << inputCount << " || ";
		}
		else {
			cout << inputCount << " || ";
			outFS << inputCount << " || ";
		}

		//check for negative values and invalid value count. Also changing color to blue.
		if (fileInput < 0) {
			fileInput = fabs(fileInput);
			++invalidCount;
			SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE);
		}

		//check for too high values and changing color to red.
		if (fileInput > 114 && fileInput != 9999) {
			fileInput = 114;
			SetConsoleTextAttribute(hConsole, BACKGROUND_RED);
			++invalidCount;
		}
		
		//rest of bar graph output with the actual bars and changing colors
		if (inputCount < 10) {
			for (int i = 0; i < fileInput; ++i) {
				cout << X;
				outFS << X;
			}
			cout << "" << "\n";
			outFS << "" << "\n";
			++inputCount;
		}
		else {
			for (int i = 0; i < fileInput; ++i) {
				cout << X;
				outFS << X;
			}
			cout << "" << "\n";
			outFS << "" << "\n";
			++inputCount;
		}
		SetConsoleTextAttribute(hConsole, WHITE);
	}
	inFS.close();

	//axis for the bar graph
	cout << setw(120) << setfill('-') << "" << "\n" << "      \n";
	outFS << setw(120) << setfill('-') << "" << "\n" << "      \n";
	
	for (int i = 0; i < 12; ++i) {
		cout << xAxis << SPACE;
		outFS << xAxis << SPACE;
		if (xAxis == 1) {
			xAxis += 9;
		}
		else {
			xAxis += 10;
		}
	}

	//Not enough data for unique values for each of the smallest and biggest values
	if ((small1 == small2) && (small1 == small3) && (small2 == small3)) {
		small2 = big2;
		small3 = big1;
	}

	//Value outputs for smallest, biggest, and invalid values
	cout << "\nSMALLEST\n" << "========\n" << "The smallest value: " << small1 << "\nThe second smallest value: " << small2;
	cout << "\nThe third smallest value: " << small3 << "\n\n";

	outFS << "\nSMALLEST\n" << "========\n" << "The smallest value: " << small1 << "\nThe second smallest value: " << small2;
	outFS << "\nThe third smallest value: " << small3 << "\n\n";

	cout << "\BIGGEST\n" << "=======\n" << "The biggest value: " << big1 << "\nThe second biggest value: " << big2;
	cout << "\nThe third biggest value: " << big3 << "\n";

	outFS << "\BIGGEST\n" << "=======\n" << "The biggest value: " << big1 << "\nThe second biggest value: " << big2;
	outFS << "\nThe third biggest value: " << big3 << "\n";

	cout << "\nINVALID\n" << "=======\n" << "There are " << invalidCount << " invalid values in the data.";

	outFS << "\nINVALID\n" << "=======\n" << "There are " << invalidCount << " invalid values in the data.";

	outFS.close();
	return 0;
}