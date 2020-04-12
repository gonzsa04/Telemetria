#pragma once

#include "IPersistence.h"
#include "ConcurrentQueue.h"

class FilePersistence : public IPersistence
{
public:
	FilePersistence();
	~FilePersistence();

	virtual void Send(const TrackerEvent* trackerEvent);

	/// <summary>
	/// Applies persistence to the saved tracker events
	/// </summary>
	virtual void Flush();

private:

	ConcurrentQueue<TrackerEvent> _events;
	std::string _path;
	std::string _filename;

};

