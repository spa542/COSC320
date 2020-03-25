#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include "Dictionary.h"

int main(int argc, char** argv) {

	int argCount = argc;
	if (argCount != 2) { // Error Code for incorrect arguments
		std::perror("Cannot Execute Program: Error Code\n\t--Amount of arguments incorrect");
		exit(1);
	}
	std::ifstream inFile;
	try {
			inFile.open(argv[1]);
	} catch (...) {
		std::perror("Error: File input not found"); // Error code for incorrect file name
		exit(1);
	}
	
	Dictionary d;
	std::string inputWord;

	while(inFile.peek() != EOF) {
		inFile >> inputWord;
		d.insert(inputWord);
	}
	
	return 0;
}
