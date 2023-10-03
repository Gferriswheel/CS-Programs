#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
using namespace std;

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- 
// Program description:   Program runs a two player game of Tic-Tac-Toe continously until players don't want to play anymore.
// Program author:  Grant Ferris 
// Class and term:   CS2010, Fall 2022
// Reflection: This was probably the hardest and most confusing out of all the projects so fat. I learned a lot and when I actually completed I definitely
// felt great but the whole process took me a while to fully understand.
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- 




//Global constants/variables
const char PLAY1X = 'X';
const char PLAY2O = 'O';
const char SPACE = ' ';
const int COLMS = 13;
const int ROWS = 6;
bool TURN = false; //false = Player 1 and true = Player 2


//Function prototypes
void readInitialGrid(char TTTgrid[ROWS][COLMS], ifstream& inFS);
void initializeGrid(char TTTgrid[ROWS][COLMS]);
void displayGrid(char TTTgrid[ROWS][COLMS]);
bool isWin(char TTTgrid[ROWS][COLMS], int moveCount);

int main() {
	ifstream inFS;
	char choice = 'Y';
	char TTTgrid[ROWS][COLMS];
	int moveCount = 0;
	char columnInput = ' '; //starting inputs to make them false later
	char rowInput = ' ';
	char XorO;

	readInitialGrid(TTTgrid, inFS);
	

	//main while loop
	while (choice == 'Y' || choice == 'y') {
		initializeGrid(TTTgrid);
		displayGrid(TTTgrid);
		columnInput = ' '; rowInput = ' '; //resets for inputs for next game
		moveCount = 0;
		TURN = false;

		while (isWin(TTTgrid, moveCount) == false) {
			++moveCount;
			columnInput = ' '; rowInput = ' ';

			//display whose turn
			if (TURN) {
				cout << "Player 2's Move.";
				XorO = PLAY2O;
			}
			else {
				cout << "Player 1's Move.";
				XorO = PLAY1X;
			}
			cout << " Enter column [A,B, C] followed by row [1,2, 3]. => ";

			
			while ((columnInput != 'A' && columnInput != 'B' && columnInput != 'C') || (rowInput != '1' && rowInput != '2'
				&& rowInput != '3')) {
				cin >> columnInput >> rowInput;
				//correct for lowercase inputs
				columnInput = toupper(columnInput);

				//error check for incorrect position inputs
				if ((columnInput != 'A' && columnInput != 'B' && columnInput != 'C') || (rowInput != '1' && rowInput != '2'
					&& rowInput != '3')) {
					cout << endl << "ERROR: Invalid position! Enter column [A,B, C] followed by row [1,2, 3]. => ";
				}

				//error check for already taken spots on board
				if (columnInput == 'A') {
					if (rowInput == '1' && TTTgrid[1][3] != SPACE) {
						cout << "ERROR: Spot already Taken! Enter column [A,B, C] followed by row [1,2, 3]. => ";
						columnInput = ' '; rowInput = ' ';
					}
					if (rowInput == '2' && TTTgrid[3][3] != SPACE) {
						cout << "ERROR: Spot already Taken! Enter column [A,B, C] followed by row [1,2, 3]. => ";
						columnInput = ' '; rowInput = ' ';
					}
					if (rowInput == '3' && TTTgrid[5][3] != SPACE) {
						cout << "ERROR: Spot already Taken! Enter column [A,B, C] followed by row [1,2, 3]. => ";
						columnInput = ' '; rowInput = ' ';
					}
				}
				else if (columnInput == 'B') {
					if (rowInput == '1' && TTTgrid[1][7] != SPACE) {
						cout << "ERROR: Spot already Taken! Enter column [A,B, C] followed by row [1,2, 3]. => ";
						columnInput = ' '; rowInput = ' ';
					}
					if (rowInput == '2' && TTTgrid[3][7] != SPACE) {
						cout << "ERROR: Spot already Taken! Enter column [A,B, C] followed by row [1,2, 3]. => ";
						columnInput = ' '; rowInput = ' ';
					}
					if (rowInput == '3' && TTTgrid[5][7] != SPACE) {
						cout << "ERROR: Spot already Taken! Enter column [A,B, C] followed by row [1,2, 3]. => ";
						columnInput = ' '; rowInput = ' ';
					}
				}
				else if (columnInput == 'C') {
					if (rowInput == '1' && TTTgrid[1][11] != SPACE) {
						cout << "ERROR: Spot already Taken! Enter column [A,B, C] followed by row [1,2, 3]. => ";
						columnInput = ' '; rowInput = ' ';
					}
					if (rowInput == '2' && TTTgrid[3][11] != SPACE) {
						cout << "ERROR: Spot already Taken! Enter column [A,B, C] followed by row [1,2, 3]. => ";
						columnInput = ' '; rowInput = ' ';
					}
					if (rowInput == '3' && TTTgrid[5][11] != SPACE) {
						cout << "ERROR: Spot already Taken! Enter column [A,B, C] followed by row [1,2, 3]. => ";
						columnInput = ' '; rowInput = ' ';
					}
				}
			}

			//switch to store position input in correct board cell
			switch (columnInput) {
			case 'A':

				switch (rowInput) {
				case '1':
						TTTgrid[1][3] = XorO;
						cout << endl;
						system("cls");
						cout.clear();
					break;

				case '2':
					TTTgrid[3][3] = XorO;
					cout << endl;
					system("cls");
					cout.clear();
					break;
				case '3':
					TTTgrid[5][3] = XorO;
					cout << endl;
					system("cls");
					cout.clear();
					break;
				}
				break;
			case 'B':

				switch (rowInput) {
				case '1':
					TTTgrid[1][7] = XorO;
					cout << endl;
					system("cls");
					cout.clear();
					break;

				case '2':
					TTTgrid[3][7] = XorO;
					cout << endl;
					system("cls");
					cout.clear();
					break;
				case '3':
					TTTgrid[5][7] = XorO;
					cout << endl;
					system("cls");
					cout.clear();
					break;
				}
				break;
			case 'C':

				switch (rowInput) {
				case '1':
					TTTgrid[1][11] = XorO;
					cout << endl;
					system("cls");
					cout.clear();
					break;

				case '2':
					TTTgrid[3][11] = XorO;
					cout << endl;
					system("cls");
					cout.clear();
					break;
				case '3':
					TTTgrid[5][11] = XorO;
					cout << endl;
					system("cls");
					cout.clear();
					break;
				}
				break;
			}

			// display grid and switch player turn
			displayGrid(TTTgrid);
			if (TURN) {
				TURN = false;
			}
			else {
				TURN = true;
			}
		}

		//input for asking to play again
		do {
			cout << endl << "Do you want to play again? (Y/N) ";
			cin >> choice;

			// accounting for incorrect choices
			if (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n') {

				cin.clear();
				cin.ignore(256, '\n');

			}
		} while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');

		if (choice == 'N' || choice == 'n') {
			
			break;
		}
		cout << endl;
		system("cls");
		cout.clear();
	}
	
	return 0;
}

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- 
 // Function name:   readInitialGrid
 // Function description: This function reads the data values from the input file to store the Tic-Tac-Toe board in the array.
 // Function parameters: char **TTTgrid - holds the Tic-Tac-Toe board and values, const int ROWS - rows of the array, const int COLMS - columns of array,
 // ifstream& inFS - gets data from the input file to store the Tic-Tac-Toe board
 // Funcrion return value: none
// Function author:  Grant Ferris 
// Class and term:   CS2010, Fall 2022
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-  
void readInitialGrid(char TTTgrid[ROWS][COLMS], ifstream& inFS) {
	int inputCount = 0;
	int input;

	inFS.open("pgm7-input.txt");

	//error check for opening input file
	if (!inFS.is_open()) {
		cout << "ERROR: could not open input file";
		exit(1);

	}
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLMS; ++j) {
			inFS >> input;
			TTTgrid[i][j] = static_cast<char>(input);
		}
	}
	inFS.close();
}

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- 
 // Function name:   initializeGrid
 // Function description: This function nitialize only the game cells where Xs and Os are placed after a game is played.
 // Function parameters: char **TTTgrid - holds the Tic-Tac-Toe board and values, const int ROWS - rows of the array, const int COLMS - columns of array,
 // Funcrion return value: none
// Function author:  Grant Ferris 
// Class and term:   CS2010, Fall 2022
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-  
void initializeGrid(char TTTgrid[ROWS][COLMS]) {
	TTTgrid[1][3] = SPACE; TTTgrid[3][3] = SPACE;
	TTTgrid[5][3] = SPACE; TTTgrid[1][7] = SPACE;
	TTTgrid[3][7] = SPACE; TTTgrid[5][7] = SPACE;
	TTTgrid[1][11] = SPACE; TTTgrid[3][11] = SPACE; TTTgrid[5][11] = SPACE;
}

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- 
 // Function name:   displayGrid
 // Function description: This function displays the current Tic-Tac-Toe board
 // Function parameters: char **TTTgrid - holds the Tic-Tac-Toe board and values, const int ROWS - rows of the array, const int COLMS - columns of array,
 // Funcrion return value: none
// Function author:  Grant Ferris 
// Class and term:   CS2010, Fall 2022
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-  
void displayGrid(char TTTgrid[ROWS][COLMS]) {
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 13; ++j) {

			cout << TTTgrid[i][j];
		}
		cout << endl;
	}
}
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- 
 // Function name:   iSWin
 // Function description: This function determines if a player has won the game and displays who won along with the number of moves.
 // Function parameters: char **TTTgrid - holds the Tic-Tac-Toe board and values, const int ROWS - rows of the array, const int COLMS - columns of array,
 // int moveCount - number of moves taken in the game
 // Funcrion return value: bool result - false if noone has won and true if someone did
// Function author:  Grant Ferris 
// Class and term:   CS2010, Fall 2022
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
bool isWin(char TTTgrid[ROWS][COLMS], int moveCount) {

	//checks for every possible win condition
	for (int i = 1; i < ROWS; i = i + 2) {
		if (TTTgrid[i][3] == TTTgrid[i][7] && TTTgrid[i][7] == TTTgrid[i][11] && TTTgrid[i][3] != SPACE) {
			cout << endl;
			if (TURN) {
				cout << "Player 1 wins in " << moveCount << " moves!";
			}
			else {
				cout << "Player 2 wins in " << moveCount << " moves!";
			}

			return true;
		}
		else {
			for (int i = 3; i < COLMS; i = i + 4) {
				if (TTTgrid[1][i] == TTTgrid[3][i] && TTTgrid[3][i] == TTTgrid[5][i] && TTTgrid[1][i] != SPACE) {
					if (TURN) {
						cout << endl << "Player 1 wins in " << moveCount << " moves!";
					}
					else {
						cout << endl << "Player 2 wins in " << moveCount << " moves!";
					}

					return true;
				}
				else if (TTTgrid[1][3] == TTTgrid[3][7] && TTTgrid[3][7] == TTTgrid[5][11] && TTTgrid[1][3] != SPACE ||
					TTTgrid[5][3] == TTTgrid[3][7] && TTTgrid[3][7] == TTTgrid[1][11] && TTTgrid[5][3] != SPACE) {
					if (TURN) {
						cout << endl << "Player 1 wins in " << moveCount << " moves!";
					}
					else {
						cout << endl << "Player 2 wins in " << moveCount << " moves!";
					}

					return true;
				}
				else if (moveCount == 9) {
					cout << endl << "Tie! Nobody wins!";
					return true;
				}
			}
		}
	}
	return false;
}