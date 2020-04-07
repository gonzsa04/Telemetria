#include "FilePersistence.h"
#include <Windows.h>
#include <iostream>
#include <fstream>


FilePersistence::FilePersistence()
{
}


FilePersistence::~FilePersistence()
{
}

void FilePersistence::Send(std::string str)
{
	std::string path;
	std::string filename = "userID.json";
	path = GetWorkingDirectory();
	path = path + "\logs";

	std::ofstream i(path); //file
	//json j;
	//writes serialized file

	i.close(); 

}

std::string FilePersistence::GetWorkingDirectory()
{
	char buf[256];
	GetCurrentDirectoryA(256, buf);
	return std::string(buf) + '\\';
}

