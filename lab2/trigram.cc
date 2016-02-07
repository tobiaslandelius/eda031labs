#include "trigram.h"
#include <algorithm>

using namespace std;

vector<string> Trigram::trigrams(const string &word) {
  vector<string> substrings;
  if (word.size() < 3) {
    return substrings;
  }
  for (unsigned int i = 0; i != word.length() - 2; ++i) {
    substrings.push_back(word.substr(i, 3));
  }
  sort(substrings.begin(), substrings.end());
  return substrings;
}