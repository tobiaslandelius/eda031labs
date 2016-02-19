#include <sstream>
#include <stdexcept>
#include <iostream>
#include "tostring.h"
#include "date.h"

template <typename T>
std::string toString(const T& t) {
  std::ostringstream oss;
  oss << t;
 
  if (oss.fail()) throw std::invalid_argument("FAIL!");
  return oss.str();


}

int main() {
  Date today;
  double d = 1.234;
  std::string sd = toString(d);
  std::string st = toString(today);
  std::cout << sd << std::endl << st;
}