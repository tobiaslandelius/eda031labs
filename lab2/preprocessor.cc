#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	std::ifstream fin("words");
	std::ofstream fout("word.txt");
	
	std::string word;
	int i=0;
	while (getline(fin, word)) {
		++i;
	}
	std::cout << i << std::endl;
	fin.close();
	fout.close();
	return 0;
}