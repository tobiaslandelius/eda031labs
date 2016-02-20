#include "mns.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

MNS::MNS() {}

MNS::~MNS() {}

void MNS::insert(const HostName& host, const IPAddress& ip) {
	nsmap.insert(make_pair(host, ip));
}

bool MNS::remove(const HostName& host) {
	return nsmap.erase(host);
}

IPAddress MNS::lookup(const HostName& host) const {
	map<HostName, IPAddress>::const_iterator it = nsmap.find(host);
	
	if (it != nsmap.end()) {
		return it->second;
	}
	return NON_EXISTING_ADDRESS;
}