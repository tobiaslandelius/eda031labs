#include <string>
#include <iostream>
#include "prime.h"
#include <math.h>

using namespace std;

Prime::Prime(int n) {
	s = string(n, 'P');

	s[0] = 'C';
	s[1] = 'C';

	for (int i = 2; i < sqrt(n); i++) {
		if (s.at(i) == 'P') {
			for (int j = i*i; j < n; j += i) {
				s[j] = 'C';
			}
		}
	}
}

void Prime::print_200() {
	int count = 15; // Print 15 each line

	for (int i = 0; i <= 200; i++) {
		if (s[i] == 'P') {
			cout << i << " " ;
			if (--count == 0) {
				cout << endl;
				count = 15;
			}
		}
	}
	cout << endl;
}

void Prime::print_largest() {
	cout << s.find_last_of('P') << endl;
}