#pragma once

#include "IPersistence.h"

class FilePersistence : public IPersistence
{
public:
	FilePersistence();
	~FilePersistence();

	virtual void Send(std::string str);

private:

	/// <summary>
	/// Returns the working directory of the project
	/// </summary>
	std::string GetWorkingDirectory(); 
};

