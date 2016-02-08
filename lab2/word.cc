#include <iostream>
#include <string>
#include <vector>
#include "word.h"
#include "trigram.h"

using namespace std;

Word::Word(const string& w, const vector<string>& t) : word(w), trigrams(t) {}

string Word::get_word() const { return word; }

// Not done!
unsigned int Word::get_matches(const vector<string>& t) const {
  int count = 0;
  unsigned int i = 0, j = 0;

  while (i < t.size() && j < trigrams.size()) {
    int comp = t[i].compare(trigrams[j]);
    if (comp < 0) {
      i++;
    } else if (comp > 0) {
      j++;
    } else {
      count++;
      i++;
    }
  }
  return count;
}
