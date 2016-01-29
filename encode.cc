#include <iostream>
#include <fstream>
#include "coding.h"
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {
	std::ifstream fin(argv[0]);
	std::ofstream fout(argv[0] + std::string(".enc"));
	
	char ch;
	unsigned uch;
	
	while (fin.good()) {
		fin.get(ch);
		uch = static_cast<unsigned char>(ch);
		uch = Coding::encode(uch);
		fout.put(uch);
	}
	return 0;
}
