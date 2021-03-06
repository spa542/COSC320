#include <iostream> // cout, endl
#include <stdio.h> // printf
#include <math.h> // pow()
#include <time.h> // time functions
#include <chrono> // chrono

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
int* makeArray2(int); // Creates a dynamic pre-sorted array
int* makeArray3(int); // Creates a dynamic sorted descending array
void printArray(Heap&); // Prints an array in a line
void timeSort(void (*sort)(Heap&), Heap&); // Calculates the time it takes to sort an array
bool isSorted(Heap&); // Takes a Heap struct and determines if array is sorted correctly

namespace Counters { // To get rid of ambiguity on a global swap counter variable
	int count = 0;
}

int main() {
	
	srand(time(NULL));
	int sizesLen = 19;
	int sizes[] = {10000, 60000, 110000, 160000, 210000, 260000, 310000, 360000, 
		410000, 460000, 510000, 560000, 610000, 660000, 710000, 760000, 810000,
		860000, 910000};

	std::cout << "=======================================" << std::endl;
	std::cout << "Testing the print algorithm and a mini array for basic demonstration\n";
	Heap heapTest(makeArray(15), 15);

	printArray(heapTest);

	HeapSort(heapTest);

	printArray(heapTest);
	std::cout << "=======================================" << std::endl;

	std::cout << "=======================================" << std::endl;
	std::cout << "Large Test cases of Heap sort: " << std::endl;
	for (int i = 0; i < sizesLen; i++) {
		std::cout << "Sorting array of " << sizes[i] << " elements..." << std::endl;
		Heap newHeap(makeArray(sizes[i]), sizes[i]);
		timeSort(HeapSort, newHeap);
	}	
	std::cout << "=======================================" << std::endl;

	std::cout << "=======================================" << std::endl;
	std::cout << "Large Test cases already sorted Heap sort: " << std::endl;
	for (int i = 0; i < sizesLen; i++) {
		std::cout << "Sorting array of " << sizes[i] << " elements..." << std::endl;
		Heap newHeap(makeArray2(sizes[i]), sizes[i]);
		timeSort(HeapSort, newHeap);
	}
	std::cout << "=======================================" << std::endl;

	std::cout << "=======================================" << std::endl;
	std::cout << "Large Test cases sorted in descending Heap sort: " << std::endl;
	for (int i = 0; i < sizesLen; i++) {
		std::cout << "Sorting array of " << sizes[i] << " elements..." << std::endl;
		Heap newHeap(makeArray3(sizes[i]), sizes[i]);
		timeSort(HeapSort, newHeap);
	}
	std::cout << "=======================================" << std::endl;
	
	return 0;
}

/*
 * timeSort Function:
 * Calculates the time it takes for heap sort to sort a given amount of elements
 */
void timeSort(void (*sort)(Heap&), Heap& sample) {
	auto start = std::chrono::system_clock::now();

    sort(sample);

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "Finished at " << std::ctime(&end_time) << "Elapsed time: " << elapsed_seconds.count() << "s\n";
    std::cout << "Amount of swaps " << Counters::count << std::endl;
    if (isSorted(sample)) {
        std::cout << "Sorted in correct order!" << std::endl;
    } else {
        std::cout << "Not sorted correctly!" << std::endl;
    }
	Counters::count = 0;
}

/*
 * isSorted Function:
 * Takes a Heap struct and determines if the array contained is sorted correctly in ascending
 * order after a heap sort takes place
 */
bool isSorted(Heap& arr) {
	for (int i = 0; i < arr.length - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			return false;
		}
	}
	return true;
}

/*
 * printArray Function:
 * Prints the array for function testing
 */
void printArray(Heap& arr) {
	for (int i = 0; i < arr.length; i++) {
		for (int j = 0; j < pow(2, i) && j + pow(2, i) < arr.length; j++) {
			std::cout << arr[j + pow(2, i) - 1] << " ";
		}
		std::cout << std::endl;
	}
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
 * makeArray2 Function:
 * Takes a length and then makes a dynamic array that is the size of the length passed already sorted correctly
 */
int* makeArray2(int len) {
	int* rtn = new int[len];
	for (int i = 0; i < len; i++) {
		rtn[i] = i / 2;
	}
	return rtn;
}

/* 
 * makeArray3 Function:
 * Takes a length and then makes a dynamic array that is the size of the length passed that is sorted in descending
 */
int* makeArray3(int len) {
	int* rtn = new int[len];
	for (int i = 0, j = len / 2; i < len; i++, j--) {
		rtn[i] = j;
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
	for (int i = arr.length - 1; i >= 0; i--) {
		MaxHeapify(arr, i);
	}
}

/*
 * HeapSort Function:
 * Makes sure that the array is a valid heap, then sorts the array correctly
 */
void HeapSort(Heap& arr) {
	BuildMaxHeap(arr);
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
	Counters::count++;
}
