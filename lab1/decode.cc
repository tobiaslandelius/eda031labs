#include <iostream>
#include <fstream>
#include "coding.h"
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {
	std::ifstream fin(argv[1]);
	std::ofstream fout(argv[1] + std::string(".dec"));
	
	char ch;
	unsigned char uch;
	fin.get(ch);
	while (!fin.eof()) {
		uch = static_cast<unsigned char>(ch);
		uch = Coding::decode(uch);
		ch = static_cast<char>(uch);
		fout.put(ch);
		fin.get(ch);
	}
	
	fin.close();
	fout.close();
	return 0;
}
