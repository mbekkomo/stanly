#include "Scompile.hh"

#include <iostream>
#include <filesystem>
#include <string>

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

std::string compile::genC(std::string text) {

}
