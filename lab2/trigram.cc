#include "trigram.h"
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<string> trigrams(const string &word) {
  vector<string> substrings;
  for (unsigned int i = 0; i != word.length() - 3; ++i) {
    substrings.push_back(word.substr(i, 3));
  }
  sort(substrings.begin(), substrings.end());
  return substrings;
}