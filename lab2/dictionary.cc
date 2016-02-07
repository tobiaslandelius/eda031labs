#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"

using namespace std;

Dictionary::Dictionary() {

  ifstream fin("words.txt");
  string word;
  while (fin >> word) {
    words.insert(word);
    fin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
  fin.close();
}

bool Dictionary::contains(const string &word) const {
  auto got = words.find(word);
  return got != words.end();
}

vector<string> Dictionary::get_suggestions(const string &word) const {
  cout << word;
  vector<string> suggestions;
  return suggestions;
}
