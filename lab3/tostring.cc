#include <sstream>
#include "tostring.h"

template <typename T>
std::string toString(const T& t) {
	std::ostringstream oss;
	oss << t;
	return oss.str();
}


int main() {
	double d = 1.234;
	std::string sd = toString(d);
}