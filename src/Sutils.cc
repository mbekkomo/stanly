#include "Sutils.hh"

#include <cstdio>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

	template<typename T>
std::string utils::vectorJoin(std::vector<T> const &vec, std::string delim)
{
	if (vec.empty()) {
		return std::string();
	}

	return std::accumulate(vec.begin() + 1, vec.end(), std::to_string(vec[0]),
		[](const std::string& a, T b){
			return a + ", " + std::to_string(b);
		});
}

std::string utils::stringToCHex(std::string characters) {
	std::vector<std::string> hex;
	char* buff;

	for (size_t i = 0; i < sizeof(characters); i++) {
		std::sprintf(buff,"0x%02x",int(characters[i]));
		hex.push_back((std::string) buff);
	}

	return utils::vectorJoin(hex, ", ");
}
