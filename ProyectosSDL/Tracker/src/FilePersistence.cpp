#include "FilePersistence.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <direct.h>
#include <stdlib.h>

FilePersistence::FilePersistence()
{
}


FilePersistence::~FilePersistence()
{
}

void FilePersistence::Send(std::string str)
{
	_events.push(str);
	std::cout << "event sent" << std::endl;
}

void FilePersistence::Flush()
{
	if (!_events.empty())
	{
		std::string path = _SOLUTIONDIR;
		path += "\logs\\";
		_mkdir(path.c_str()); //creates directory if it doesn't exist

		std::string filename = "\\userID.json";
		path += filename;

		std::ofstream file; 
		
		file.open(path, std::ios::out | std::ios::app);

		while (!_events.empty()) //write pending events
		{
			std::string event = _events.pop();
			file << event << '\n';
		}

		file.close();
	}
}

