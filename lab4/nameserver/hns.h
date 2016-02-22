#ifndef HNS_H
#define HNS_H

#include "nameserverinterface.h"
#include <vector>

using namespace std;

class HNS : public NameServerInterface 
{
public:
	HNS(int i);
	~HNS();
	void insert(const HostName&, const IPAddress&);
	bool remove(const HostName&);
	IPAddress lookup(const HostName&) const;
private:
	int myhash(const HostName& host) const;
	void resize();
	vector<vector<pair<HostName, IPAddress>>> nshmap;
	int tablesize;
	int nbrofpairs;
	hash<string> hasher;
};

#endif