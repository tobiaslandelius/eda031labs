#include <fstream>
#include <algorithm>
#include <unordered_map>
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
    vector<string> trigrams;
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
  trim_suggestions(suggestions);
  return suggestions;
}

void Dictionary::add_trigram_suggestions(vector<string> &suggestions,
                                         const string word) const {
  vector<string> t = Trigram::trigrams(word);
  unsigned int requiredMatches = t.size() / 2;
  int length = word.length();
  for (int i = length - 1; i != length + 2; ++i)
    for (Word w : words[i])
      if (w.get_matches(t) >= requiredMatches)
        suggestions.push_back(w.get_word());
}

void Dictionary::rank_suggestions(vector<string> &suggestions,
                                  const string word) const {
  unordered_map<string, int> dist;

  for (string s : suggestions)
    dist.insert(make_pair(s, distance(s, word)));

  struct Compare {
    Compare(unordered_map<string, int> d) { this->d = d; }
    bool operator()(string i, string j) { return (d[i] < d[j]); }

    unordered_map<string, int> d;
  };

  sort(suggestions.begin(), suggestions.end(), Compare(dist));
}

void Dictionary::trim_suggestions(vector<string> &suggestions) const {
  suggestions.resize(5);
}

unsigned int Dictionary::distance(const string &s1, const string &s2) const {
  unsigned int d[allowedLength + 1][allowedLength + 1];

  for (int i = 0; i != allowedLength + 1; ++i) {
    d[0][i] = i;
    d[i][0] = i;
  }

  unsigned int diag = 0;
  unsigned int above = 0;
  unsigned int left = 0;

  for (int i = 1; i != allowedLength + 1; ++i) {
    for (int j = 1; j != allowedLength + 1; ++j) {
      left = d[i][j - 1] + 1;
      above = d[i - 1][j] + 1;
      diag = d[i - 1][j - 1];
      if (s1[i] != s2[j])
        ++diag;
      d[i][j] = min(left, min(above, diag));
    }
  }

  return d[s1.length()][s2.length()];
}
