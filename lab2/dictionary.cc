#include <fstream>
#include <iostream>
#include <algorithm>
#include "dictionary.h"
#include "trigram.h"

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
  vector<string> suggestions;
  add_trigram_suggestions(suggestions, word);
  rank_suggestions(suggestions, word);
  return suggestions;
}

void Dictionary::add_trigram_suggestions(std::vector<std::string> &suggestions,
                                         const std::string word) const {
  std::vector<string> t = Trigram::trigrams(word);
  unsigned int requiredMatches = t.size() / 2;
  int length = word.length();
  for (int i = length - 1; i != length + 2; ++i)
    for (Word w : words[i])
      if (w.get_matches(t) >= requiredMatches)
        suggestions.push_back(w.get_word());
}

void Dictionary::rank_suggestions(std::vector<std::string> &suggestions,
                                  const std::string word) const {
  std::vector<pair<unsigned int, string>> v;
  for (string s : suggestions) v.push_back(make_pair(distance(s, word), s));
  sort(v.begin(), v.end());
}

unsigned int Dictionary::distance(std::string &s1,
                                  const std::string &s2) const {
  unsigned int d[allowedLength + 1][allowedLength + 1];

  for (int i = 0; i != allowedLength + 1; ++i) {
    d[0][i] = 0;
    d[i][0] = 0;
  }

  unsigned int diag = 0;
  unsigned int above = 0;
  unsigned int left = 0;

  for (int i = 1; i != allowedLength + 1; ++i) {
    for (int j = 1; j != allowedLength + 1; ++j) {
      left = d[i][j - 1] + 1;
      above = d[i - 1][j] + 1;
      diag = d[i - 1][j - 1];
      if (s1[i] != s2[j]) ++diag;
      d[i][j] = min(left, min(above, diag));
    }
  }

  return d[s1.length()][s2.length()];
}
