#include <iostream>
#include <fstream>
#include "coding.h"
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {
	std::ifstream fin(argv[0]);
	std::ofstream fout(argv[0] + std::string(".dec"));
	
	char ch;
	unsigned char uch;
	
	while (fin.good()) {
		fin.get(ch);
		uch = static_cast<unsigned char>(ch);
		uch = Coding::decode(uch);
		ch = static_cast<char>(uch);
		fout.put(ch);
	}
	return 0;
}
