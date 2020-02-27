#ifndef _HEAPQ_H_
#define _HEAPQ_H_
#include <iostream>
#include <stdio.h>

template<class T>
struct HeapObj {
	T data;
	int priority;
	
	HeapObj(T d, int p) {
		data = d;
		priority = p;
	}
};

class HeapQ {
private:
	
	HeapObj<T>* arr;
	int arrLength;
	int heap_size;	

	void increase-key(int, int); // Increases the priority of the HeapObj
	void increaseSize(); // Increases the size of the array to avoid overflow
	void swap(HeapObj<T>&, HeapObj<T>&); // Swaps two given values in the priority queue
public:
	
	HeapQ(); // Defualt Constructor
	HeapQ(const HeapQ&); // Copy Constructor
	~HeapQ(); // Destructor
	HeapQ& operator=(const HeapQ&); // Overloaded Assignment
		
	HeapObj<T> dequeue(); // Dequeue the first object in the queue and return it
	void peek(); // Display the contents of the object in the front of the queue
	void enqueue(T, int); // Enqueue an object into the queue with a specified priority
	void print(); // Prints out the contents of the queue
	
	void MaxHeapify(int); // Fixes violations in subtree rooted at A[i]	
};

#endif
