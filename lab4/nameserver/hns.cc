#include "hns.h"
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct CompareFirst {
	CompareFirst(HostName host) : host_(host) {}
	bool operator()(const std::pair<HostName, IPAddress>& pair) const {
		return host_ == pair.first;
	}
private:
	HostName host_;
};

HNS::HNS(int i) {
	nshmap.resize(i);
	tablesize = i;
}

HNS::~HNS() {}

void HNS::insert(const HostName& host, const IPAddress& ip) {
	int hashnbr = hasher(host) % tablesize;
	nshmap.at(hashnbr).push_back(make_pair(host, ip));

	double ratio = ++nbrofpairs / tablesize;
	if (ratio > 0.5) {
		resize();
	}
}

bool HNS::remove(const HostName& host) {
	int hashnbr = hasher(host) % tablesize;
	vector<pair<HostName, IPAddress>> v = nshmap.at(hashnbr);
	vector<pair<HostName, IPAddress>>::iterator it = find_if(v.begin(), v.end(), CompareFirst(host));

	if (it != v.end()) {
		nshmap.at(hashnbr).erase(it);
		--nbrofpairs;
		return true;
	}
	return false;
}

IPAddress HNS::lookup(const HostName& host) const {	
	int hashnbr = hasher(host) % tablesize;
	vector<pair<HostName, IPAddress>> v = nshmap.at(hashnbr);
	vector<pair<HostName, IPAddress>>::iterator it = find_if(v.begin(), v.end(), CompareFirst(host));

	if (it != v.end()) {
		return it->second;
	}
	return NON_EXISTING_ADDRESS;
}

void HNS::resize() {
	vector<vector<pair<HostName, IPAddress>>> temp = nshmap;
	tablesize *= 2;
	nshmap = vector<vector<pair<HostName, IPAddress>>>(tablesize, vector<pair<HostName, IPAddress>>());
	
	nbrofpairs = 0;
	for (vector<pair<HostName, IPAddress>> v : temp) {
		for (pair<HostName, IPAddress> p : v) {
			insert(p.first, p.second);
		}
	}	
}


