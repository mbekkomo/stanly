#include "Scli_Init.hh"
#include "Sterm.hh"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <filesystem>

std::string latestLuaVersion = "5.4.4";
std::string latestLuarocksVersion = "3.9.2";

std::vector<std::string> cli_Init::promptInit() {
	std::string luaVersion = term::prompt("lua version",latestLuaVersion);
	std::string luarocksVersion = term::prompt("luarocks version",latestLuarocksVersion);

	std::string luaFile;
	while (true) {
		luaFile = term::prompt("lua file");

		if (! std::filesystem::exists(luaFile)) {
			term::logError("file not exists!");
			continue;
		}

		std::smatch _;
		if (! std::regex_match(luaFile,_,(std::regex) ".+?\\.lua$")) {
			term::logError("not a lua file!");
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

	term::logSuccess(std::string("successfully created `") + std::filesystem::absolute("build.sly").string() + std::string("`"));
}

void cli_Init::cmdInit() {
	cli_Init::createSlyFile(cli_Init::promptInit());
}
