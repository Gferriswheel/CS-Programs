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
//Classes: Appliance (base class), TV (derived class), and VCR (derived class)
//This file holds the classes and their data members and function definitions.
#ifndef POLYAPPH
#define POLYAPPH

#include <iostream>
#include <string>

using namespace std;
//=========================Appliance class definition=========================
//-----------------------------------------------------------------------

class Appliance {
public:
	Appliance(string ccustName, string cmanuFact);
	void SetCustName(string ccustName);
	void SetManuFact(string cmanuFact);
	void SetEstCost(double cestCost);
	string GetCustName();
	string GetManuFact();
	double GetEstCost();
	virtual void EstimateService();
	virtual void PrintObject();

protected:
	string custName;
	string manuFact;
	double estCost;
};

//-----------------------------------------------------------------------
//=========================TV class definition=========================
//-----------------------------------------------------------------------

class TV : public Appliance {
public:
	TV(string ccustName, string cmanuFact, int cmodelAge);
	void SetModelAge(int age);
	int  GetModelAge();
	virtual void EstimateService();
	virtual void PrintObject();

private:
	int modelAge;
};

//-----------------------------------------------------------------------
//=========================VCR class definition=========================
//-----------------------------------------------------------------------

class VCR : public Appliance {
public:
	VCR(string ccustName, string cmanuFact, int cnumTapes);
	void SetNumTapes(int cnumTapes);
	int  GetNumTapes();
	virtual void EstimateService();
	virtual void PrintObject();

private:
	int numTapes;
};
#endif