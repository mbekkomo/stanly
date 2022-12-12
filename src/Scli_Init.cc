#include "termcolor/termcolor.hpp"
#include "Scli_Init.hh"

#include <iostream>
#include <string>
#include <regex>
#include <filesystem>

std::string prompt(std::string text, std::string defValue = "") {
	std::cout // V //
		<< termcolor::bold << text + ' '
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

cli_Init::SlyInfo_t cli_Init::promptInit() {
	std::string luaVersion = prompt("lua version",latestLuaVersion);
	std::string luarocksVersion = prompt("luarocks version",latestLuarocksVersion);
start_luaFile:
	std::string luaFile = prompt("lua file");
	
	if (! std::filesystem::exists(luaFile)) {
		std::cerr << termcolor::red << termcolor::bold
			<< "invalid path to lua file!\n"
			<< termcolor::reset;
		goto start_luaFile;
	}

	std::cmatch _;
	if (! std::regex_match(luaFile.c_str(),_,(std::regex) ".+?\\.lua$")) {
		std::cerr << termcolor::red << termcolor::bold
			<< "not a lua file!\n"
			<< termcolor::reset;
		goto start_luaFile;
	}

	std::cout 
		<< "lua: " + luaVersion + '\n'
		<< "luarocks: " + luarocksVersion + '\n'
		<< "lua file: " + luaFile << std::endl;
	return (cli_Init::SlyInfo_t) {};
}
