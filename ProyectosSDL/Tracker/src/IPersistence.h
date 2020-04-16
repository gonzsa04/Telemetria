#pragma once
#include "TrackerEvents.h"
#include "ISerializer.h"
#include <string>
#include <list>
#include "ConcurrentQueue.h"
#include <queue>
#include <thread>

class IPersistence
{
public:
	IPersistence() {};
	virtual ~IPersistence() {};

	/// <summary>
	/// A tracker event is stored in the queue
	/// </summary>
	inline void Send(const TrackerEvent* trackerEvent) 
	{
		// protecting the shared variable
		mutex_.lock();
		protectedSend(trackerEvent);
		mutex_.unlock();
	};

	/// <summary>
	/// Creates the thread. It needs to be redefined in every child.
	/// </summary>
	virtual void Flush() = 0;

	inline void release() 
	{
		if (thread_.joinable()) {
			thread_.join();
		}
	};

protected:
	// thread
	std::thread thread_;
	std::mutex mutex_;

	std::list<ISerializer*> _serializeObjects; //list of active formats
	
	std::queue<const TrackerEvent*> _events; //stored events pending flush operation

	std::list<const TrackerEvent*> _flushEvents; 
	
	const int MAX_EVENTS = 3; //max queue storage

	// specific flush
	virtual void protectedFlush() = 0;

	// protected method, used in Send()
	virtual void protectedSend(const TrackerEvent* trackerEvent) = 0;
};

