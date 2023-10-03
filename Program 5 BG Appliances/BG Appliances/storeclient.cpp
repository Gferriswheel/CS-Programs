// Program #5 – BG Appliances
// Programmer:  Grant Ferris
// Class:  CS 2020 1002, Spring 2023
// Due Date: April 23, 2023
// Purpose of program: To build and display a list
//that utilizes inheritance and polymorphism.
//TV and VCR, which are all derived from
//the same base class Appliance, Are stored in a vector used to maintain
//the list of appliances in inventory. The vector consists of base class
//pointers to each appliance. Appliances all show the customer name, manufacturer, and estimated cost. TVs also show their model age
// and VCRs show the number of tapes they have.
//Program: storeclient.cpp
// Client program to use the Appliance, TV, and VCR classes
#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include "polyapp.h"

using namespace std;

Appliance* GetAppliance(int code);				     // prototype: creates an appliance
void PrintList(vector<Appliance*> repairList);      // prototype: prints the list appliances
ifstream infile;									// global file pointer to read data from the input file

int main()
{
	vector<Appliance*> repairList;
	Appliance* AppPtr;
	int code;
	infile.open("repairlist.txt");

	if (!infile.is_open()) {			// error check for opening input file
		cout << "ERROR: could not open input file";
		return 1;
	}

	infile >> code; // get a menu code before entering the loop		

	while (code != 3)
	{
		AppPtr = GetAppliance(code);
		repairList.push_back(AppPtr); //this adds a pointer to the vector,
		//the object is dynamically declare
		//in the heap. The pointer points to it.
		infile >> code;
	}

	//add a base class object to the end of the list to test your base class functions
	repairList.push_back(new Appliance("END", "TEST"));
	//print the list
	PrintList(repairList);
	return 0;
}
//-----------------------------------------------------
// Function: getAppliance
// Inputs data for an appliance
// Create a new object based on the type of appliance
// and returns a pointer to that appliance
//-----------------------------------------------------
Appliance* GetAppliance(int code)
{
	//Declare the appropriate variables to popluate your object.
	Appliance* nuApp;
	string custName, manuFact;
	int modelAge, numTapes;

	//input those variables to popluate your object.
	infile.ignore();
	getline(infile, custName);
	getline(infile, manuFact);

	//add those variables as arguments to populate your object.
	if (code == 1)
	{
		infile >> modelAge;
		nuApp = new TV(custName, manuFact, modelAge);			//create a new TV with the custName, manuFact and modelAge
	}
	else
	{
		infile >> numTapes;
		nuApp = new VCR(custName, manuFact, numTapes);				//create a new VCR with the custName, manuFact and numTapes
	}
	return nuApp;
}
//-----------------------------------------------------
// Function: PrintList
// Prints the list of appliance
//-----------------------------------------------------
void PrintList(vector<Appliance*> repairList)
{
	for (int k = 0; k < repairList.size(); k++)
	{
		cout << "------------------------------------" << endl;
		repairList[k]->EstimateService();   //repairList.at(k)->EstimateService()
		repairList[k]->PrintObject();		//will also work with vectors
	}
}