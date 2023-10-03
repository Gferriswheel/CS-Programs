#include "LinkedStack.h"
#include <iostream>
using namespace std;

int post


int main() {

	LinkedStack<string> stack;
	string choice;
	cout << "Enter the postfix expression, 1 token per line, enter -1 to exit" << endl;
	cin >> choice;

	while (choice != "-1") {
		
		stack.push(choice);
		cin >> choice;


	}




	return 0;
}