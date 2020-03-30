#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_
#include <iostream>
#include <string>
#include "HashList.h"

class Dictionary {
	private:
		HashList* arr;
		int length;

		int* usage;
	public:
		Dictionary(); // Default Constructor
		Dictionary(const Dictionary&); // Copy Constructor
		~Dictionary(); // Deconstructor
		Dictionary& operator=(const Dictionary&); // Overloaded assignment

		void insert(std::string); // Inserts a given string into the hash table
		size_t hash(std::string); // Hashes a given string and returns an int
		void print(); // Prints the hash table for testing purposes
		void printUsage(); // Prints the amount of use of each element spot
							// in the hash table
		int findBiggestBucket(); // Finds the largest bucket size
		int findSmallestBucket(); // Finds the smalles bucket size
		int countUsedBuckets(); // Returns the amount of buckets filled
		int getLength(); // Gets length of hash table
		double avgNodes(); // Returns the average amount of nodes in each bucket 
};

#endif
