#pragma once
#include "BasePage.h" // Not required as QueueDemo includes but kept for clarity
using namespace std;

class PriorityPageQueue {
	int arrSize;
	BasePage** pages;
	int current;
public:
	// Constructor takes size int as parameter and assigns the initial values for the arrays
	PriorityPageQueue(int s) {
		pages = new BasePage * [s];
		arrSize = s;
		current = 0;
	}

	// Destructor nullifies values
	~PriorityPageQueue() {
		pages = NULL;
		arrSize = NULL;
		current = NULL;
	}

	// Push a page to the array of pages
	void Push(BasePage* page) {
		// Queue is empty
		if (IsEmpty()) {
			pages[current++] = page; // Increment pages array and assign its value to the page parameter
		}
		// Queue is full
		else if (IsFull()) {
			cout << "Queue is full" << endl; // Log to for error handling so no further information can be stored within the full array. This could be updated to return or throw.
		}
		else {
			int i;
			for (i = (current - 1); i >= 0; i--) { // Start loop
				if (*page > * pages[i]) { // If the new page is larger than current pages priority
					pages[i + 1] = pages[i]; // If true, shift to the new current page 
				}
				else {
					break; // Done
				}
			}
			pages[i + 1] = page; // assign page
			current++; // increment
		}
	}

	// Returns the page address at the front of the Queue
	BasePage* Peek() {
		return pages[current - 1];
	}

	// Removes an item from the queue
	BasePage* Remove() {
		return pages[--current];
	}

	// Returns Boolean if Queue is empty
	bool IsEmpty() {
		return current == 0;
	}

	// Returns Boolean if Queue is equal to the desired size of the queue
	bool IsFull() {
		return current == arrSize;
	}
};