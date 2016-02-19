#ifndef UMNS_H
#define UMNS_H

#include "nameserverinterface.h"
#include <vector>

using namespace std;

class UMNS : public NameServerInterface 
{
public:
	UMNS();
	~UMNS();
	void insert(const HostName&, const IPAddress&);
	bool remove(const HostName&);
	IPAddress lookup(const HostName&) const;

};

#endif