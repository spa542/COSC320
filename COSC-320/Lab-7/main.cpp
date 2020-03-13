#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>

size_t hash(size_t); // Hashes a given integer based off the multiplication method
void displayHash(size_t); // Takes a size_t and displays the hash in hexadecimal

int main() {

	std::cout << "Integer: " << 5 << std::endl;
	displayHash(hash(5));

	return 0;
} 

/*
 * hash Function:
 * Hashes a function based on a given integer using the multiplication method
 */
size_t hash(size_t num) {
	size_t W = pow(2, 64);
	size_t M = pow(2, 43);
	size_t a = 17;
	
	size_t mod = a * num % W;
	size_t moo = mod / pow(2, 21);
	std::cout << mod << std::endl;
	std::cout << moo << std::endl;

	return 1;
}

/*
 * displayHash Function:
 * Function that turns the hash into a hexadecimal to be able to be displayed on screen
 */
void displayHash(size_t num) {
	std::cout << "Hash is " << std::hex << num << std::endl;
}
