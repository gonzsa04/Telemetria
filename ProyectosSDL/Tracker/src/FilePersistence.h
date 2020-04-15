#pragma once

#include "IPersistence.h"

class FilePersistence : public IPersistence
{
public:
	FilePersistence();
	virtual ~FilePersistence();

	virtual void Flush();

protected:
	/// <summary>
	/// Applies persistence to the stored events in the queue
	/// </summary>
	virtual void protectedFlush();

	/// <summary>
	/// Stores the event in the queue
	/// </summary>
	virtual void protectedSend(const TrackerEvent* trackerEvent);
private:

	std::string _commonPath; //directory path where the file is written 
};

