#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_
#include <iostream>
#include <string>
#include "HashList.h"

class Dictionary {
	private:
		HashList* arr;
		int length;
	public:
		Dictionary(); // Default Constructor
		Dictionary(const Dictionary&); // Copy Constructor
		~Dictionary(); // Deconstructor
		Dictionary& operator=(const Dictionary&); // Overloaded assignment

		void insert(std::string); // Inserts a given string into the hash table
		size_t hash(std::string); // Hashes a given string and returns an int
		void print(); // Prints the hash table for testing purposes
};

#endif
