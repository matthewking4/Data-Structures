#include <iostream>
#include "NavigationStack.h"
#include "BasePage.h"
#include "PriorityQueue.h"
#include "StackDemo.h"
using namespace std;

// Logs all the possible Queue & Stack commands
void QueueCommands() {
	cout << "***********************" << endl;
	cout << "What operation do you want to perform?" << endl;
	cout << "***** Queue ******" << endl;
	cout << "1. Insert()" << endl;
	cout << "2. Remove()" << endl;
	cout << "3. Peak()" << endl;
	cout << "4. IsEmpty()" << endl;
	cout << "5. IsFull()" << endl;
	cout << "6. Run Queue against the Stack" << endl;
	cout << "***** Stack ******" << endl;
	cout << "7. View Stack Functions" << endl;
	cout << "***** General ******" << endl;
	cout << "8. Show operation commands()" << endl;
	cout << "9. Exit" << endl;
	cout << "***********************" << endl;
	cout << endl;
}

// Main Queue Demo
void QueueStackDemo(Stack<BasePage> stack) {
	int queueSize, option;
	cout << "Please input the size of the queue: ";
	cin >> queueSize;
	PriorityQueue queue(queueSize);
	system("cls");
	QueueCommands();
	do {
		cout << "Please input a command 1-9: ";
		cin >> option;
		switch (option) {
		case 1: // queue.Insert()
			queue.Insert(NavigationCommands()); // inserts int into the queue based from the navigation commands
			break;
		case 2: // queue.Remove()
			cout << queue.Remove() << endl; // Removes the first entry from the queue
			break;
		case 3: // queue.Peak()
			cout << queue.Peek() << endl; // Returns the it at the beginning of the queue
			break;
		case 4: // queue.IsEmpty()
			cout << queue.IsEmpty() << endl; // bool if the queue is empty
			break;
		case 5: // queue.IsFull()
			cout << queue.IsFull() << endl; // bool if the queue is full
			break;
		case 6:
		{
			bool result = true; // result bool of true - this will allow the while loop to run
			do {
				int element = queue.Remove(); // removes the first entry from the queue
				result = stack.Push(Navigate(element)); // push removed item into stack and asign the result
			} while (!queue.IsEmpty() && result); // if the queue isn empty and the result is true - continue
			break;
		}
		case 7:
			StackDemo(stack); // Start the stack demo with the previously created stack
			break;
		case 8:
			QueueCommands(); // Show all queue commands
			break;
		case 9:
			// Exit
			break;
		default:
			// Key press not found - default
			cout << "Press 7 for help " << endl;
			break;
		}
	} while (option != 9);
}
