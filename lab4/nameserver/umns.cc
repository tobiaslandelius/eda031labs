#include "umns.h"
#include <vector>
#include <algorithm>

using namespace std;

UMNS::UMNS() {}

UMNS::~UMNS() {}

void UMNS::insert(const HostName& host, const IPAddress& ip) {
}

bool UMNS::remove(const HostName& host) {
	return false;
}

IPAddress UMNS::lookup(const HostName& host) const {
	return NON_EXISTING_ADDRESS;
}


