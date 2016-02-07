#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "trigram.h"
#include <cctype>

using namespace std;

int main() {
  ifstream fin("words");
  ofstream fout("words.txt");

  string word;
  while (getline(fin, word)) {

    for (std::string::size_type i = 0; i < word.length(); ++i)
      word[i] = tolower(word[i]);

    vector<string> trigrams = Trigram::trigrams(word);
    fout << word << " " << trigrams.size();

    for (string sub : trigrams) {
      fout << " " << sub;
    }
    fout << "\n";
  }
  fin.close();
  fout.close();
}
