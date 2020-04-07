#pragma once
#include <cstdio>
#include <string>

using namespace std;

//Serializer Interface 

class ISerializer {
public:
	//int se sustituirá por el tipo evento
	virtual string Serialize(int event) = 0;
};
