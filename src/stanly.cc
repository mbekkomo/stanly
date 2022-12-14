#include <iostream>
#include <ostream>
#include "Sterm.hh"

int main() {
	std::cout << "Hello Stanly!" << std::endl;
	std::cout << "Testing:\n" << std::endl;

	term::logInfo("test");
	term::logWarning("wow");
	term::logError("ehh");
	term::logFailure("fail to uwu");
	term::logSuccess("hi hi");

	std::string input1 = term::prompt("hi");
	std::string input2 = term::prompt("hi","hello");
	std::string input3 = term::prompt("hi","hello",true);

	std::cout << input1 + '\n'
		<< input2 + '\n'
		<< input3 << std::endl;
	return 0;
}
