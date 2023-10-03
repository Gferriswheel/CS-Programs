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
//This file holds the function definitions, and constructors of the classes.
#include <iostream>
#include <string>
#include "polyapp.h"

using namespace std;

//=====================Aplliance class member functions======================
//-----------------------Appliance Constructor-----------------------------

Appliance::Appliance(string ccustName, string cmanuFact) {
	custName = ccustName;
	manuFact = cmanuFact;
	estCost = 0;

}

//Setters and getters for customer name, manufacturer, and estimated cost
void Appliance::SetCustName(string ccustName) {
	custName = ccustName;
}
void Appliance::SetManuFact(string cmanuFact) {
	manuFact = cmanuFact;
}
void Appliance::SetEstCost(double cestCost) {
	estCost = cestCost;
}
string Appliance::GetCustName() {
	return custName;
}
string Appliance::GetManuFact() {
	return manuFact;
}
double Appliance::GetEstCost() {
	return estCost;
}

//-----------------------Appliance EstimateService-----------------------------

 void Appliance::EstimateService() {
	 estCost = 0;
}

 //-----------------------Appliance printObject-----------------------------
 //Prints customer name, manufacturer, and estimated cost
 void Appliance::PrintObject() {
	 cout << "Customer Name  :" << custName << endl;
	 cout << "Manufacture    :" << manuFact << endl;
	 cout << "Estimated Cost :" << estCost << endl;
}


//=========================TV class member functions=========================
//-----------------------TV Constructor-----------------------------
 TV::TV(string ccustName, string cmanuFact, int cmodelAge) : Appliance(ccustName, cmanuFact) {
	 modelAge = cmodelAge;
 }

 //Setter and getter for model age
 void TV::SetModelAge(int age) {
	 modelAge = age;
 }
 int TV::GetModelAge() {
	 return modelAge;
 }

 //-----------------------TV EstimateService-----------------------------
 //Sets estimated cost to $150 if model age is 6 years or greater, else its $50
 void TV::EstimateService() {
	 if (modelAge >= 6) {
		 estCost = 150;
	 }
	 else {
		 estCost = 50;
	 }
 }

 //-----------------------TV printObject-----------------------------
 //calls the base class printObject and prints model age
 void TV::PrintObject() {
	 cout << "-----TV-------" << endl;
	 Appliance::PrintObject();
	 cout << "Model Age      : " << modelAge << endl;

 }


//====================VCR class member functions=========================
//-----------------------VCR Constructor-----------------------------
 VCR::VCR(string ccustName, string cmanuFact, int cnumTapes) : Appliance(ccustName, cmanuFact) {
	 numTapes = cnumTapes;
 }

 //Setter and getter for number of tapes
 void VCR::SetNumTapes(int age) {
	 numTapes = age;
 }
 int VCR::GetNumTapes() {
	 return numTapes;
 }

//-----------------------VCR EstimateService-----------------------------
//Sets estimated cost to $100 if the number of tapes is greater than 1, else its $50
 void VCR::EstimateService() {
	 if (numTapes > 1) {
		 estCost = 100;
	 }
	 else {
		 estCost = 40;
	 }
 }


//-----------------------VCR printObject-----------------------------
//calls the base class printObject and prints number of tapes
 void VCR::PrintObject() {
	 cout << "-----VCR-------" << endl;
	 Appliance::PrintObject();
	 cout << "Number of Tape Drives: " << numTapes << endl;
 }











