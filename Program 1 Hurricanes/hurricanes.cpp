// Program #1 ÅEHurricane Program
// Programmer:  Grant Ferris
// Class:  CS 2020 1002, Spring 2023
// Due Date: Feb 5, 2023
// Purpose of program: Create a program that 
// will read data from a file called hurricanes.txt.  
// The data will consist of a cityís name, wind velocity 
//and amount of rain for the hurricanes that occurred in the United States.
// The program will sort the peviously mentioned variables and calculate the cities with violent winds, cities with major floods, 
// the windiest city and its wind speed, average wind speed, and the average rainfall.
//It will output the all previously mentioned variables and calculations in a easily readable format.

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
//global constants
const int MAXCITIES = 50;
const int NAMESPACE = 15;
const int WINDSPACE = 12;
const int RAINSPACE = 9;

//Prototypes
void ReadData(fstream& inFS, vector<string>& names, vector<int>& wind, vector<double>& rain, int& hurricanes);
void SelSort(vector<string>& names, vector<int>& wind, vector<double>& rain, int& hurricanes);
void PrintVectors(vector<string> names, vector<int> wind, vector<double> rain, int hurricanes);
void ViolentWinds(vector<string> names, vector<int> wind, int hurricanes);
void MajorFlood(vector<string> names, vector<double> rain, int hurricanes);
int WindiestCity(vector<string> names, vector<int> wind, int hurricanes);
int AverWind(vector<int> wind, int hurricanes);
double AverRain(vector<double> rain, int hurricanes);

int main() {
	fstream inFS;
	int numHurricanes = 0;
	vector<string> cityNames;
	vector<int> cityWind;
	vector<double> cityRain;
	
	//Function calls
	ReadData(inFS, cityNames, cityWind, cityRain, numHurricanes);
	SelSort(cityNames, cityWind, cityRain, numHurricanes);
	PrintVectors(cityNames, cityWind, cityRain, numHurricanes);
	ViolentWinds(cityNames, cityWind, numHurricanes);
	MajorFlood(cityNames, cityRain, numHurricanes);
	WindiestCity(cityNames, cityWind, numHurricanes);

	//Other outputs
	cout << "\nWindiest City: " << cityNames.at(WindiestCity(cityNames, cityWind, numHurricanes)) << " ";
	cout << cityWind.at(WindiestCity(cityNames, cityWind, numHurricanes)) << " mph" << endl;
	cout << "Average Wind: " << fixed << setprecision(1) << AverWind(cityWind, numHurricanes) << " mph" << endl;
	cout << "Average Rainfall: " << fixed << setprecision(3) << AverRain(cityRain, numHurricanes) << " in." << endl;
	return 0;
}

//************************************************************************************
//Function: ReadData
//Function to read and fill vectors. The file is opened and closed after filling vectors
//************************************************************************************
void ReadData(fstream& inFS, vector<string>& names, vector<int>& wind, vector<double>& rain, int& hurricanes) {
	string nameInput;
	int windInput;
	double rainInput;
	string tempstr;
	inFS.open("hurricanes.txt");

	//error check for opening input file
	if (!inFS.is_open()) {
		cout << "ERROR: could not open input file";
		exit(1);
	}

	//filling in vectors
	while (!inFS.eof() && hurricanes < MAXCITIES)
	{
		getline(inFS, nameInput);
		names.push_back(nameInput);
		inFS >> windInput;
		wind.push_back(windInput);
		inFS >> rainInput;
		rain.push_back(rainInput);
		inFS.ignore();
		//getline(inFS, tempstr); //either one flushes out the endline character 
		hurricanes++;
	}
	inFS.close();
}

//************************************************************************************
//Function: SelSort
//Function to sort all three vectors at the same time through selection sorting
//************************************************************************************
void SelSort(vector<string>& names, vector<int>& wind, vector<double>& rain, int& hurricanes) {
	int i;
	int j;
	int indexSmallest;
	string cityTemp;      // Temporary variables for swap
	int windTemp;
	double rainTemp;
	//sorting each vector at the same time
	for (i = 0; i < hurricanes - 1; ++i) {

		// Find index of smallest remaining element in each vector
		indexSmallest = i;

		for (j = i + 1; j < hurricanes; ++j) {

			if (names.at(j) < names.at(indexSmallest)) {
				indexSmallest = j;
			}
		}

		// Swapping
		cityTemp = names.at(i);
		windTemp = wind.at(i);
		rainTemp = rain.at(i);
		names.at(i) = names.at(indexSmallest);
		names.at(indexSmallest) = cityTemp;
		wind.at(i) = wind.at(indexSmallest);
		wind.at(indexSmallest) = windTemp;
		rain.at(i) = rain.at(indexSmallest);
		rain.at(indexSmallest) = rainTemp;
	}
}

//************************************************************************************
//Function: PrintVectors
//Function to print information from vectors in a tabular format
//************************************************************************************
void PrintVectors(vector<string> names, vector<int> wind, vector<double> rain, int hurricanes) {
	int i;

	//header
	cout << "Hurricanes in the United States\n\n";
	cout << "City Name      Wind (mph)  Rain (in)\n";
	cout << setw(37) << setfill('-') << "";
	cout << endl;

	//table 
	for (i = 0; i < hurricanes; ++i) {
		cout << left << setw(NAMESPACE) << setfill(' ') << names.at(i);
		cout << left << setw(WINDSPACE) << setfill(' ') << wind.at(i);
		cout << left << setw(RAINSPACE) << setfill(' ') << rain.at(i);
		cout << endl;
	}
}

//************************************************************************************
//Function: ViolentWinds
//Function to print out cites that have violent winds (>= 120) and their wind speed
//************************************************************************************
void ViolentWinds(vector<string> names, vector<int> wind, int hurricanes) {
	int i;

	//header
	cout << "\nViolent Winds" << endl;
	cout << setw(19) << setfill('-') << "";
	cout << endl;

	//list
	for (i = 0; i < hurricanes; ++i) {
		if (wind.at(i) >= 120) {
			cout << left << setw(NAMESPACE) << setfill(' ') << names.at(i);
			cout << left << setw(WINDSPACE) << setfill(' ') << wind.at(i);
			cout << endl;

		}
	}
}

//************************************************************************************
//Function: MajorFlood
//Function to print out cites that have major floods (>=3.5) and their rainfall
//************************************************************************************
void MajorFlood(vector<string> names, vector<double> rain, int hurricanes) {
	int i;

	//header
	cout << "\nMajor Floods" << endl;
	cout << setw(19) << setfill('-') << "";
	cout << endl;

	//list
	for (i = 0; i < hurricanes; ++i) {
		if (rain.at(i) >= 3.5) {
			cout << left << setw(NAMESPACE) << setfill(' ') << names.at(i);
			cout << left << setw(RAINSPACE) << setfill(' ') << rain.at(i);
			cout << endl;
		}
	}
}

//************************************************************************************
//Function: WindiestCity
//Function to calculate the windiest city and return the vector index of it 
//************************************************************************************
int WindiestCity(vector<string> names, vector<int> wind, int hurricanes) {
	int windiestCityPos = 0;
	int i;

	for (i = 0; i < hurricanes; ++i) {
		if (wind.at(i) > wind.at(windiestCityPos)) {
			windiestCityPos = i;
		}
	}
	
	return windiestCityPos;
}

//************************************************************************************
//Function: AverWind
//Function to return the average wind of all cities
//************************************************************************************
int AverWind(vector<int> wind, int hurricanes) {
	int i;
	int sumWind = 0;

	for (i = 0; i < hurricanes; ++i) {
		sumWind += wind.at(i);
	}

	return sumWind / hurricanes;
}

//************************************************************************************
//Function: AverRain
//Function to return the average rainfall of all cities
//************************************************************************************
double AverRain(vector<double> rain, int hurricanes) {
	int i;
	double sumRain = 0;

	for (i = 0; i < hurricanes; ++i) {
		sumRain += rain.at(i);
	}

	return sumRain / hurricanes;
}