#include <iostream>
#include <stdio.h>

struct Heap {
	int* arr; // the underlying array
	int length; // the size of the array
	int heap_size; // is the proportion of the array that is a valid heap

	Heap(int* a, int len) {
		arr = a;
		length = len;
		heap_size = 0;
	}
	
	~Heap() {
		delete [] arr;
	}

	int& operator[](int i) {
		return arr[i];
	}
};

void MaxHeapify(Heap&, int); // Heapify function that will create a valid heap on a trio of elements
void BuildMaxHeap(Heap&); // Loop to create a valid heap throughout the array
void HeapSort(Heap&); // Creates the final sorting of the heap
void swap(int&, int&); // Swaps two elements taken by reference
int* makeArray(int); // Creates a dynamic array of specified length
void printArray(Heap&); // Prints an array in a line

int main() {
	
	srand(time(NULL));
	
	int* test = makeArray(10);

	Heap heapTest(test, 10);

	printArray(heapTest);

	HeapSort(heapTest);

	printArray(heapTest);
	
	return 0;
}

/*
 * printArray Function:
 * Prints the array for function testing
 */
void printArray(Heap& arr) {
	std::cout << std::endl;
	for (int i = 0; i < arr.length; i++) {
		std::cout << arr[i] << "  ";
	}
	std::cout << std::endl;
}

/*
 * makeArray Function:
 * Takes a length and then makes a dynamic array that is the size of the length passed
 */
int* makeArray(int len) {
	int* rtn = new int[len];
	for (int i = 0; i < len; i++) {
		rtn[i] = 1 + rand() & 50;	
	}
	return rtn;
}

/*
 * MaxHeapify Function:
 * Heapify function that will create a valid heap on a trio of elements
 */
void MaxHeapify(Heap& arr, int i) {
	int Lchild = 2 * i + 1;
	int Rchild = 2 * i + 2;
	int largest = i;
	if (Lchild < arr.heap_size && arr[Lchild] > arr[largest]) {
		largest = Lchild;
	}
	if (Rchild < arr.heap_size && arr[Rchild] > arr[largest]) {
		largest = Rchild;
	}
	if (largest != i) {
		swap(arr[i], arr[largest]);
		MaxHeapify(arr, largest);
	}
}

/*
 * BuildMaxHeap Function:
 * Loops on the array until the whole array is a heap
 */
void BuildMaxHeap(Heap& arr) {
	arr.heap_size = arr.length;
	for (int i = arr.length / 2 - (3 / 2); i > 1; i--) {
		MaxHeapify(arr, i);
	}
}

/*
 * HeapSort Function:
 * Makes sure that the array is a valid heap, then sorts the array correctly
 */
void HeapSort(Heap& arr) {
	BuildMaxHeap(arr);
	printArray(arr);
	for (int i = arr.length - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		arr.heap_size -= 1;
		MaxHeapify(arr, 0);
	}
}
/*
 * swap Function:
 * Takes two elements by reference and swaps them in place
 */
void swap(int& l, int& r) {
	int temp = l;
	l = r;
	r = temp;
}
