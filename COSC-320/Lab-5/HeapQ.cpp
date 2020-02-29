#include "HeapQ.h"

/*
 * increase-key Function:
 * Increases the priority of a specific HeapObj
 */
template<class T>
void HeapQ<T>::increaseKey(int subscript, int newPriority) {
	if (arr[subscript].priority > newPriority) {
		throw "Priority error?";
	}
	arr[subscript].priority = newPriority;
	
	while (subscript != 0 && arr[subscript].priority > arr[subscript / 2].priority) {
		swap(arr[subscript], arr[subscript / 2]);
		subscript /= 2;
	}
}

/*
 * increaseSize Function:
 * Pads the array size to avoid array overflow/seg faults
 */
template<class T>
void HeapQ<T>::increaseSize() {
	HeapObj<T>* newArr = new HeapObj<T>[arrLength * 2];
	for (int i = 0; i < arrLength; i++) {
		newArr[i] = arr[i];
	}
	delete [] arr;
	arr = newArr;
	arrLength *= 2;
}

/*
 * Default Constuctor:
 * Initializes the priority queue
 */
template<class T>
HeapQ<T>::HeapQ() {
	arr = new T[4];
	arrLength = 4;
	heap_size = -1;
}

/*
 * Copy Constructor:
 * Copies a HeapQ over to another instance
 */
template<class T>
HeapQ<T>::HeapQ(const HeapQ& rhs) {

}

/*
 * Destructor:
 * Deletes dynamically allocated data
 */
template<class T>
HeapQ<T>::~HeapQ() {
	delete [] arr;
}

/*
 * Overloade Assignment Operator:
 * Allows for assignment of a priority Queue into another priority Queue instance
 */
template<class T>
HeapQ<T>& HeapQ<T>::operator=(const HeapQ& rhs) {

}

/*
 * dequeue Function:
 * Dequeues the front object in the queue and then returns it
 */
template<class T>
HeapObj<T> HeapQ<T>::dequeue() {
	if (heap_size == -1) {
		throw "No items in the queue";
	}
	HeapObj<T> temp = arr[0];
	arr[0] = arr[heap_size];
	heap_size--;
	MaxHeapify(0);
	return temp;
}

/*
 * MaxHeapify Function:
 * Fixes violations in subtree rooted at A[i]
 */
template<class T>
void HeapQ<T>::MaxHeapify(int i) {
	int Lchild = 2 * i + 1; 
	int Rchild = 2 * i + 2;
	int max = i;
	if (Lchild <= heap_size && arr[Lchild].priority > arr[i].priority) {
		max = Lchild;
	}
	if (Rchild <= heap_size && arr[Rchild].priority > arr[max].priority) {
		max = Rchild;
	}
	if (max != i) {
		swap(arr[i], arr[max]);
		MaxHeapify(max);
	}
}

/*
 * swap Function:
 * Swaps two given values in the priority queue
 */
template<class T>
void HeapQ<T>::swap(HeapObj<T>& first, HeapObj<T>& second) {
	HeapObj<T> temp(first.data, first.priority);
	first = second;
	second = temp;
}

/*
 * peek Function: 
 * Displays the contents of the object in the front of the queue
 */
template<class T>
void HeapQ<T>::peek() {

}

/*
 * enqueue Function:
 * Enqueue's an object into the queue with a specified priority
 */
template<class T>
void HeapQ<T>::enqueue(T obj, int priority) {
	if (priority < 0) {
		throw "Priority out of bounds";
	}
	HeapObj<T> newItem(obj, 0);
	if (heap_size + 1 == arrLength) {
		increaseSize();
	}
	arr[++heap_size] = newItem;
	increaseKey(heap_size, priority);
}

/*
 * print Function:
 * Prints out the contents of the queue
 */
template<class T>
void HeapQ<T>::print() {
	
}
