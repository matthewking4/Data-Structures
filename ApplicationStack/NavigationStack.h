#pragma once
#include "BasePage.h"
using namespace std;

class NavigationStack {
private: 
	BasePage* top;
public:
	// Constructor assign default
	NavigationStack() {
		top = NULL;
	}

	// Destructor nullifies values
	~NavigationStack() {
		top = NULL;
	}

	bool Push(BasePage* newPage) {
		if (top) { // if top is not Null
			BasePage* oldPage = top; //oldPage is assigned to the top value
			top = newPage; // top is now assigned to the new page provided within the parameter
			newPage->previous = oldPage; // Linked List updated to contain the oldPage value
			cout << "\n**************" << endl;
			cout << newPage->title << " PUSHED successfully" << endl; // informative log
			cout << "**************\n" << endl;
			return true; // return true to inform about its success with pushing page
		}
		else { //if Null (default)
			top = newPage; // asign top to the newPage parameter
			cout << "\n**************" << endl;
			cout << newPage->title << " PUSHED successfully" << endl; // informative log
			cout << "**************\n" << endl;
			return true; // return true to inform about its success with pushing page
		}
	}

	// Method to Peek value on top of stack
	BasePage* Peek() {
		if (IsEmpty()) { // If the stack is empty
			cout << "No Items to PEEK from the stack" << endl; // log informational output
			return NULL; // return null so imported pages can error handle. Could also throw. 
		}
		return top; // if the array is not empty, the value on top of the stack is returned
	}

	// Method to Pop values on top of the stack
	BasePage* Pop() {
		if (IsEmpty()) {
			cout << "No Items to POP from the stack" << endl;
			return NULL;
		}
		else {
			BasePage* currentPage = top; // assign current page to the value on top of the stack
			top = top->previous;  // top will now equal the previous page
			return currentPage; // return current page as it is the popped value. Most navigation stacks will remove and disregard the popped value.
		}
	}

	// Method to that returns an int of the total number of pages in the stack
	int Count() {
		int count = 0; // assign initial count
		BasePage* currentPage = top; // assign current page to the value on top of the stack
		while (currentPage != NULL) { // if the current page is not null
			count++; // increment count
			currentPage = currentPage->previous; // the new current page is assigned via the linked list previous pointer
		}
		return count; // When the while loop breaks due to page being null, return count
	}

	// Method to check if Stack is empty and return bool
	bool IsEmpty() {
		if (top == NULL) {
			return true;
		}
		return false;
	}


	// Method to display all items within the stack
	void History() {
		cout << "\n**************" << endl;
		cout << "Avalible Pages on the Stack: " << endl;
		BasePage* currentPage = top; // assign current page to the value on top of the stack
		while (currentPage != NULL) { // if the current page is not null
			cout << currentPage->title << endl; // log the title
			currentPage = currentPage->previous; // the new current page is assigned via the linked list previous pointer
		}
		cout << "**************\n" << endl;
	}
};