#pragma once
#include "IPersistence.h"

class ServerPersistence : public IPersistence
{
public:
	ServerPersistence();

	/// <summary>
	/// A tracker event is stored in the queue
	/// </summary>
	void Send(const TrackerEvent* trackerEvent);

	/// <summary>
	/// Applies persistence to the stored events in the queue sending them to a server
	/// </summary>
	void Flush();

	~ServerPersistence();
};

