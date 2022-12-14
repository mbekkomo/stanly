#include <iostream>
#include <ostream>
#include "Sterm.hh"

int main() {
	std::cout << "Hello Stanly!" << std::endl;
	std::cout << "Testing:" << std::endl;
	term::logInfo("test");
	term::logWarning("wow");
	term::logError("ehh");
	term::logFailure("fail to uwu");
	return 0;
}
