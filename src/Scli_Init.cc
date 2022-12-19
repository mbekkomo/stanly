#include "Scli_Init.hh"
#include "Sterm.hh"

#include <fstream>
#include <iostream>
#include <sstream>
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
	std::ostringstream fContent;
	fContent << "# What Lua and Luarocks should be used\n"
		<< "lua-version: \"" << finfo[0] << "\"\n"
		<< "luarocks-version: \"" << finfo[1] << "\"\n\n"
		<< "# What Lua file that should be compiled to static binary\n"
		<< "lua-file: \"" << finfo[2] << '"' << std::endl;

	std::ofstream slyYaml("project.sly.yaml");
	slyYaml << fContent.str();
	slyYaml.close();

	term::logSuccess(std::string("successfully created `") + std::filesystem::absolute("project.sly.yaml").string() + std::string("`"));
}

void cli_Init::cmdInit() {
	cli_Init::createSlyFile(cli_Init::promptInit());
}
