/*
   COPYRIGHT (C) 2017 Student Name (UANET ID ) All rights reserved.
   CSII assignment 9
   Author.  Student Name
            zippy@zips.uakron.edu
   Version. 1.01 09.09.2017
   Purpose: This program is the test cases for the assignment
*/
#include <iostream>
#include <iomanip>

// prototypes
void unpackCharacters(char[], unsigned);
void displayBits(unsigned);
using namespace std;

int main() {
   char characters[4];
   unsigned packed{1633903975}; // a, c, e, g

   cout << "The packed character representation is:\n";
   displayBits(packed);

   // demonstrate unpacking of characters
   unpackCharacters(characters, packed);
   cout << "\nThe unpacked characters are: ";
   for (size_t i{0}; i < 4; ++i) {
      cout << characters[i] << " ";
   }
   cout << endl;

   cout << "\nThe unpacked characters in bits are:" << endl;
   for (size_t i{0}; i < 4; ++i) {
      displayBits(characters[i]);
   }
}

// take apart the characters
void unpackCharacters(char characters[], unsigned pack)
{
	int num = sizeof(&characters) / sizeof(*characters);
	for (int i = 0; i < num; i++) {
		characters[num-1 - i] = (pack & (0xff << (8 * i))) >> (8 * i);
	}
}

// display the bits of value
void displayBits(unsigned value)
{
	const int SHIFT = 8 * sizeof(unsigned) - 1;
	const unsigned MASK = 1 << SHIFT;

	std::cout << std::setw( 10 ) << value << " = ";

	// display bits
	for (unsigned i = 1; i <= SHIFT + 1; i++) {
		std::cout << (value & MASK ? '1' : '0');
		value <<= 1; // shift value left by 1
		if (i % 8 == 0) // output a space after 8 bits
			std::cout << ' ';
	}

	std::cout << std::endl;
}
