#ifndef _HASHLIST_H_
#define _HASHLIST_H_
#include <iostream>
#include <string>

class HashList {
	private:
		struct HashNode {
			std::string word;
			HashNode* next;
			HashNode* prev;
		};

		HashNode* head;
		HashNode* tail;
	public:
		HashList(); // Default Constructor
		HashList(const HashList&); // Copy Constructor
		~HashList(); // Deconstructor
		HashList& operator=(const HashList&); // Overloaded Assignment

		void insert(std::string); // Inserts a string node at the head of list
		void print(); // Prints the linked list for testing purposes
};

#endif
