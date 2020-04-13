#pragma once

#include "IPersistence.h"

class FilePersistence : public IPersistence
{
public:
	FilePersistence();
	~FilePersistence();

	/// <summary>
	/// Stores the event in the queue
	/// </summary>
	void Send(const TrackerEvent* trackerEvent);

	/// <summary>
	/// Applies persistence to the stored events in the queue
	/// </summary>
	void Flush();

private:

	std::string _commonPath; //directory path where the file is written 
};

