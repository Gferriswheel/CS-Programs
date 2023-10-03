// Program #4 – BG Insurance
// Programmer:  Grant Ferris
// Class:  CS 2020 1002, Spring 2023
// Due Date: April 2, 2023
// Purpose of program: Create a program that 
// will read input from a file and keep track of members of an insurance company. It has options from a
// a menu to add members, remove members of a certain id, print the full list members, 
// print a list of all members of a certain policy along with their average premium, print a list 
// of all members if a given year or higher, and calculate and output the member with the lowest premium.
// Class: memberList							
// This file maintains a list of objects. Holds the constructors, deconstructors, function definitions,
// etc of the memberList class   

#include "memberNode.h"
#include "memberList.h"
#include <iostream>
#include <iomanip>
using namespace std;


//main default constructor that sets head and tail to nullptr
memberList::memberList() {
	head = nullptr;
	tail = nullptr;
}

//destructor that deletes each node in the list
memberList::~memberList() {

	//deletes each node by deleting what head points to and then point head to the next node
	while (head) {
		memberNode* next = head->GetNext();
		delete head;
		head = next;
	}
}

//This is an overloaded assignment function. It is needed when the object had dynamic memory allocated										 
memberList::memberList(const memberList& rs) {
	memberNode* currNode = rs.head;                // Copy List

	while (currNode != nullptr) {
		PushBack(new memberNode(rs.head->GetID(), rs.head->GetName(), rs.head->GetPolicy(),
			rs.head->GetYear(), rs.head->GetPremium()));
		currNode = currNode->GetNext();					//Traversal Statement
	}													//Important to point to the next node
}


// This is an copy constructor function. It is needed when the object had dynamic memory allocated
memberList& memberList::operator=(memberList& rs) {
	memberNode* currNode = rs.head;                // Copy List
	if (head != rs.head)
	{
		if (head) {
			delete head;
			head = nullptr;
			tail = nullptr;
		}
		while (currNode != nullptr) {

			PushBack(new memberNode(rs.head->GetID(), rs.head->GetName(), rs.head->GetPolicy(),
				rs.head->GetYear(), rs.head->GetPremium()));

			currNode = currNode->GetNext();					//Traversal Statement
		}													//Important to point to the next node
	}
	return *this;
}


//Function that takes the node passed in and adds it to the end of the linked list. 
//Accounts for an empty list.
void memberList::PushBack(memberNode* currNode) {
	if (!head) {
		head = tail = currNode;
	}
	else {
		tail->SetNext(currNode);
		tail = currNode;
	}
}

//Function that adds a new member to the start of the list
void memberList::AddOneMember(memberNode* currNode) {
	currNode->SetNext(head);
	head = currNode;
	cout << currNode->GetID() << " member added." << endl;
}

//Function that removes a member from a list
void memberList::RemoveOneMember(int id) {
	memberNode* currNode;
	memberNode* prevNode = nullptr; //holds the previous node before the desired deleted node.
	currNode = head;
	int idFound = false;


	while (currNode != nullptr) {
		if (currNode->GetID() == id) {
			idFound = true;
			if (currNode == head) {
				//If currNode is head then sets prevNode to currNode
				prevNode = currNode;
			}
			memberNode* idNode = currNode; //holds the node to delete
			if (currNode != head) {
				//If removing node that isn't head it links the previous node before the deleted node to
				//the node after the deleted node
				prevNode->SetNext(currNode->GetNext());
			}
			else {
				//If removing the first node it sets the head to the next following node
				head = currNode->GetNext();
			}
			currNode = currNode->GetNext(); //idNode holds the desired node to delete and currNode then points
			//to the next node
			delete idNode; //deletes desired node
		}
		else {
			//if currNode's id != id then prevNode is set to currNode and the latter points to the next node
			prevNode = currNode;
			currNode = currNode->GetNext();
		}
	}
	//If the id of the member is not found
	if (!idFound) {
		cout << id << " is not a member." << endl;
	}
}

//Function that prints out a table of the full list of members
void memberList::PrintMemberList() {
	memberNode* currNode;
	currNode = head;
	int count = 0;

	while (currNode != nullptr) {
		cout << setw(79) << setfill('=') << "" << endl;
		cout << "Id   Name                     Policy         Premium        Years" << endl;
		cout << "--   ----                     ------         -------        -----" << endl;
		while (currNode != nullptr) {
			cout << left << setw(5) << setfill(' ') << currNode->GetID();
			cout << left << setw(25) << setfill(' ') << currNode->GetName();
			cout << left << setw(15) << setfill(' ') << currNode->GetPolicy();
			cout << left << setw(15) << setfill(' ') << currNode->GetPremium();
			cout << currNode->GetYear() << endl;
			currNode = currNode->GetNext();
			++count;
		}
		
	}
	//precaution if there is no members in list
	if (count == 0) {
		cout << "Sorry there are no members in the list." << endl;
	}
	cout << left << setw(79) << setfill('=') << "" << endl;
	
}

//Function that prints table of the full list of members of a given policy along with their average premium
void memberList::PrintPolicy(string policy) {
	memberNode* currNode;
	currNode = head;
	double sumPrem = 0;
	int counter = 0;
	cout << left << setw(79) << setfill('=') << "" << endl;
	cout << "              All " << policy << " members" << endl;
	cout << left << setw(79) << setfill('=') << "" << endl;
	cout << "Id   Name                     Policy         Premium        Years" << endl;
	cout << "--   ----                     ------         -------        -----" << endl;
	while (currNode != nullptr) {
		if (currNode->GetPolicy() == policy) {
			cout << left << setw(5) << setfill(' ') << currNode->GetID();
			cout << left << setw(25) << setfill(' ') << currNode->GetName();
			cout << left << setw(15) << setfill(' ') << currNode->GetPolicy();
			cout << left << setw(15) << setfill(' ') << currNode->GetPremium();
			cout << currNode->GetYear() << endl;
			sumPrem += currNode->GetPremium();
			++counter;
		}
		currNode = currNode->GetNext();
	}
	cout << left << setw(79) << setfill('-') << "" << endl;
	if (currNode != head && counter != 0) {
		cout << "The average " << policy << " premium is: $" << sumPrem / counter << endl;
	}
	else { //precaution if there is no members of that policy in the list
		cout << "Sorry no " << policy << " members." << endl;
	}
	
	cout << left << setw(79) << setfill('=') << "" << endl;
}

//Function that prints out a table of the full list of members of a given year or higher
void memberList::PrintYear(int year) {
	memberNode* currNode;
	currNode = head;
	int count = 0;

	cout << left << setw(79) << setfill('=') << "" << endl;
	cout << "              Members of at least: " << year << " year(s)" << endl;
	cout << left << setw(79) << setfill('=') << "" << endl;
	cout << "Id   Name                     Policy         Premium        Years" << endl;
	cout << "--   ----                     ------         -------        -----" << endl;
	while (currNode != nullptr) {
		if (currNode->GetYear() >= year) {
			cout << left << setw(5) << setfill(' ') << currNode->GetID();
			cout << left << setw(25) << setfill(' ') << currNode->GetName();
			cout << left << setw(15) << setfill(' ') << currNode->GetPolicy();
			cout << left << setw(15) << setfill(' ') << currNode->GetPremium();
			cout << currNode->GetYear() << endl;
			++count;
		}
		currNode = currNode->GetNext();
	}
	if (count == 0) { //precaution if there is no members of that year or higher
		cout << "Sorry, no member with " << year << " or more years" << endl;
	}
	cout << left << setw(79) << setfill('=') << "" << endl;
}

//Function that calculates and prints the member with the lowest premium
void memberList::PrintLowPremium() {
	memberNode* currNode;
	currNode = head;
	memberNode* lowYearNode = head;

	while (currNode != nullptr) {
		if (currNode->GetPremium() < lowYearNode->GetPremium()) {
			lowYearNode = currNode;
		}
		currNode = currNode->GetNext();

	}
	cout << left << setw(79) << setfill('-') << "" << endl;
	if (currNode != head) {
		cout << lowYearNode->GetName() << " has the lowest premium of " << lowYearNode->GetPremium() << " dollar(s)." << endl;
	}
	else { //precaution of there is no members in the list
		cout << "There are no members to get the lowest premium of." << endl;
	}
	cout << left << setw(79) << setfill('=') << "" << endl;
}