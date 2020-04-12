#include "FilePersistence.h"
#include "Tracker.h"
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
		_path += ".json";

		std::ofstream file; 
		
		file.open(_path, std::ios::out | std::ios::app);

		while (!_events.empty()) //write pending events
		{
			std::string event = _events.pop().toJson();
			file << event << '\n';
		}

		file.close();
	}

	std::cout << "event written" << std::endl;

}

