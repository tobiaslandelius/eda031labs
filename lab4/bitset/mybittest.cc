#include <iostream>
#include <cstddef> /* size_t */
#include <limits>  /* numeric_limits */
#include "simplebitset.h"

using namespace std;

void print(const SimpleBitset& bs) {
	for (size_t i = 0; i != bs.size(); ++i) {
		cout << bs.get(i);
	}
	cout << endl;
}

int main() {
	SimpleBitset bs;
	print(bs);

	unsigned long mylong = 0;
	mylong |= (1L << 5);
	cout << mylong << endl;
	unsigned long lo1 = 6;
	unsigned long lo2 = 2;
	cout << "--> " << (lo1 & lo2) << endl;

	print(bs);
	cout << endl;
	
	
}
