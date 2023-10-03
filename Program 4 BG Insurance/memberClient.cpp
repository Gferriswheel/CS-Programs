// Program #4 – BG Insurance
// Programmer:  Grant Ferris
// Class:  CS 2020 1002, Spring 2023
// Due Date: April 2, 2023
// Purpose of program: Create a program that 
// will read input from a file and keep track of members of an insurance company. It has options from a
// a menu to add members, remove members of a certain id, print the full list members, 
// print a list of all members of a certain policy along with their average premium, print a list 
// of all members if a given year or higher, and calculate and output the member with the lowest premium.
// Program: memberListClient.cpp
// Client program to use the memberNode and memberList 
// classes 

#include "memberNode.h"
#include "memberList.h"
#include <iostream>
#include<fstream>
#include<string>
using namespace std;

memberNode* CreatecurrNode();
ifstream infile;

int main() {
	infile.open("memberData.txt");		//open file for input

	if (!infile.is_open()) {			// error check for opening input file
		cout << "ERROR: could not open input file";
		return 1;
	}

	memberList MyListOfmembers;			//memberList Object
	int yrs, choice, Delid;			//input variables for processing the list
	string policy;
	memberNode* currNode;
	cout << "The list is empty." << endl;
	infile >> choice; // get a menu choice before entering the loop		

	while (choice != 7) {

		if (choice == 1) {				//Add a newly created node to the front of the list
			currNode = CreatecurrNode();
			MyListOfmembers.AddOneMember(currNode);
		}
		else if (choice == 2) {			//Finds and deletes a node based on the integer entered
			infile >> Delid;
			MyListOfmembers.RemoveOneMember(Delid);
		}
		else if (choice == 3) {			//Prints full list of members
			MyListOfmembers.PrintMemberList();
		}
		else if (choice == 4) {			//Prints list of certain policy members along with their average premium
			infile.ignore();
			getline(infile, policy);
			MyListOfmembers.PrintPolicy(policy);
		}
		else if (choice == 5) {			//print a list of all members if a given year or higher
			infile >> yrs;
			MyListOfmembers.PrintYear(yrs);
		}
		else if (choice == 6) {			//Calculate and output the member with the lowest premium.
			MyListOfmembers.PrintLowPremium();
		}
		infile >> choice;				// get a menu choice in the loop	
	}
	return 0;
}

//-----------------------------------------------------
// Function: CreatecurrNode
// Create a node with member data
// Returns a pointer to that current node
//-----------------------------------------------------
memberNode* CreatecurrNode()
{
	memberNode* currNode;		//local pointer for the dynamic node that will be created
	string name;
	int id;
	string policy;
	int premium;
	int year;


	//inputs from file
	infile >> id;
	infile.ignore();
	getline(infile, name);
	getline(infile, policy);
	infile >> year;
	infile >> premium;
	
	//create new node
	currNode = new memberNode(id, name, policy, year, premium);

	return currNode;
}