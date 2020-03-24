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

		int hash(std::string); // Hashes a given string and returns and int
};

#endif
