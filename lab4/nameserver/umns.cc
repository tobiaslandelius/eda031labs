#include "umns.h"
#include <vector>
#include <algorithm>

using namespace std;

UMNS::UMNS() {}

UMNS::~UMNS() {}

void UMNS::insert(const HostName& host, const IPAddress& ip) {
	nsumap.insert(make_pair(host, ip));
}

bool UMNS::remove(const HostName& host) {
	return nsumap.erase(host);
}

IPAddress UMNS::lookup(const HostName& host) const {
	unordered_map<HostName, IPAddress>::const_iterator it = nsumap.find(host);
	
	if (it != nsumap.end()) {
		return it->second;
	}
	return NON_EXISTING_ADDRESS;
}