#include <iostream>
#include "NavigationStack.h"
#include "BasePage.h"
#include "PriorityPageQueue.h"
#include "StackDemo.h"
using namespace std;

// Logs all the possible Queue & Stack commands
void QueueCommands() {
	cout << "***********************" << endl;
	cout << "What operation do you want to perform?" << endl;
	cout << "***** Queue ******" << endl;
	cout << "1. Insert page into Queue" << endl;
	cout << "2. Remove first page from Queue" << endl;
	cout << "3. View first page in Queue" << endl;
	cout << "4. View if Queue is empty" << endl;
	cout << "5. View if Queue is full" << endl;
	cout << "6. Add Queue'd pages into the Navigation Stack" << endl;
	cout << "***** Navigation Stack ******" << endl;
	cout << "7. View Navigation Stack Commands" << endl;
	cout << "***** General ******" << endl;
	cout << "8. Show All Commands" << endl;
	cout << "9. Exit" << endl;
	cout << "***********************" << endl;
	cout << endl;
}

// Main Queue Demo
void QueueStackDemo(NavigationStack stack) {
	int queueSize, option;
	cout << "Please input the size of the queue: ";
	cin >> queueSize; // input for queue size
	PriorityPageQueue queue(queueSize); // initilise priority queue with queue size
	system("cls"); // clear console
	QueueCommands(); // log possible commands
	do {
		cout << "Please input a Queue command 1-9 (Press 8 for help): ";
		cin >> option; // input of he desired command
		switch (option) { // switch based of input
		case 1: // queue.Insert()
		{
			queue.Push(Navigate()); // inserts int into the queue based from the navigation commands
			break;
		}
		case 2: // queue.Remove()
		{
			BasePage* p = queue.Remove();
			cout << p->title << " removed" << endl; // Removes the first entry from the queue
			break;
		}
		case 3: // queue.Peek()
		{
			BasePage* p = queue.Peek();
			cout << p->title << " is at the front of queue" << endl; // Returns the it at the beginning of the queue
			break;
		}
		case 4: // queue.IsEmpty()
		{
			cout << std::boolalpha << queue.IsEmpty() << endl; // bool if the queue is empty
			break;
		}
		case 5: // queue.IsFull()
			cout << std::boolalpha << queue.IsFull() << endl; // bool if the queue is full
			break;
		case 6:
		{
			bool result = true; // result bool of true - this will allow the while loop to run
			do {
				BasePage* element = queue.Remove(); // removes the first entry from the queue
				result = stack.Push(element); // push removed item into stack and assign the result
			} while (!queue.IsEmpty() && result); // if the queue isnt empty and the result is true - continue
			break;
		}
		case 7:
			system("cls"); // clear console
			StackDemo(stack); // Start the stack demo with the previously created stack
			break;
		case 8:
			system("cls"); // clear console
			QueueCommands(); // Show all queue commands
			break;
		case 9:
			// Exit
			break;
		default:
			// Key press not found - default
			cout << "Press 8 for help " << endl;
			break;
		}
	} while (option != 9);
}
