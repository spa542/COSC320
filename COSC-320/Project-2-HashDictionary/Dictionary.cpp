#include "Dictionary.h"

/*
 * Default Constructor:
 * Initializes private member data to default attributes
 */
Dictionary::Dictionary() {
	arr = new HashList[10000];
	length = 10000;
}

/*
 * Copy Constructor:
 * Does necessary operations in order to deep copy
 */
Dictionary::Dictionary(const Dictionary& old) {
	arr = new HashList[old.length];
	length = old.length;
	for (int i = 0; i < length; i++) {
		arr[i] = old.arr[i];
	}
}

/*
 * Destructor:
 * Deallocates dynamically allocated data
 */
Dictionary::~Dictionary() {
	delete [] arr;
}

/*
 * Overloaded Assignment:
 * Performs a necessary deep copy for assignment
 */
Dictionary& Dictionary::operator=(const Dictionary& rhs) {
	if (this == &rhs) {
		return *this;
	}

	delete [] arr;

	arr = new HashList[rhs.length];
	length = rhs.length;
	for (int i = 0; i < length; i++) {
		arr[i] = rhs.arr[i];
	}

	return *this;
}

/*
 * hash Function:
 * Hashes an a string into an index to be inserted into an array
 */
int Dictionary::hash(std::string hashMe) {
	
}
