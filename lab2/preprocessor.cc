#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "trigram.h"
#include <cctype>
#include <algorithm>

using namespace std;

int main() {
  ifstream fin("words");
  ofstream fout("words.txt");

  string word;
  while (getline(fin, word)) {
    transform(word.begin(), word.end(), word.begin(), ::tolower);

    vector<string> trigrams = Trigram::trigrams(word);
    fout << word << " " << trigrams.size();

    for (const string& sub: trigrams) {
      fout << " " << sub;
    }
    fout << endl;
  }
  fin.close();
  fout.close();
  return 0;
}
