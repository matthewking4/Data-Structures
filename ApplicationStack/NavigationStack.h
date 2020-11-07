#pragma once
using namespace std;

template <class T>
class Stack {
public:
	T* top;

	Stack() {
		top = NULL;
	}

	bool IsEmpty() {
		if (top == NULL) {
			return true;
		}
		return false;
	}

	bool CheckIfPageExist(T* n) {
		T* currentPage = top;
		bool exist = false;
		while (currentPage != NULL) {
			if (currentPage->title == n->title) {
				exist = true;
				break;
			}
			currentPage = currentPage->previous;
		}
		return exist;
	}

	bool Push(T* newPage) {
		if (top == NULL) {
			top = newPage;
			cout << "\n=============" << endl;
			cout << newPage->title << " PUSHED successfully" << endl;
			cout << "=============\n" << endl;
			return true;
		}
		else if (CheckIfPageExist(newPage)) {
			cout << "\n=============" << endl;
			cout << newPage->title << " already exist within the stack. Please use POP to access the desired page" << endl;
			cout << "=============\n" << endl;
			return false;
		}
		else {
			T* oldPage = top;
			top = newPage;
			newPage->previous = oldPage;
			cout << "\n=============" << endl;
			cout << newPage->title << " PUSHED successfully" << endl;
			cout << "=============\n" << endl;
			return true;
		}
	}

	T* Pop() {
		T* currentPage = NULL;
		if (IsEmpty()) {
			cout << "No Items to POP from the stack" << endl;
			return NULL;
		}
		else {
			currentPage = top;
			top = top->previous;
			return currentPage;
		}
	}

	T* Peek() {
		if (IsEmpty()) {
			cout << "No Items to PEEK from the stack" << endl;
			return NULL;
		}
		return top;
	}

	int Count() {
		int count = 0;
		T* currentPage = top;
		while (currentPage != NULL) {
			count++;
			currentPage = currentPage->previous;
		}
		return count;
	}

	void Display() {
		cout << "\n=============" << endl;
		cout << "Avalible Pages on the Stack: " << endl;
		T* currentPage = top;
		while (currentPage != NULL) {
			cout << currentPage->title << endl;
			currentPage = currentPage->previous;
		}
		cout << "=============\n" << endl;
	}

};