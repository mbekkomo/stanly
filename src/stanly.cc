#include <iostream>
#include <ostream>
#include "Scli_Init.hh"

int main() {
	std::cout << "Hello Stanly!" << std::endl;
	std::cout << "Testing:" << std::endl;
	cli_Init::promptInit();
	return 0;
}
