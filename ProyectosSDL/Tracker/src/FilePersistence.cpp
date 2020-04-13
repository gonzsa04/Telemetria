#include "FilePersistence.h"
#include "Tracker.h"
#include "JsonSerializer.h"
#include "CSVSerializer.h"
#include <iostream>
#include <fstream>

#include <stdio.h>
#include <direct.h>
#include <stdlib.h>


FilePersistence::FilePersistence()
{
	//Gets files' path & creates directory if it doesn't exist
	_commonPath = _SOLUTIONDIR;
	_commonPath += "\logs\\";
	_mkdir(_commonPath.c_str());

	//Common path file name
	_commonPath.append("\\" + Tracker::GetInstance().GetSessionID() + ".");

	_serializeObjects.push_back(new JsonSerializer());
	_serializeObjects.push_back(new CSVSerializer());

}


FilePersistence::~FilePersistence()
{
}

void FilePersistence::Send(const TrackerEvent* trackerEvent) // TO DO: recibir const TrackEvent event
{
	_events.push(trackerEvent);
	std::cout << "event sent" << std::endl;
}

void FilePersistence::Flush()
{
	if (!_events.empty())
	{
		std::ofstream file; 
		
		while (!_events.empty()) //write pending events
		{
			const TrackerEvent* tEvent = _events.pop();

			for (std::list<ISerializer*>::iterator it = _serializeObjects.begin(); it != _serializeObjects.end(); ++it)
			{
				std::string path;
				path.append(_commonPath + (*it)->Format());

				file.open(path, std::ios::out | std::ios::app);

				std::string event = (*it)->Serialize(tEvent);
				file << event << '\n';

				file.close();

			}	
		}
	}

	std::cout << "event written" << std::endl;

}

