#include "termcolor/termcolor.hpp"
#include "Scli_Init.hh"
#include <iostream>
#include <string>

static
std::string doPrompt(std::string text, std::string defValue = "") {
	std::cout << termcolor::bold << text + ' '
		<< termcolor::grey << '(' + defValue + ')'
		<< termcolor::reset
		<< termcolor::bold << ": "
		<< termcolor::reset;

	std::string res;
	std::getline(std::cin,res);
	if (res == "")
		res = defValue;

	return res;
}

std::string latestLuaVersion = "5.4.4";
std::string latestLuarocksVersion = "3.9.2";

cli_Init::SlyInfo_t
cli_Init::promptInit() {
	std::string luaVersion = doPrompt("lua version",latestLuaVersion);
	std::string luarocksVersion = doPrompt("luarocks version",latestLuarocksVersion);
	std::cout << "lua: " + luaVersion
		<< "\nluarocks: " + luarocksVersion << std::endl;

	return (cli_Init::SlyInfo_t) {};
}
