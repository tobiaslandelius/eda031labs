#include <string>
#include <vector>
#include <algorithm>
#include "word.h"

using namespace std;

Word::Word(const string &w, const vector<string> &t) : word(w), trigrams(t) {}

string Word::get_word() const { return word; }

unsigned int Word::get_matches(const vector<string> &t) const {
  unsigned int res = 0;
  auto start = trigrams.begin();
  auto end = trigrams.end();
  for (const string &s : t) {
    start = find(start, end, s);
    if (start == end)
      break;
    ++res;
  }
  return res;
}
