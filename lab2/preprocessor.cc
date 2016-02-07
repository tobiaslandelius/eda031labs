#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "trigram.h"

using namespace std;

int main() {
  ifstream fin("words");
  ofstream fout("words.txt");

  string word;
  while (getline(fin, word)) {
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
