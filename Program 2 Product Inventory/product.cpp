// Program #2 – Product Inventory
// Programmer:  Grant Ferris
// Class:  CS 2020 1002, Spring 2023
// Due Date: Feb 19, 2023
// Purpose of program: Create a program that 
// will manage an product inventory with options for the user to add product's name, quantity, and price.
// It will also display and calculate the average price of all products, highest priced item, out of stock items, 
// and display a table of all product info. This is done through a main menu with input validation.
// It will output the all previously mentioned variables and calculations in a easily readable format.

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

//Global Variables
unsigned int i;


//Main struct
struct Product {
	string name;    // Name
	int qty;        // quantity is the number of items in stock
	double price;  // price to purchase one item
};

//Prototypes
int Menu();
void AddProd(vector<Product>& bginventory);
void ShowAvgPrice(vector<Product> bginventory);
void ShowHiPrice(vector<Product> bginventory);
void ShowOutOfStock(vector<Product> bginventory);
void ShowInventory(vector<Product> bginventory);

int main() {
	vector<Product> bginventory;
	int inputChoice = -1;
	char input = 'Y';


	//switch for inputs (instead of ifelse statements)
	while (inputChoice != 6) {
		inputChoice = Menu();

		switch (inputChoice) {

		case 1:
			AddProd(bginventory);
			break;
		case 2:
			ShowAvgPrice(bginventory);
			break;
		case 3:
			ShowHiPrice(bginventory);
			break;
		case 4:
			ShowOutOfStock(bginventory);
			break;
		case 5:
			ShowInventory(bginventory);
			break;
		case 6:
			//exit program from main meu
			exit(0);
			break;
		}

		//Confirmation to continue or exit program from current choice
		if (inputChoice != 1) {
			cout << "\nContinue? (Any key for yes and N for no)" << endl;
			cin >> input;
			input = toupper(input);

			if (input == 'N') {
				exit(0);
			}
		}
		//clearing screen
		system("cls");
		cin.clear();
		cin.ignore(256, '\n');
	}
	return 0;
}

//************************************************************************************
//Function: Menu
//Function to display meny options along with input validation and return input
//************************************************************************************
int Menu() {
	int choice = -1;

	// Display a menu.
	// Get the user's choice.
	while (!(choice >= 1 && choice <= 6)) {
		cout << "1. Add new product\n";
		cout << "2. Average Price\n";
		cout << "3. Highest Price\n";
		cout << "4. Display out of stock\n";
		cout << "5. Display all products in inventory\n";
		cout << "6. Exit the program\n\n";
		cout << "Enter your choice: ";
		cin >> choice;

		//Validation for invalid inputs
		if (!(choice >= 1 && choice <= 6)) {
			cout << "ERROR: Invalid choice" << endl;
			system("cls");
			cin.clear();
			cin.ignore(256, '\n');
		}
		system("cls");
	}
	return choice;
}

void AddProd(vector<Product>& bginventory) {
	Product product;

	cout << "Enter name: ";
	cin >> product.name;
	cout << "Enter quantity: ";
	cin >> product.qty;
	cout << "Enter price: ";
	cin >> product.price;

	bginventory.push_back(product);
}

//************************************************************************************
//Function: ShowAvgPrice
//Function to calculate and show average price of all products
//************************************************************************************
void ShowAvgPrice(vector<Product> bginventory) {
	double sum = 0;
	int qty = 0;
	Product product;

	//Gets sum of price and quantity for calculation
	for (i = 0; i < bginventory.size(); ++i) {
		sum += bginventory.at(i).price * bginventory.at(i).qty;
		qty += bginventory.at(i).qty;
	}
	cout << fixed << setprecision(2) << "Average Price: $" << sum / qty << endl;
}

//************************************************************************************
//Function: ShowHiPrice
//Function to calculate and show the highest priced product along with its price
//************************************************************************************
void ShowHiPrice(vector<Product> bginventory) {
	int highestIndex = 0;

	//Finds highest price index
	for (i = 0; i < bginventory.size(); ++i) {
		if (bginventory.at(i).price > bginventory.at(highestIndex).price) {
			highestIndex = i;
		}
	}

	cout << "Highest Price is " << bginventory.at(highestIndex).name << " at $" << bginventory.at(highestIndex).price << endl;
}

//************************************************************************************
//Function: ShowOutOfStock
//Function to show out of stock items in a list
//************************************************************************************
void ShowOutOfStock(vector<Product> bginventory) {
	cout << "Out of Stock Items:" << endl;
	cout << "##      Name       Quantity     Price" << endl;
	cout << setw(44) << setfill('-') << "" << endl;

	for (i = 0; i < bginventory.size(); ++i) {
		if (bginventory.at(i).qty <= 0) {
			cout << left << setw(7) << setfill(' ') << i + 1;
			cout << left << setw(11) << setfill(' ') << bginventory.at(i).name;
			cout << left << setw(13) << setfill(' ') << bginventory.at(i).qty;
			cout << "$" << bginventory.at(i).price << endl;
		}
	}
}

//************************************************************************************
//Function: ShowInventory
//Function to show current inventory with all product information in a tabular form
//************************************************************************************
void ShowInventory(vector<Product> bginventory) {
	int counter = 1;
	cout << "Current Inventory:\n" << endl;
	cout << "##     Name       Quantity     Price" << endl;
	cout << setw(44) << setfill('-') << "" << endl;

	for (i = 0; i < bginventory.size(); ++i) {
		cout << left << setw(7) << setfill(' ') << counter;
		cout << left << setw(11) << setfill(' ') << bginventory.at(i).name;
		cout << left << setw(13) << setfill(' ') << bginventory.at(i).qty;
		cout << "$" << bginventory.at(i).price << endl;
		++counter;
	}
}