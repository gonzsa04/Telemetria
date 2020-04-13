#pragma once
#include "IPersistence.h"

class ServerPersistence : public IPersistence
{
public:
	ServerPersistence();

	/// <summary>
	/// Applies persistence to the saved tracker events
	/// </summary>
	void Send(const TrackerEvent* trackerEvent);

	/// <summary>
	/// Applies persistence to the stored events in the queue
	/// </summary>
	void Flush();

	~ServerPersistence();
};

