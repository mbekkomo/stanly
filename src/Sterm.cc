#include "termcolor/termcolor.hpp"
#include "Sterm.hh"

#include <iostream>
#include <string>

namespace tc = termcolor;

std::string indent = "  ";

constexpr int cGrey = 246;
constexpr int cGreen = 10;
constexpr int cYellow = 11;
constexpr int cRed = 9;

void term::logInfo(std::string txt) {
	std::cout << tc::bold
		<< tc::color<cGrey> << '|'
		<< tc::color<cGreen> << "•"
		<< tc::color<cGrey> << '|'
		<< tc::reset << indent
		<< txt << std::endl;
}

void term::logWarning(std::string txt) {
	std::cout << tc::bold
		<< tc::color<cGrey> << '|'
		<< tc::color<cYellow> << '!'
		<< tc::color<cGrey> << '|'
		<< tc::reset << indent
		<< txt << std::endl;
}

void term::logError(std::string txt) {
	std::cout << tc::bold
		<< tc::color<cGrey> << '|'
		<< tc::color<cRed> << '!'
		<< tc::color<cGrey> << '|'
		<< tc::reset << indent
		<< txt << std::endl;
}

void term::logFailure(std::string txt) {
	std::cout << tc::bold
		<< tc::color<cGrey> << '|'
		<< tc::color<cRed> << '-'
		<< tc::color <cGrey> << '|'
		<< tc::reset << indent
		<< txt << std::endl;
}
