#include <iostream>
#include "prime.h"

using namespace std;

int main() {
	Prime p(100000);

	cout << "0 - 200" << endl;
	p.print_200();

	cout << endl << "largest below 100 000" << endl;
	p.print_largest();
}
