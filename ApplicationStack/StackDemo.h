#pragma once
#include<iostream>
#include "BasePage.h"
#include "InformationPage.h"
#include "VideoPage.h"
#include "ViewPage.h"
#include "HomePage.h"
#include "NavigationStack.h"

// Logs all the possible stack commands
void StackCommands() {
	cout << "\nWhat operation do you want to perform?" << endl;
	cout << "1. Push()" << endl;
	cout << "2. Pop()" << endl;
	cout << "3. isEmpty()" << endl;
	cout << "4. peek()" << endl;
	cout << "5. count()" << endl;
	cout << "6. display()" << endl;
	cout << "7. Clear Screen" << endl;
	cout << "8. Show operation commands" << endl;
	cout << "9. Exit" << endl;
	cout << endl;
}

// Logs all the possible pages the user can navigate to
// returns int
int NavigationCommands() {
	int page;
	cout << "\nPlease Input a desired Page" << endl;
	cout << "1. Home Page" << endl;
	cout << "2. View Page" << endl;
	cout << "3. Information Page" << endl;
	cout << "4. Video Page" << endl;
	cout << endl;
	cout << "Please input a command 1-4: ";
	cin >> page;
	return page;
}

// Navigate func will return a new page based of the int parameter 
BasePage* Navigate(int command) {
	BasePage* new_page;
	switch (command) {
	default:
		new_page = new HomePage();
		break;
	case 1:
		new_page = new HomePage();
		break;
	case 2:
		new_page = new ViewPage();
		break;
	case 3:
		new_page = new InformationPage();
		break;
	case 4:
		new_page = new VideoPage();
		break;
	}
	return new_page;
}

// Main Stack Demo
void StackDemo(Stack<BasePage> stack) {
	int option, key, data;
	BasePage* page;
	StackCommands(); // display all possible commands from the stack
	do {
		cout << "Please input a command 1-9: ";
		cin >> option;
		switch (option) {
		case 1: // Stack.push()
		{
			int command = NavigationCommands(); // Display and obtain desired page int
			page = Navigate(command); // Get page class from desired page int
			stack.Push(page); // Push page to stack
			break;
		}

		case 2: // Stack.pop()
			page = stack.Pop(); // Pop page from stack
			if (page) {
				cout << "Page POPPED from the stack - Transitioning to: " << page->title << endl; // logs the popped value
				delete page; // deletes page and releases obtained memory
			}
			break;

		case 3: // Stack.isEmpty()
			cout << stack.IsEmpty() << endl; // displays if return of Stack.isEmpty() 
			break;

		case 4: // Stack.peek()
			page = stack.Peek(); //peek the top of the stack
			if (page) {
				cout << "Page on top of the of the stack is: " << page->title << endl; // logs the peeked value
			}
			break;

		case 5: // Stack.count()
			cout << "Number of pages in the Stack: " << stack.Count() << endl; // logs the count of the stack
			break;

		case 6: // Stack.display()
			stack.Display(); // Displays all pages within the stack
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