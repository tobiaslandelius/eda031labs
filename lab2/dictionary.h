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
  std::vector<Word> words[allowedLength];
  void add_trigram_suggestions(std::vector<std::string> &suggestions,
                               const std::string word) const;
  void rank_suggestions(std::vector<std::string> &suggestions,
                        const std::string word) const;
  void trim_suggestions(std::vector<std::string> &suggestions) const;
  unsigned int distance(const std::string &s1, const std::string &s2) const;
  bool compare(const std::string &s1, const std::string &s2) const;
};

#endif
