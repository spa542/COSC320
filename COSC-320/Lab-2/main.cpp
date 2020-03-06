#include <iostream> // cout, endl
#include <stdio.h> // printf
#include <time.h> // time functions
#include <chrono> // chrono

void quickSort(int*, int, int); // sorts array using Quick Sort algorithm
int partition(int*, int, int); // partitions array for quickSort function
void mergeSort(int*, int, int); // sorts array using Merge Sort algorithm
void merge(int*, int, int, int); // returns a sorted array to the mergeSort function
int* makeArray(int); // creates a dynamically allocated array with passed limit
void swap(int&, int&); // swaps two integers
int* makeArray2(int); // Creates an array made for worst case
bool isSorted(int*, int); // checks to see if array is sorted
void timeSort(void (*sort)(int*, int, int), int*, int, int); // calculates the time it takes to sort an array

int count = 0;

int main() {

	srand(time(NULL)); // Seed the random number generator
	int sizesLen = 19; // Length of test case array
	int sizes[] = {10000, 60000, 110000, 160000, 210000, 260000, 310000, 360000,
		410000, 460000, 510000, 560000, 610000, 660000, 710000, 760000, 810000,
		860000, 910000}; // Amount of integers test cases
	
	std::cout << "===================================\n" << std::endl;
	std::cout << "Sorting in Ascending order!" << std::endl;
	std::cout << "Merge Sort: " << std::endl;
	for (int i = 0; i < 19; i++) {
		int *arr = makeArray(sizes[i]);
		int len = sizes[i];
		timeSort(mergeSort, arr, 0, len - 1);
	}

	std::cout << "===================================\n" << std::endl;
	std::cout << "Quick Sort: " << std::endl;
	for (int i = 0; i < 19; i++) {
		int *arr = makeArray(sizes[i]);
		int len = sizes[i];
		timeSort(quickSort, arr, 0, len - 1);
	}

	std::cout << "===================================\n" << std::endl;
	std::cout << "Sorting in Worst case!" << std::endl;
	std::cout << "Quick Sort: " << std::endl;
	for (int i = 0; i < 10; i++) {
		int *arr = makeArray2(sizes[i]);
		int len = sizes[i];
		timeSort(quickSort, arr, 0, len - 1);
	}
	std::cout << "===================================\n" << std::endl;

	return 0;
}

int* makeArray2(int len) {
	int *rtn = new int[len];
	for (int i = len - 1, j = 0; j < len; j++, i--) {
		rtn[j] = i;
	}
	return rtn;
}

/*
 * timeSort Function:
 * Calculate the time it takes for specific sorting algorithms to run on and 
 * how long they take to sort
 */
void timeSort(void (*sort)(int*, int, int), int* a, int l, int r) {
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
void mergeSort(int* arr, int l, int r) {
	if (l < r) {
		int p = (l + r) / 2;
		mergeSort(arr, l, p);
		mergeSort(arr, p + 1, r);
		merge(arr, l, p, r);
	}
}

/*
 * merge Function:
 * Merges two sorted arrays into one array and then returns it
 */
void merge(int* arr, int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for (int i = 0; i < n1; i++) {
		L[i] = arr[l + i];
	}
	for (int j = 0; j < n2; j++) {
		R[j] = arr[m + j + 1];
	}

	i = j = 0;
	k = l;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
			count++;
		} else {
			arr[k] = R[j];
			j++;
			count++;
		}
		k++;
	}
	
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
		count++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
		count++;
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
	count++;
}

/*
 * quickSort Function:
 * Sorts and array of integers using the Quick Sort algorithm
 */
void quickSort(int* arr, int l, int r) {
	if (l < r) {
		int p = partition(arr, l, r);
		quickSort(arr, l, p);
		quickSort(arr, p + 1, r);
	}
}

/*
 * partition Function:
 * Returns a partition that will be used for the quickSort function after sorting
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
