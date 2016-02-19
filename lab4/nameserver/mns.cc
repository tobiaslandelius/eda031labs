#include "mns.h"
#include <vector>
#include <algorithm>

using namespace std;

struct CompareFirst {
	CompareFirst(HostName host) : host_(host) {}
	bool operator()(const std::pair<HostName, IPAddress>& pair) const {
		return host_ == pair.first;
	}
private:
	HostName host_;
};

MNS::MNS() {}

MNS::~MNS() {}
void MNS::insert(const HostName& host, const IPAddress& ip) {}

bool MNS::remove(const HostName& host) {
	return false;
}

IPAddress MNS::lookup(const HostName& host) const {
	return NON_EXISTING_ADDRESS;
}


