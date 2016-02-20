#include "mns.h"
#include <vector>
#include <algorithm>

using namespace std;

MNS::MNS() {}

MNS::~MNS() {}

void MNS::insert(const HostName& host, const IPAddress& ip) {
	nsmap.insert(make_pair(host, ip));
}

bool MNS::remove(const HostName& host) {
	return nsmap.erase(host) == 1;
}

IPAddress MNS::lookup(const HostName& host) const {
	return nsmap.find(host)->second;
}