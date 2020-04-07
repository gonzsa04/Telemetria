#pragma once

#include <string>

class IPersistence
{
public:
	IPersistence() {};
	virtual ~IPersistence() {};

	virtual void Send(std::string str) = 0;
};

