#include <string>
#include <vector>
#include "word.h"
#include "trigram.h"

using namespace std;

Word::Word(const string& w, const vector<string>& t) {
	word = w;
	trigrams = t;
}

string Word::get_word() const {
	return word;
}

// Not done!
unsigned int Word::get_matches(const vector<string>& t) const {
	vector<string> trigrams = trigrams(t);
	return trigrams.size();
}
