#ifndef Scli_Init_HH
#define Scli_Init_HH

#include <string>
#include <vector>

namespace cli_Init {
	std::vector<std::string> promptInit(void);
	void createSlyFile(std::vector<std::string> finfo);
	void cmdInit(void);
}

#endif /* Scli_Init_HH */
