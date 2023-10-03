// Program #4 – BG Insurance
// Programmer:  Grant Ferris
// Class:  CS 2020 1002, Spring 2023
// Due Date: April 2, 2023
// Purpose of program: Create a program that 
// will read input from a file and keep track of members of an insurance company. It has options from a
// a menu to add members, remove members of a certain id, print the full list members, 
// print a list of all members of a certain policy along with their average premium, print a list 
// of all members if a given year or higher, and calculate and output the member with the lowest premium.
// Class: memberNode					
// This file defines the memberNode class that holds data members of a node.
// Holds function declarations.

#ifndef MEMBERNODEH
#define MEMBERNODEH
using namespace std;
#include <iostream>

class memberNode {
public:
    memberNode();
    memberNode(int id, string name, string policy, int year, int premium);
    ~memberNode();
    void SetID(int id);
    int GetID();
    void SetName(string name);
    string GetName();
    void SetPolicy(string policy);
    string GetPolicy();
    void SetYear(int year);
    int GetYear();
    void SetPremium(int premium);
    int GetPremium();
    void SetNext(memberNode* next);
    memberNode* GetNext();
    
private:
    int id;
    string name;
    string policy;
    int year;
    int premium;
    memberNode* next;
};

#endif
