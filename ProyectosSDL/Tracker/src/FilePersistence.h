#pragma once

#include "IPersistence.h"


class FilePersistence : public IPersistence
{
public:
	FilePersistence(const std::list<ISerializer*> serializers);
	virtual ~FilePersistence();

	/// <summary>
	/// Prepares protected flush operation if thread is free
	/// </summary>
	virtual void Flush();

protected:
	/// <summary>
	/// Applies persistence to the stored events in the queue
	/// </summary>
	virtual void protectedFlush();

private:

	std::string _commonPath; //directory path where the file is written 
};

