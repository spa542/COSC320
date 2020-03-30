#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include "Dictionary.h"
#include <time.h>
#include <chrono>

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

	std::cout << "Welcome to the Spell Checker!" << std::endl;
	std::cout << "---------------------------------------------------" << std::endl;
	std::cout << "Loading the database..." << std::endl;
	std::cout << "---------------------------------------------------" << std::endl;

	Dictionary d;
	std::string inputWord;
	int numOfWords = 0;

	auto start = std::chrono::system_clock::now();

	while(inFile.peek() != EOF) {
		std::getline(inFile, inputWord);
		d.insert(inputWord);
		numOfWords++;
	}

	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	std::cout << "Total words = " << numOfWords << std::endl;
	std::cout << "Biggest bucket size = " << d.findBiggestBucket() << std::endl;
	std::cout << "Smallest bucket size = " << d.findSmallestBucket() << std::endl;
	std::cout << "Total number of buckets = " << d.getLength() << std::endl;
	std::cout << "Number of used buckets = " << d.countUsedBuckets() << std::endl;
	std::cout << "Average number of nodes in each bucket = " << d.avgNodes() << std::endl;
	std::cout << "Total time taken = " << elapsed_seconds.count() << "s\n"; 
	
		

	inFile.close();	

	return 0;
}
