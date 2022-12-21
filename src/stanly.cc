#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include "Scompile.hh"

int main() {
	std::cout << "Hello Stanly!" << std::endl;
	std::cout << "Testing:\n" << std::endl;

	compile::genC("");
	return 0;
}
