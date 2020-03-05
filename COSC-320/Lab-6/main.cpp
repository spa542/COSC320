#include <iostream>
#include <stdio.h>
#include <chrono>
#include <time.h>

namespace CostCount {
	int c = 0;
}

int* makeArray(int); // Creates a dynamic array based off a given length
void shuffle(int*, int); // Shuffles the array randomly
void swap(int&, int&); // Swaps two int elements in the array
void HireAssistant(int*, int); // Simulates the hire assistent algorithm
void interview(int); // Acts as a dumby interview function
void hire(int); // Acts as a dumby hire function
void printArray(int*, int); // prints the array
void randomizedQuickSort(int*, int, int); // Implements randomized quick sort
int partition(int*, int, int); // partition functions for the randomized quick sort
bool isSorted(int*, int); // checks to see if the array is sorted correctly

int main() {
	
	srand(time(NULL));

	int* test = makeArray(10);
	printArray(test, 10);
	shuffle(test, 10);
	printArray(test, 10);	
	delete [] test;
	
	int testCases[] = {10000, 60000, 110000, 160000, 210000, 260000, 310000, 360000, 410000, 460000, 510000, 560000, 
			610000, 660000, 710000, 760000, 810000, 860000, 910000};
	int testLen = 19;	
	for (int i = 0; i < testLen; i++) {
		int *arr = makeArray(testCases[i]);
		int len = testCases[i];
		shuffle(arr, len);
		
		std::cout << "Working on a pool of " << testCases[i] << " applicants." << std::endl;	
		auto start = std::chrono::system_clock::now();

		HireAssistant(arr, len);
		
		auto end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds = end - start;
		std::time_t end_time = std::chrono::system_clock::to_time_t(end);
		std::cout << "Finished at " << std::ctime(&end_time) << "Elapsed time: " << elapsed_seconds.count() << "s\n";
		std::cout << "Amount of work: " << CostCount::c << std::endl;
		CostCount::c = 0;
		delete [] arr;
	}		

	return 0;
}

/*
 * Randomized QuickSort:
 * Implements the randomized QuickSort algorithm
 */
void randomizedQuickSort(int* arr, int l, int r) {
	if (l < r) {
		swap(arr[rand() % (r - l - 1) + l], arr[r - 1]); 
		int p = partition(arr, l, r);
		randomizedQuickSort(arr, l, p);
		randomizedQuickSort(arr, p + 1, r);
	}
}

/*
 * partition Function:
 * Finds a partition and returns that to the quicksort function
 */
int partition(int* arr, int l, int r) {
	int p = arr[r - 1];
	int i = l - 1;
	for (int j = l; j <= r - 2; j++) {
		if (arr[j] < p) {
			i++;
			swap(arr[j], arr[i]);
		}
	}
	swap(arr[r - 1], arr[i + 1]);
	return i + 1;
}

/*
 * isSorted Function:
 * Checks to see if the array is sorted correctly
 */
bool isSorted(int* arr, int len) {
	for (int i = 0; i < len - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			return false;
		}
	} 
	return true;
}

/*
 * HireAssistant Function:
 * Simulates the hire assistant algorithm
 */
void HireAssistant(int* arr, int len) {
	int best = 0;
	for (int i = 0; i < len; i++) {
		interview(arr[i]);
		if (arr[i] > best) {
			best = arr[i];
			hire(arr[i]);
		}
	} 
}

/*
 * interview Function:
 * Acts as a dumby interview function
 */
void interview(int element) {
	CostCount::c++;	
}

/*
 * hire Function:
 * Acts as a dumby hire function
 */
void hire(int element) {
	CostCount::c += 2;
}

/*
 * makeArray Function:
 * Takes a length input by the user and then creates a dynamic array of that length
 */
int* makeArray(int len) {
	int* rtnMe = new int[len];
	for (int i = 0; i < len; i++) {
		rtnMe[i] = i + 1;
	}	
	return rtnMe;
}

/*
 * shuffle Function:
 * Shuffles a given array randomly
 */
void shuffle(int* arr, int len) {
	int rand1 = 0;
	int rand2 = 0;
	for (int i = 0; i < len; i++) {
		rand1 = rand() % len;
		rand2 = rand() % len;
		swap(arr[rand1], arr[rand2]);	
	}		
}

/*
 * swap Function:
 * Swaps two given values in an array
 */
void swap(int& first, int& second) {
	int temp = first;
	first = second;
	second = temp;
}

/*
 * printArray Function:
 * Prints the array for testing purposes
 */
void printArray(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		std::cout << arr[i] << " ";
	} 
	std::cout << std::endl;
}
