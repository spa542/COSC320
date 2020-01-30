#include <iostream>
#include <stdio.h>
#include <time.h>
#include <chrono>

int count = 0;

void bubbleSort(int*, int, bool); // sort the function using bubble sort algorithm
void selectionSort(int*, int, bool); // sort the funciton using selection sort algorithm
void insertionSort(int*, int, bool); // sort the function using insertion sort algorithm
int* makeArray(int);	// creates a dynamic array of integers
int* makeArray2(int); 	// creates a dynamic array of integers in backwards order
void swap(int&, int&); // swaps two integers that are passed by reference
bool isSorted(int*, int, bool); // tests to see if the array is sorted in the correct order
void timeSort(void (*sort)(int*, int, bool), int*, int, bool); // generic size array timing array 


int main() {
	
	bool ascending = true; // boolean to see which way the array is to be sorted
	srand(time(NULL)); // seed the random number generator
	int sizesLen = 13;
	int sizes[] = {10, 20, 50, 500, 700, 1000, 5000, 7500, 12000, 25000, 50000, 60000, 100000}; // Amount of integers test cases
	/*
	std::cout << "Sorting in Ascending order!" << std::endl;
	std::cout << "Bubble Sort: " << std::endl;
	for (int i = 0; i < sizesLen; i++) { // Bubble sort ascending tests
		int *arr = makeArray(sizes[i]);
		int len = sizes[i];
		timeSort(bubbleSort, arr, len, ascending);
	}
	
	std::cout << "Selection Sort: " << std::endl;
	for (int i = 0; i < sizesLen; i++) { // Selection sort ascending tests
		int *arr = makeArray(sizes[i]);
		int len = sizes[i];
		timeSort(selectionSort, arr, len, ascending);
	}
	
	std::cout << "Insertion Sort: " << std::endl;
	for (int i = 0; i < sizesLen; i++) { // Insertion sort ascending tests
		int *arr = makeArray(sizes[i]);
		int len = sizes[i];
		timeSort(insertionSort, arr, len, ascending);
	}
	
	std::cout << "Sorting in Descending order!" << std::endl;
	std::cout << "Bubble Sort: " << std::endl;
	for (int i = 0; i < sizesLen; i++) { // Bubble sort descending tests
		int *arr = makeArray(sizes[i]);
		int len = sizes[i];
		timeSort(bubbleSort, arr, len, ascending);
	}

	std::cout << "Selection Sort: " << std::endl;
	for (int i = 0; i < sizesLen; i++) { // Selection sort descending tests
		int *arr = makeArray(sizes[i]);
		int len = sizes[i];
		timeSort(selectionSort, arr, len, ascending);
	}

	std::cout << "Insertion Sort: " << std::endl;
	for (int i = 0; i < sizesLen; i++) { // Insertion sort descending tests
		int *arr = makeArray(sizes[i]);
		int len = sizes[i];
		timeSort(insertionSort, arr, len, ascending);
	}
	*/
	ascending = true;
	std::cout << "Sorting Worst Case scenario!" << std::endl;
	std::cout << "Bubble Sort: " << std::endl;
	for (int i = 0; i < sizesLen; i++) {
		int *arr = makeArray2(sizes[i]);
		int len = sizes[i];
		timeSort(bubbleSort, arr, len, ascending);
	}

	std::cout << "Selection Sort: " << std::endl;
	for (int i = 0; i < sizesLen; i++) {
		int *arr = makeArray2(sizes[i]);
		int len = sizes[i];
		timeSort(selectionSort, arr, len, ascending);
	}

	std::cout << "Insertion Sort: " << std::endl;
	for (int i = 0; i < sizesLen; i++) {
		int *arr = makeArray2(sizes[i]);
		int len = sizes[i];
		timeSort(insertionSort, arr, len, ascending);
	}

	return 0;
}

/*
 * timeSort Function:
 * Calculate the time it takes for specific sorting algorithms to run on and completely sorted 
 */
void timeSort(void (*sort)(int*, int, bool), int* a, int len, bool isAsc) {
	auto start = std::chrono::system_clock::now();
	
	sort(a, len, isAsc);

	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	std::cout << "Finished at " << std::ctime(&end_time) << "Elapsed time: " << elapsed_seconds.count() << "s\n";
	std::cout << "Amount of swaps " << count << std::endl;
	if (isSorted(a, len, isAsc)) {
		std::cout << "Sorted in correct order!" << std::endl;
	} else {
		std::cout << "Not sorted correctly!" << std::endl;
	}
	count = 0;
	delete [] a;
}

/*
 * makeArray Function:
 * Takes an int that is the length of an array and then dynamically creates that array and returns
 * a pointer to that array
 */
int* makeArray(int len) {
	int *rtn = new int[len];
	for (int i = 0; i < len; i++) {
		rtn[i] = 1 + rand() % 100; // from 1 to 100
	}
	return rtn;
}

int* makeArray2(int len) {
	int *rtn = new int[len];
	for (int i = len - 1; i >= 0; i--) {
		rtn[i] = i;
	}
	return rtn;
}

/*
 * isSorted Function:
 * Takes a dynamic array, a lenth of that array, and whether the array is supposed to be sorted
 * in ascending or descending order and tahtn determines if the array is sorted correctly
 */
bool isSorted(int* arr, int length, bool ascending) {
	if (ascending) {
		for (int i = 0; i < (length - 1); i++) {
			if (arr[i] > arr[i + 1]) {
				return false;
			}
		}
		return true;
	} else {
		for (int i = 0; i < (length - 1); i++) {
			if (arr[i] < arr[i + 1]) {
				return false;
			}
		}
		return true;
	}
}

/*
 * swap Function:
 * Takes two array elements by reference and swaps them
 */
void swap(int& prev, int& next) {
	int temp = prev;
	prev = next;
	next = temp;
	count++; // remember to make it 0 after each test
}

/*
 * bubbleSort Function:
 * Takes a dynamic array, the length of the array, and whether the array is to be sorted in ascending
 * or descending and then sorts the array
 */
void bubbleSort(int* arr, int length, bool ascending) {
	bool didSwap = true;
	while (didSwap) {
		didSwap = false;
		for (int i = 0; i < (length - 1); i++) {
			if (ascending) {
				if (arr[i] > arr[i + 1]) {
					swap(arr[i], arr[i + 1]);
					didSwap = true;	
				}
			} else {
				if (arr[i] < arr[i + 1]) {
					swap(arr[i], arr[i + 1]);
					didSwap = true;	
				}
			}
		}
	}
}

/* 
 *  * selectionSort Function:
 *   * Takes a dynamic array, the length of the array, and whether the array is to be sorted in ascending 
 *    * or descending order and then sorts the array
 *     */
void selectionSort(int* arr, int length, bool ascending) {
	int min;
	for (int i = 0; i < length - 1; i++) {
		min = i;
		for (int j = i + 1; j < length; j++) {
			if (ascending) {
				if (arr[j] < arr[min]) {
					min = j;
				}
			} else {
				if (arr[j] > arr[min]) {
					min = j;
				}
			}
		}
	swap(arr[i], arr[min]);
	}		
}

/*
 *  * insertionSort Function:
 *   * Takes a dynamic array, the length of the array, and whether the array is to be sorted in ascending
 *    * or descending order and then sorts the array
 *     */
void insertionSort(int* arr, int length, bool ascending) {
	int j;
	for (int i = 1; i < length; i++) {
		j = i;
		if (ascending) {
			while ((j > 0) && (arr[j] < arr[j - 1])) {
				swap(arr[j], arr[j - 1]);
				j = j - 1;
			}	
		} else {
			while ((j > 0) && (arr[j] > arr[j - 1])) {
				swap(arr[j], arr[j - 1]);
				j = j - 1;
			}
		}
	}
}
