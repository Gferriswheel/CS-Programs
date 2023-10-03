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
// Defines the memberList class that maintains a list of nodes/objects
// This class maintains a list of objects and holds function declarations.

#ifndef MEMBERLISTH
#define MEMBERLISTH
using namespace std;
#include <iostream>
#include "memberNode.h"

class memberList {
public:
	memberList(); 
	memberList(const memberList& rs);
	~memberList();
	memberList& operator=(memberList& rhs);
	void PushBack(memberNode* currNode);
	void AddOneMember(memberNode* currNode);
	void RemoveOneMember(int id);
	void PrintMemberList();
	void PrintPolicy(string policy);
	void PrintYear(int year);
	void PrintLowPremium();
private:
	memberNode* head;
	memberNode* tail;
};
#endif