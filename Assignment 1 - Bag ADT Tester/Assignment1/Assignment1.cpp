#include "pch.h"
#include <iostream>
#include <string>
#include "ArrayBag.h"
#include "MyBag.h"
using namespace std;
void displayBag(MyBag<string>& bag)
{
	cout << "The bag contains " << bag.getCurrentSize()
		<< " items:" << endl;
	vector<string> bagItems = bag.toVector();

	int numberOfEntries = (int)bagItems.size();
	for (int i = 0; i < numberOfEntries; i++)
	{
		cout << bagItems[i] << " ";
	}  // end for
		cout << endl << endl;
}  // end displayBag

void bagTester(MyBag<string>& bag) {
	string choice = "";

	cout << "Please enter the strings you want to store in the bag, max of 6 strings";
	cout << " (enter \"stop\" to stop)" << endl;

	//inputs to add to bag until user says stop (max is still 6 so any inputs past that don't do anything)
	while (choice != "stop") {
		cin >> choice;
		if (choice == "stop") {
			break;
		}
		bag.add(choice);
	}

	//Display current bag size and items
	displayBag(bag);

	cout << "The current size of the bag is " << bag.getCurrentSize() << endl;
	cout << "Please enter a string to remove" << endl;
	cin >> choice;

	//remove string including duplicates
	bag.removeAll(choice);

	cout << "The current size of the bag is " << bag.getCurrentSize() << endl;

	//Display current bag size and items after removal
	displayBag(bag);

	//***************************************************************************
		//below are tests for all the methods we discussd in class
		/*std::cout << "isEmpty: returns " << bag.isEmpty()
			<< "; should be 1 (true)" << std::endl;
		displayBag(bag);

		std::string items[] = { "one", "two", "three", "four", "five", "one" };
		std::cout << "Add 6 items to the bag: " << std::endl;
		for (int i = 0; i < 6; i++)
		{
			bag.add(items[i]);
		}  // end for

		displayBag(bag);

		std::cout << "isEmpty: returns " << bag.isEmpty()
			<< "; should be 0 (false)" << std::endl;

		std::cout << "getCurrentSize: returns " << bag.getCurrentSize()
			<< "; should be 6" << std::endl;

		std::cout << "Try to add another entry: add(\"extra\") returns "
			<< bag.add("extra") << std::endl;

		std::cout << "contains(\"three\"): returns " << bag.contains("three")
			<< "; should be 1 (true)" << std::endl;
		std::cout << "contains(\"ten\"): returns " << bag.contains("ten")
			<< "; should be 0 (false)" << std::endl;
		std::cout << "getFrequencyOf(\"one\"): returns "
			<< bag.getFrequencyOf("one") << " should be 2" << std::endl;
		std::cout << "remove(\"one\"): returns " << bag.remove("one")
			<< "; should be 1 (true)" << std::endl;
		std::cout << "getFrequencyOf(\"one\"): returns "
			<< bag.getFrequencyOf("one") << " should be 1" << std::endl;
		std::cout << "remove(\"one\"): returns " << bag.remove("one")
			<< "; should be 1 (true)" << std::endl;
		std::cout << "remove(\"one\"): returns " << bag.remove("one")
			<< "; should be 0 (false)" << std::endl;
		std::cout << std::endl;

		displayBag(bag);

		std::cout << "After clearing the bag, ";
		bag.clear();

		std::cout << "isEmpty: returns " << bag.isEmpty()
			<< "; should be 1 (true)" << std::endl;*/
}  // end bagTester

int main()
{
	MyBag<string> bag;
	bagTester(bag);
	cout << "All done!" << endl;

	return 0;
}  // end main

/*
 Testing the Array-Based Bag:
 The initial bag is empty.
 isEmpty: returns 1; should be 1 (true)
 The bag contains 0 items:


 Add 6 items to the bag:
 The bag contains 6 items:
 one two three four five one

 isEmpty: returns 0; should be 0 (false)
 getCurrentSize: returns 6; should be 6
 Try to add another entry: add("extra") returns 0
 contains("three"): returns 1; should be 1 (true)
 contains("ten"): returns 0; should be 0 (false)
 getFrequencyOf("one"): returns 2 should be 2
 remove("one"): returns 1; should be 1 (true)
 getFrequencyOf("one"): returns 1 should be 1
 remove("one"): returns 1; should be 1 (true)
 remove("one"): returns 0; should be 0 (false)

 The bag contains 4 items:
 five two three four

 After clearing the bag, isEmpty: returns 1; should be 1 (true)
 All done!
 */