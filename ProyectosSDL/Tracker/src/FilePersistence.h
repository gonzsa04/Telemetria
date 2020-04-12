#pragma once

#include "IPersistence.h"
#include "ConcurrentQueue.h"

class FilePersistence : public IPersistence
{
public:
	FilePersistence();
	~FilePersistence();

	void Send(const TrackerEvent* trackerEvent);

	/// <summary>
	/// Applies persistence to the saved tracker events
	/// </summary>
	void Flush();

private:

	ConcurrentQueue<const TrackerEvent*> _events;
	std::string _commonPath;
	std::string _filename;
};

