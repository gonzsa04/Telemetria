#pragma once
#include "IPersistence.h"
#include <queue>

class ServerPersistence : public IPersistence
{
public:
	ServerPersistence(const std::list<ISerializer*> serializers, const std::string url);

	/// <summary>
	/// Prepares protected flush operation if thread is free
	/// </summary>
	virtual void Flush();
	virtual ~ServerPersistence();

protected:
	/// <summary>
	/// Applies persistence to the stored events in the queue sending them to a server
	/// </summary>
	virtual void protectedFlush();
	std::string _url;
};

