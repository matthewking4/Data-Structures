#include<iostream>
#include "BasePage.h"
#include "NavigationStack.h"
#include "QueueDemo.h"
#include "StackDemo.h"
using namespace std;

int main() {
	Stack<BasePage> stack;
	int command; // Int of the inital command
	cout << "********************************************\n";
	cout << "Welcome to the Application Navigation System!\n";
	cout << "Plase Enter the number of the operation you wish to perform\n";
	cout << "1. Stack Functionality" << endl;
	cout << "2. Queue and Stack Functionality" << endl;
	cout << "Press Exit to quit the application at any time\n" << endl;
	cout << "********************************************\n\n";
	cin >> command; // input of command

	switch (command) {
		case 1:
			StackDemo(stack); //Invoke Stack Functionaliy 
			break;
		case 2:
			QueueStackDemo(stack);// Invoke Queue with Stack Functionaliy 
			break;
	}

	return 0;
}
