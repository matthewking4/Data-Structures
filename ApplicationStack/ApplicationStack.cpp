#include <iostream>
#include "BasePage.h"
#include "NavigationStack.h"
#include "QueueDemo.h"
#include "StackDemo.h"
using namespace std;

int main() {
	int command; // Int of the inital command

	do {
		NavigationStack stack; // declare Stack
		system("cls");
		cout << "********************************************\n";
		cout << "Welcome to the Navigation System!\n";
		cout << "Plase Enter the number of the operation you wish to perform\n";
		cout << "1. Navigation Queue and Navigation Stack Functionality" << endl;
		cout << "2. Exit" << endl;
		cout << "********************************************\n\n";
		cin >> command; // input of command

		switch (command) {
		case 1:
			QueueStackDemo(stack);// Invoke Queue with Stack 
			break;
		case 2:
			break;
		}
	} while (command != 2);
	return 0;
}
