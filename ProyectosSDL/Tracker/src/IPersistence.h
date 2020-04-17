#pragma once
#include "TrackerEvents.h"
#include "ISerializer.h"
#include <string>
#include <list>
#include "ConcurrentQueue.h"
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
		const TrackerEvent* clone = trackerEvent->clone(); //pushes the pointer's clone
		_eventQueue.push(clone);

		if (_eventQueue.size() >= MAX_EVENTS)
		{
			Flush();
		}
		//std::cout << "PUSH" << std::endl;
		//std::cout << "event sent" << std::endl;
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

	inline virtual void finalFlush() {
		while (!_eventQueue.empty()) {			
			Flush();
		}
	};

protected:
	// thread
	std::thread thread_;

	std::list<ISerializer*> _serializeObjects; //list of active formats
	
	ConcurrentQueue<const TrackerEvent*> _eventQueue; //stored events pending flush operation
	
	const int MAX_EVENTS = 5; //max queue storage

	// specific flush
	virtual void protectedFlush() = 0;

	bool threadFinished_ = true;
	std::mutex mutex_;
};

