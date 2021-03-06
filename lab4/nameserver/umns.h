#ifndef UMNS_H
#define UMNS_H

#include "nameserverinterface.h"
#include <unordered_map>

using namespace std;

class UMNS : public NameServerInterface 
{
public:
	UMNS();
	~UMNS();
	void insert(const HostName&, const IPAddress&);
	bool remove(const HostName&);
	IPAddress lookup(const HostName&) const;
private:
	unordered_map<HostName, IPAddress> nsumap;
};

#endif