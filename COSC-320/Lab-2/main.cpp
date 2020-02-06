#include <iostream> // cout, endl
#include <stdio.h> // printf
#include <time.h> // time functions
#include <chrono> // chrono

void quickSort(int*, int, int); // sorts array using Quick Sort algorithm
int partition(int*, int, int); // partitions array for quickSort function
int* mergeSort(int*, int, int); // sorts array using Merge Sort algorithm
int* merge(int*, int, int*, int); // returns a sorted array to the mergeSort function
int* makeArray(int); // creates a dynamically allocated array with passed limit
void swap(int&, int&); // swaps two integers
bool isSorted(int*, int); // checks to see if array is sorted
void timeSort(int* (*sort)(int*, int, int), int*, int, int); // calculates the time it takes to sort an array

int count = 0;

int main() {

	srand(time(NULL)); // Seed the random number generator
	int sizesLen = 15; // Length of test case array
	int sizes[] = {10, 20, 50, 500, 700, 1000, 5000, 7500, 12000, 25000, 50000, 60000, 100000, 500000, 1000000}; // Amount of integers test cases

	std::cout << "Sorting in Ascending order!" << std::endl;
	std::cout << "Merge Sort: " << std::endl;
	for (int i = 0; i < sizesLen; i++) {
		int *arr = makeArray(sizes[i]);
		int len = sizes[i];
		timeSort(mergeSort, arr, 0, len);
	}

	return 0;
}

/*
 * timeSort Function:
 * Calculate the time it takes for specific sorting algorithms to run on and 
 * how long they take to sort
 */
void timeSort(int* (*sort)(int*, int, int), int* a, int l, int r) {
	auto start = std::chrono::system_clock::now();
	sort(a, l, r);
	
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	std::cout << "Finished at " << std::ctime(&end_time) << "Elapsed time: " << elapsed_seconds.count() << "s\n";
	std::cout << "Amount of swaps " << count << std::endl;
	if (isSorted(a, r)) {
		std::cout << "Sorted in correct order!" << std::endl;
	} else {
		std::cout << "Not sorted correctly!" << std::endl;
	}
	count = 0;
	delete [] a;
}

/*
 * makeArray Function:
 * Creates and fills an array based off of a specified limit
 */
int* makeArray(int len) {
	int* rtn = new int[len];
	for (int i = 0; i < len; i++) {
		rtn[i] = 1 + rand() % 100;
	}
	return rtn;
}

/*
 * isSorted Function:
 * Takes a dynamic array and a length of that array and scans the array to test 
 * if it is sorted in the correct ascending order and then determines if the array
 * is sorted correctly
 */
bool isSorted(int* arr, int length) {
	for (int i = 0; i < (length - 1); i++) {
		if (arr[i] > arr[i + 1]) {
			return false;
		}
	}
	return true;
}

/*
 * mergeSort Function:
 * Sorts an array of integers using the Merge Sort algorithm 
 */
int* mergeSort(int* arr, int l, int r) {
	if (l < r - 1) {
		int p = (l + r) / 2;
		int* L1 = mergeSort(arr, l, p);
		int* L2 = mergeSort(arr, p, r);
		arr = merge(L1, p,  L2, r - p);
	}
	return arr;
}

/*
 * merge Function:
 * Merges two sorted arrays into one array and then returns it
 */
int* merge(int* a1, int len1, int* a2, int len2) {
	int* rtn = new int[len1 + len2];
	
	int i = 0, j = 0, q = 0;
	while ( i < len1 && j < len2) {
		if (a1[i] < a2[j]) {
			rtn[q] = a1[i];
			i++;
		} else {
			rtn[q] = a2[j];
			j++;
		}
		q++;
	}

	while ( i < len1 ) {
		rtn[q] = a1[i];
		i++;
		q++;
	}

	while( j < len2 ) {
		rtn[q] = a2[j];
		j++;
		q++;
	}
	
	return rtn;
}

/*
 * swap Function:
 * Takes two array elements by reference and swaps them
 */
void swap(int& prev, int& next) {
	int temp = prev;
	prev = next;
	next = temp;
	count++;
}

/*
 * quickSort Function:
 * Sorts and array of integers using the Quick Sort algorithm
 */
void quickSort(int* arr, int l, int r) {

}

/*
 * partition Function:
 * Returns a partition that will be used for the quickSort function after sorting
 */
int partition(int* a, int l, int r) {

}
