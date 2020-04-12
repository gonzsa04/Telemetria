#pragma once
#include "TrackerEvents.h"
#include "ISerializer.h"
#include <string>
#include <list>

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
	/// Applies persistence to the saved tracker events
	/// </summary>
	virtual void Flush() = 0;

protected:
	std::list<ISerializer*> _serializeObjects;
};

