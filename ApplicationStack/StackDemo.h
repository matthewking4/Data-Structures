#pragma once
#include <iostream>
#include "BasePage.h"
#include "InformationPage.h"
#include "VideoPage.h"
#include "ViewPage.h"
#include "HomePage.h"
#include "NavigationStack.h"

// Logs all the possible stack commands
void StackCommands() {
	cout << "***********************" << endl;
	cout << "What operation do you want to perform?" << endl;
	cout << "***********************" << endl;
	cout << "1. Go forward" << endl;
	cout << "2. Go Back" << endl;
	cout << "3. View if the stack is empty" << endl;
	cout << "4. View current page" << endl;
	cout << "5. View amount of pages in stack" << endl;
	cout << "6. History" << endl;
	cout << "7. Clear Screen" << endl;
	cout << "8. Show operation commands" << endl;
	cout << "9. Exit" << endl;
	cout << "***********************" << endl;
	cout << endl;
}

// Logs all the possible pages the user can navigate to
// Navigate will return a new page based from user selection 
BasePage* Navigate() {
	BasePage* new_page;
	int page;
	cout << "\nPlease Input a desired Page" << endl;
	cout << "1. Home Page" << endl;
	cout << "2. View Page" << endl;
	cout << "3. Information Page" << endl;
	cout << "4. Video Page" << endl;
	cout << endl;
	cout << "Please input a command 1-4: ";
	cin >> page; //input of the desired page
	switch (page) { // switch based from input
	default:
		new_page = new HomePage(1); // construct new page with priority
		break;
	case 1:
		new_page = new HomePage(1); // construct new page with priority
		break;
	case 2:
		new_page = new ViewPage(3); // construct new page with priority
		break;
	case 3:
		new_page = new InformationPage(2); // construct new page with priority
		break;
	case 4:
		new_page = new VideoPage(4); // construct new page with priority
		break;
	}
	return new_page;
}

// Main Stack Demo
void StackDemo(NavigationStack stack) {
	int option, key, data;
	StackCommands(); // display all possible commands from the stack
	do {
		cout << "Please input a Stack command 1-9 (Press 8 for help): ";
		cin >> option; // input of he desired command
		switch (option) { // switch based of input
		case 1: // Stack.push()
		{
			//int command = NavigationCommands(); // Display and obtain desired page int
			//page = Navigate(command); // Get page class from desired page int
			stack.Push(Navigate()); // Push page to stack
			break;
		}

		case 2: // Stack.pop()
		{
			BasePage* page = stack.Pop(); // Pop page from stack
			if (page) {
				cout << "Page POPPED from the stack - Current page is: " << page->title << endl; // logs the popped value
				delete page; // deletes page and releases obtained memory
			}
			break;
		}
		case 3: // Stack.isEmpty()
			cout << std::boolalpha  << stack.IsEmpty() << endl; // displays if return of Stack.isEmpty() 
			break;

		case 4: // Stack.peek()
		{
			BasePage* page = stack.Peek(); //peek the top of the stack
			if (page) {
				cout << "Page on top of the of the stack is: " << page->title << endl; // logs the peeked value
			}
			break;
		}
		case 5: // Stack.count()
			cout << "Number of pages in the Stack: " << stack.Count() << endl; // logs the count of the stack
			break;

		case 6: // Stack.History()
			stack.History(); // Displays all pages within the stack
			break;
		case 7:
			// Clears console
			system("cls");
			break;
		case 8:
			// Displays all commands
			StackCommands();
			break;
		case 9:
			// QUIT
			break;
		default:
			// Key press not found - default
			cout << "Press 8 for help " << endl;
		}

	} while (option != 9);
}