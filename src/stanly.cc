#include <iostream>
#include <ostream>
#include "Scli_Init.hh"

int main() {
	std::cout << "Hello Stanly!" << std::endl;
	std::cout << "Testing:\n" << std::endl;
	
	cli_Init::cmdInit();
	return 0;
}
