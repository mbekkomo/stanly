#ifndef Scompile_HH
#define Scompile_HH

#include <iostream>
#include <string>
#include <vector>
#include <map>

namespace compile {
	std::string genC(std::string text, std::map<std::string, std::vector<std::string>> info);
}

#endif /* Scompile_HH */
