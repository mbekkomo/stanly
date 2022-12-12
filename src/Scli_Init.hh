#ifndef Scli_Init_HH
#define Scli_Init_HH

#include <string>
#include <vector>

namespace cli_Init {
	typedef struct {
		std::string luaVersion;
		std::string luarocksVersion;
		std::vector<std::string> luarocksDeps;
	} SlyInfo_t;

	SlyInfo_t promptInit(void);
}

#endif /* Scli_Init_HH */
