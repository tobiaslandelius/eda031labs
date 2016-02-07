#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
#include <unordered_set>
#include "word.h"

class Dictionary {
public:
  Dictionary();
  bool contains(const std::string &word) const;
  std::vector<std::string> get_suggestions(const std::string &word) const;
  static const unsigned int allowedLength = 25;

private:
  std::unordered_set<std::string> wordlist;
  std::vector<Word> words[allowedLength - 1];
  void add_trigram_suggestions(std::vector<std::string> &suggestions,
                               const std::string word);
};

#endif
