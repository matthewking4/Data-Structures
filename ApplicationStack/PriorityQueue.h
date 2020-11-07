#pragma once
class PriorityQueue {
	int size;
	int* data;
	int count;
public:

	PriorityQueue(int size) :size(size) {
		data = new int[size];
		count = 0;
	}

	~PriorityQueue() {}

	void Insert(int item) {
		if (count == 0) {
			data[count++] = item;
		}
		else {
			int i;
			for (i = (count - 1); i >= 0; i--) {
				if (item > data[i]) {
					data[i + 1] = data[i];
				}
				else {
					break;
				}
			}
			data[i + 1] = item;
			count++;
		}
	}

	// Removes an item from the queue
	int Remove() {
		return data[--count];
	}

	// Returns the int at the beginning of the Queue
	int Peek() {
		return data[count - 1];
	}

	// Returns Boolean if Queue is empty
	bool IsEmpty() {
		return count == 0;
	}

	// Returns Boolean if Queue is equal to the desired size of the queue
	bool IsFull() {
		return count == size;
	}
};
