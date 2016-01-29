#include <iostream>
#include "coding.h"

using namespace std;

int main() {
	char ch;
	std::ifstream infile("file");
	std::ifstream outfile("file.enc");
	
	while (infile.get(ch)) {
		outfile.put(Coding::encode(ch));
	}
}
