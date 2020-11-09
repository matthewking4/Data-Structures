#pragma once
using namespace std;

// Superclass for all pages
class BasePage {
public:
	int prioriy; // priority int
	std::string title; // title value for UI and demonstration
	BasePage* previous; // Linked List previous page
	BasePage(int p) { prioriy = p; }; // constructor asigns priority
	~BasePage() { }; // destructor

	// Method to provide greater than oporator to compare priorities
	bool operator>(const BasePage& newPage) {
		return this->prioriy > newPage.prioriy;
	}
};