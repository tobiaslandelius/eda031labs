#include <iostream>
#include "coding.h"

static unsigned char Coding::encode(unsigned char c) {
	return --c;	
}

static unsigned char Coding::decode(unsigned char c) {
	return ++c;	
}