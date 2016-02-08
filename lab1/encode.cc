#include <iostream>
#include <fstream>
#include "coding.h"
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {
  std::ifstream fin(argv[1]);
  std::ofstream fout(argv[1] + std::string(".enc"));

  char ch;
  unsigned uch;
  fin.get(ch);
  while (!fin.eof()) {
    uch = static_cast<unsigned char>(ch);
    uch = Coding::encode(uch);
    fout.put(uch);
    fin.get(ch);
  }

  fin.close();
  fout.close();
  return 0;
}
