#pragma once
#include "IPersistence.h"

class ServerPersistence : public IPersistence
{
public:
	ServerPersistence();

	virtual void Flush();
	virtual ~ServerPersistence();

protected:
	/// <summary>
	/// Applies persistence to the stored events in the queue sending them to a server
	/// </summary>
	virtual void protectedFlush();

	/// <summary>
	/// A tracker event is stored in the queue
	/// </summary>
	virtual void protectedSend(const TrackerEvent* trackerEvent);

};

