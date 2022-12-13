#include "termcolor/termcolor.hpp"
#include "Scli_Init.hh"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
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

std::vector<std::string> cli_Init::promptInit() {
	std::string luaVersion = prompt("lua version",latestLuaVersion);
	std::string luarocksVersion = prompt("luarocks version",latestLuarocksVersion);

	std::string luaFile;
	while (true) {
		luaFile = prompt("lua file");

		if (! std::filesystem::exists(luaFile)) {
			std::cerr << termcolor::red << termcolor::bold
				<< "invalid path to lua file!\n"
				<< termcolor::reset;
			continue;
		}

		std::smatch _;
		if (! std::regex_match(luaFile,_,(std::regex) ".+?\\.lua$")) {
			std::cerr << termcolor::red << termcolor::bold
				<< "not a lua file!\n"
				<< termcolor::reset;
			continue;
		}

		break;
	}

	std::vector<std::string> finfo;
	finfo.push_back(luaVersion);
	finfo.push_back(luarocksVersion);
	finfo.push_back(std::filesystem::absolute(luaFile));
	return finfo;
}

void cli_Init::createSlyFile(std::vector<std::string> finfo) {
	std::string codeF[3] = {
		"lua ",
		"luarocks ",
		"file "
	};

	std::string fContent = "";
	for (int i = 0; i < finfo.size(); i++) {
		fContent += codeF[i] + finfo[i] + '\n';
	}

	std::ofstream slyF;
	slyF.open("build.sly");
	slyF << fContent;
	slyF.close();

	std::cout << termcolor::green << termcolor::bold
		<< "created `build.sly`\n"
		<< termcolor::reset;
}

void cli_Init::cmdInit() {
	cli_Init::createSlyFile(cli_Init::promptInit());
}
