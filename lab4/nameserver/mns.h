#ifndef MNS_H
#define MNS_H

#include "nameserverinterface.h"
#include <vector>
#include <map>

using namespace std;

class MNS : public NameServerInterface 
{
public:
	MNS();
	~MNS();
	void insert(const HostName&, const IPAddress&);
	bool remove(const HostName&);
	IPAddress lookup(const HostName&) const;
private:
	map<HostName, IPAddress> nsmap;
};

#endif