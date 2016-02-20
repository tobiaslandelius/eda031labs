#include "vns.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct CompareFirst {
	CompareFirst(HostName host) : host_(host) {}
	bool operator()(const std::pair<HostName, IPAddress>& pair) const {
		return host_ == pair.first;
	}
private:
	HostName host_;
};

VNS::VNS() {}

VNS::~VNS() {}

void VNS::insert(const HostName& host, const IPAddress& ip) {
	nsvector.push_back(make_pair(host, ip));
	cout << "insert made" << endl;
}

bool VNS::remove(const HostName& host) {
	vector<pair<HostName, IPAddress>>::iterator it = 
		find_if(nsvector.begin(), nsvector.end(), CompareFirst(host));

	if (it != nsvector.end()) {
		nsvector.erase(it);
		return true;
	}
	return false;
}

IPAddress VNS::lookup(const HostName& host) const {
	vector<pair<HostName, IPAddress>>::const_iterator it = 
		find_if(nsvector.begin(), nsvector.end(), CompareFirst(host));

	if (it != nsvector.end()) {
		return it->second;
	}
	return NON_EXISTING_ADDRESS;
}