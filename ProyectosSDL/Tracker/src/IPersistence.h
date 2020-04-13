#pragma once
#include "TrackerEvents.h"
#include "ISerializer.h"
#include <string>
#include <list>
#include "ConcurrentQueue.h"

class IPersistence
{
public:
	IPersistence() {};
	virtual ~IPersistence() {};

	/// <summary>
	/// A tracker event is stored in the queue
	/// </summary>
	virtual void Send(const TrackerEvent* trackerEvent) = 0;

	/// <summary>
	/// Applies persistence to the queued tracker events
	/// </summary>
	virtual void Flush() = 0;

protected:
	std::list<ISerializer*> _serializeObjects; //list of active formats
	ConcurrentQueue<const TrackerEvent*> _events; //stored events pending flush operation
	const int MAX_EVENTS = 20; //max queue storage
};

