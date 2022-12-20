#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include "Sutils.hh"

int main() {
	std::cout << "Hello Stanly!" << std::endl;
	std::cout << "Testing:\n" << std::endl;

	std::cout << utils::stringToCHex("hello") << std::endl;
	return 0;
}
