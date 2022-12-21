#include "Scompile.hh"

#include <iostream>
#include <string>
#include <filesystem>
#include <vector>
#include <map>

#include <cstdlib>

std::string CC = std::getenv("CC") ? std::getenv("CC") : "cc";
std::string NM = std::getenv("NM") ? std::getenv("NM") : "nm";

bool isSourceFile(std::string extFile) {
	return
		extFile == "lua" ||
		extFile == "luac";
}

bool isBinaryLibrary(std::string extFile) {
	return
		extFile == "o"    ||
		extFile == "so"   ||
		extFile == "a"    ||
		extFile == "dylib";
}

std::string compile::genC(std::string text, std::map<std::string, std::vector<std::string>> info) {
	std::cout << CC << std::endl;
	return "";
}
