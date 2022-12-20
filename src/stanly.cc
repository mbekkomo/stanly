#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include "Sutils.hh"

int main() {
	std::cout << "Hello Stanly!" << std::endl;
	std::cout << "Testing:\n" << std::endl;
	
	std::vector<std::string> a(2,{"a","b"});

	std::cout << utils::vectorJoin(a,"") << std::endl;
	return 0;
}
