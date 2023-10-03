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
// This file maintains a node in a list. Holds the constructors, destructors, and function definitions
//of the memberNode class.

#include <iostream>
#include "memberNode.h"
using namespace std;


//Default constructor of no parameters
memberNode::memberNode() {
    id = 0;
    name = "UKNOWN";
    policy = "UNKNOWN";
    year = 0;
    premium = 0;
}

//Constructor with parameterss for all variables besides next. Used in CreatecurrNode() function in main
memberNode::memberNode(int id, string name, string policy, int year, int premium) {
    this->id = id;
    this->name = name;
    this->policy = policy;
    this->year = year;
    this->premium = premium;
}


//Destructor
memberNode::~memberNode() {
    cout << id << " member removed." << endl;
}

//Function that sets id
void memberNode::SetID(int id) {
    this->id = id;
}

//Function that gets id
int memberNode::GetID() {
    return id;
}

//Function that sets name
void memberNode::SetName(string name) {
    this->name = name;
}

//Function that gets name
string memberNode::GetName() {
    return name;
}

//Function that sets policy
void memberNode::SetPolicy(string policy) {
    this->policy = policy;
}

//Function that gets policy
string memberNode::GetPolicy() {
    return policy;
}

//Function that sets year
void memberNode::SetYear(int year) {
    this->year = year;
}

//Function that gets year
int memberNode::GetYear() {
    return year;
}

//Function that sets premium
void memberNode::SetPremium(int premium) {
    this->premium = premium;
}

//Function that gets premium
int memberNode::GetPremium() {
    return premium;
}

//Function that sets pointer to next node
void memberNode::SetNext(memberNode* next) {
    this->next = next;
}

//Function that gets pointer to next node
memberNode* memberNode::GetNext() {
    return next;
}