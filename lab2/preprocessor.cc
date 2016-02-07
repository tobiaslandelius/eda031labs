#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "trigram.h"

using namespace std;

int main() {
  ifstream fin("words");
  ofstream fout("word.txt");

  string word;
  while (getline(fin, word)) {
    fout << word;
    fout << " ";
    fout << (word.length() - 2);
    fout << " ";
    for (string sub : Trigram::trigrams(word)) {
      fout << sub;
    }
    fout << "\n";
  }
  fin.close();
  fout.close();
}
