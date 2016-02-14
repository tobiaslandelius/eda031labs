#include <iostream>
#include <string>
#include "tagremover.h"
#include <regex>

using namespace std;

string tagsremoved;

Tagremover::Tagremover(istream &is) {
	string nextline, allinput;
	regex tags("<[^>]*> | (&.*;)");

	while (getline(is, nextline)) {
		allinput += nextline+ "\n";
	}

	tagsremoved = regex_replace(allinput, tags, "");
}

void Tagremover::print(ostream &os) {
	os << tagsremoved;
}