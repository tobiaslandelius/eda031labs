#include <string>
#include <fstream>
#include <iostream>
#include "dictionary.h"
#include "word.h"
#include "trigram.h"
#include <unordered_set>

using namespace std;

int main() {
  Dictionary *dict = new Dictionary();
  vector<string> v1 = {"asd", "bbb", "qwe", "tla"};
  vector<string> v2 = {"aaa", "abc", "bbb", "dsa", "ggg", "qwe", "tla"};
  Word *word1 = new Word("asdbbbtlaqwe", v1);

  cout << "Found " << word1->get_matches(v2) << " matches." << endl;

  delete dict;
  delete word1;
}