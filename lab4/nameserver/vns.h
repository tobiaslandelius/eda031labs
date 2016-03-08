#ifndef VNS_H
#define VNS_H

#include "nameserverinterface.h"
#include <vector>

using namespace std;

class VNS : public NameServerInterface 
{
public:
	VNS();
	~VNS();
	void insert(const HostName&, const IPAddress&);
	bool remove(const HostName&);
	IPAddress lookup(const HostName&) const;
private:
	vector<pair<HostName, IPAddress>> nsvector;
};
#endif