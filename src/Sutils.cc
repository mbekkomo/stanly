#include "Sutils.hh"

#include <cstdio>
#include <iostream>
#include <numeric>
#include <memory>
#include <sstream>
#include <string>
#include <stdexcept>
#include <regex>
#include <vector>

	template<typename T>
std::string utils::vectorJoin(std::vector<T> const &vec, std::string delim)
{
	std::stringstream res;
	for (T val : vec)
		res << val << delim;

	return std::regex_replace(res.str(), std::regex(delim + "$"), "");
}

	template<typename ... Args>
std::string utils::string_format( const std::string& format, Args ... args )
{
	int size_s = std::snprintf( nullptr, 0, format.c_str(), args ... ) + 1;
	if ( size_s <= 0 )
		throw std::runtime_error( "Error during formatting." );

	auto size = static_cast<size_t>( size_s );
	std::unique_ptr<char[]> buf( new char[ size ] );
	std::snprintf( buf.get(), size, format.c_str(), args ... );
	return std::string( buf.get(), buf.get() + size - 1 );
}

std::string utils::stringToCHex(std::string characters) {
	std::vector<std::string> hex;
	char* buff;

	for (int i = 0; i < characters.length(); i++)
		hex.push_back(
				utils::string_format("0x%02x", int(characters[i]))
				);

	return utils::vectorJoin(hex, ", ");
}
