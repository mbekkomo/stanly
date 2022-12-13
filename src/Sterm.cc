#include "termcolor/termcolor.hpp"
#include "Sterm.hh"

#include <iostream>
#include <string>

namespace tc = termcolor;

std::string indent = "  ";

constexpr int cGrey = 250;
constexpr int cGreen = 10;
constexpr int cYellow = 11;

void term::logInfo(std::string txt) {
	std::cout << tc::color<cGrey> << ':'
		<< tc::color<cGreen> << "•"
		<< tc::color<cGrey> << ':'
		<< tc::reset << indent
		<< txt << std::endl;
}

void term::logWarning(std::string txt) {
	std::cout << tc::color<cGrey> << ':'
		<< tc::color<cYellow> << '?'
		<< tc::color<cGrey> << ':'
		<< tc::reset << indent
		<< txt << std::endl;
}
