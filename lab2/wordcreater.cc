#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"
#include <cctype>
#include <clocale>
#include <vector>

using namespace std;

int main() {
	string word;
	int read_words = 0;
	
	ifstream ifs ("words");
	ofstream ofs ("words.txt");

	if (ifs.is_open()) {
		while (ifs >> word) {
			int length = word.length();
			
			// Word to lower case
			for (basic_string<char>::iterator p = word.begin();
    			p != word.end(); ++p) {
      			*p = tolower(*p);
   			}

			if (length > 2) {
				vector<string> triagrams(length - 2);

				// Split into trigrams
				for (int i = 0; i < length - 2; i++) {
					triagrams[i] = word.substr(i, 3);
				}

				// Sort
				sort(triagrams.begin(), triagrams.end());

				// Write
				ofs << word << " " << length;
				for (int i = 0; i < length - 2; i++) {
					ofs << " " << triagrams[i];
				}
				ofs << endl;
 				read_words++;
			}
		}
		ifs.close();
		ofs.close();
	} else {
		cout << "Unable to open file";
	}
	cout << "Successfully read and wrote " << read_words << " words!" << endl;
}