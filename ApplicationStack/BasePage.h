#pragma once
using namespace std;

// Superclass for all pages
class BasePage {
public:
	int priority; // priority int
	std::string title; // title value for UI and demonstration
	BasePage* previous; // Linked List previous page
	BasePage(int p) { priority = p; }; // constructor assigns priority
	~BasePage() { }; // destructor

	// Method to provide greater than operator to compare priorities
	bool operator>(const BasePage& newPage) {
		return this->priority > newPage.priority;
	}
};