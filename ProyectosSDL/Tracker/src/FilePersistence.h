#pragma once

#include "IPersistence.h"
#include "ConcurrentQueue.h"

class FilePersistence : public IPersistence
{
public:
	FilePersistence();
	~FilePersistence();

	virtual void Send(const std::string str);

	/// <summary>
	/// Applies persistence to the saved tracker events
	/// </summary>
	virtual void Flush();

private:

	ConcurrentQueue<std::string> _events;

};

