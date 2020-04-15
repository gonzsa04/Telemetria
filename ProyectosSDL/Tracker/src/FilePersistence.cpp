#include "FilePersistence.h"
#include "Tracker.h"
#include "JsonSerializer.h"
#include "CSVSerializer.h"
#include <iostream>
#include <fstream>

#include <stdio.h>
#include <direct.h>
#include <stdlib.h>
#include <Windows.h>


FilePersistence::FilePersistence()
{
	//Gets files' path & creates directory if it doesn't exist
	_commonPath = _SOLUTIONDIR;
	_commonPath += "\logs\\";
	_mkdir(_commonPath.c_str());

	//Common path file name
	_commonPath.append("\\" + Tracker::GetInstance().GetSessionID() + ".");

	//Active formats
	_serializeObjects.push_back(new JsonSerializer());
	_serializeObjects.push_back(new CSVSerializer());
}

FilePersistence::~FilePersistence()
{
	while (!_serializeObjects.empty())
	{
		_serializeObjects.pop_back();
	}
}

/// Stores the event in the queue
void FilePersistence::protectedSend(const TrackerEvent* trackerEvent) 
{
	_events.push(trackerEvent);
	if (_events.size() >= MAX_EVENTS) 
		Flush();
	std::cout << "event sent" << std::endl;
}

void FilePersistence::Flush()
{
	if (thread_.joinable())
		thread_.join();

	thread_ = std::thread(&FilePersistence::protectedFlush, this);
}

/// Applies persistence to the stored events in the queue
void FilePersistence::protectedFlush()
{
	mutex_.lock();
	std::cout << "flushing" << std::endl;

	if (!_events.empty())
	{
		std::ofstream file; 
		
		while (!_events.empty()) //write pending events
		{
			const TrackerEvent* tEvent = _events.pop();

			//serializes the event in all availlable formats
			for (std::list<ISerializer*>::iterator it = _serializeObjects.begin(); it != _serializeObjects.end(); ++it)
			{
				std::string path;
				path.append(_commonPath + (*it)->Format());

				file.open(path, std::ios::out | std::ios::app);

				std::string event = (*it)->Serialize(tEvent); 
				file << event << '\n'; //writes the event to the file

				file.close();
			}
			// delete tEvent;
		}
	}

	mutex_.unlock();
}

