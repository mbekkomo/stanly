#ifndef Sutils_HH
#define Sutils_HH

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace utils {
	template<typename ... Args>
	std::string string_format( const std::string& format, Args ... args );

	template <typename T>
	std::string vectorJoin(std::vector<T> const &vec, std::string delim = "");
	std::string stringToCHex(std::string characters);
	std::string execCommand(std::string command);
}

#endif /* Sutils_HH */
