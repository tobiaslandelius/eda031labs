#include <sstream>
#include <iostream>

#include "tostring.h"
#include "date.h"

template <typename T>
T string_cast(const std::string& s) {
  std::istringstream oss(s);
  T t;

  oss >> t;

  if (oss.fail()) throw std::invalid_argument("Could not cast from string");

  return t;
}

int main() {
  Date s = string_cast<Date>("qwöqjwqö");
  std::cout << s;
}