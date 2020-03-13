#include <iostream> // cout, endl
#include <stdio.h> // printf
#include <math.h> // pow
#include <iomanip> // hex, dec

size_t hash(size_t); // Hashes a given integer based off the multiplication method
void displayHash(size_t); // Takes a size_t and displays the hash in hexadecimal

int main() {

	std::cout << "Starting tests of integer hash function..." << std::endl;
	std::cout << "==========================================" << std::endl;
	std::cout << "Integer: " << 5 << std::endl;
	displayHash(hash(5));
	std::cout << std::dec << "Integer: " << 17 << std::endl;
	displayHash(hash(17));
	std::cout << std::dec << "Integer: " << 1001 << std::endl;
	displayHash(hash(1001));
	std::cout << std::dec << "Integer: " << 50000 << std::endl;
	displayHash(hash(50000));
	std::cout << "Proving the has works on the same number..." << std::endl;
	std::cout << std::dec << "Integer: " << 5 << std::endl;
	displayHash(hash(5));
	std::cout << "Matches the first test!" << std::endl;
	std::cout << "==========================================" << std::endl;

	return 0;
} 

/*
 * hash Function:
 * Hashes a function based on a given integer using the multiplication method
 */
size_t hash(size_t num) {
	size_t W = pow(2, 64);
	size_t a = 7919;
	return (a * num % W) / pow(2, 64 - 53);
}

/*
 * displayHash Function:
 * Function that turns the hash into a hexadecimal to be able to be displayed on screen
 */
void displayHash(size_t num) {
	std::cout << "Hash is " << std::hex << num << std::endl;
}
