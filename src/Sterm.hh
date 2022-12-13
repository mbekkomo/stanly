#ifndef Sterm_HH
#define Sterm_HH

#include <iostream>
#include <string>

namespace term {
	void logInfo(std::string txt);
	void logWarning(std::string txt);
	void logError(std::string txt);
	void logFailure(std::string txt);
	void logSuccess(std::string txt);
	std::string prompt(std::string txt, std::string defaultValue = "");
}

#endif /* Sterm_HH */
