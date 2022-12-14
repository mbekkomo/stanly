#include "termcolor/termcolor.hpp"
#include "Sterm.hh"

#include <iostream>
#include <string>

namespace tc = termcolor;

std::string indent = "  ";

constexpr int cGrey = 246;
constexpr int cPrompt = 7;
constexpr int cGreen = 10;
constexpr int cYellow = 11;
constexpr int cRed = 9;
constexpr int cBlue = 12;

void term::logInfo(std::string txt) {
	std::cout << tc::bold
		<< tc::color<cGrey> << '|'
		<< tc::white << "•"
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

void term::logSuccess(std::string txt) {
	std::cout << tc::bold
		<< tc::color<cGrey> << '|'
		<< tc::color<cGreen> << "✓"
		<< tc::color<cGrey> << '|'
		<< tc::reset << indent
		<< txt << std::endl;
}

std::string term::prompt(std::string txt, std::string defaultValue, bool newline) {
	std::cout << tc::bold
		<< tc::color<cGrey> << '|'
		<< tc::color<cBlue> << '?'
		<< tc::color<cGrey> << '|'
		<< tc::reset << indent
		<< txt;

	if (newline)
		std::cout << ' ' << tc::bold
			<< tc::grey << '(' + defaultValue + ')'
			<< tc::reset
			<< "\n " + indent
			<< tc::color<cGrey> << "-> "
			<< tc::reset << tc::color<cPrompt>;
	else
		std::cout << ' ' << tc::bold
			<< tc::grey << '(' + defaultValue + "):"
			<< tc::reset
			<< " "
			<< tc::color<cPrompt>;
	
	std::string input;
	std::getline(std::cin,input);
	std::cout << tc::reset;

	if (input == "")
		input = defaultValue;

	return input;
}
