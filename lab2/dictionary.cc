#include <fstream>
#include <iostream>
#include <algorithm>
#include "dictionary.h"

using namespace std;

Dictionary::Dictionary() {

  ifstream fin("words.txt");
  string word;
  string w;
  int n = 0;
  while (fin >> w) {
    word = w;
    fin >> w;
    n = stoi(w);
    std::vector<string> trigrams;
    for (int i = 0; i != n; ++i) {
      fin >> w;
      trigrams.push_back(w);
    }
    words[word.length()].push_back(Word(word, trigrams));
    wordlist.insert(word);
  }
  fin.close();
}

bool Dictionary::contains(const string &word) const {
  auto got = wordlist.find(word);
  return got != wordlist.end();
}

vector<string> Dictionary::get_suggestions(const string &word) const {
  cout << word;
  vector<string> suggestions;
  return suggestions;
}
