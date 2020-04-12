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
	_path = _SOLUTIONDIR;
	_path += "\logs\\";
	_mkdir(_path.c_str());

	//Common file name
	_path.append("\\" + Tracker::GetInstance().GetSessionID());
	std::cout << "PATH: " << _path << std::endl;

	_serializeObjects.push_back(new CSVSerializer());
}


FilePersistence::~FilePersistence()
{
}

void FilePersistence::Send(const TrackerEvent* trackerEvent) // TO DO: recibir const TrackEvent event
{
	_events.push(*trackerEvent);
	std::cout << "event sent" << std::endl;
}

void FilePersistence::Flush()
{
	if (!_events.empty())
	{
	
		std::string path;
		path.append(_path + _serializeObjects.front()->Format());

		std::ofstream file; 
		
		file.open(path, std::ios::out | std::ios::app);

		while (!_events.empty()) //write pending events
		{
			TrackerEvent tEvent = _events.pop();
			std::string event = _serializeObjects.front()->Serialize(&tEvent);//_events.pop().toJson();
			file << event << '\n';
		}

		file.close();
	}

	std::cout << "event written" << std::endl;

}

