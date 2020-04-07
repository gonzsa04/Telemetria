#pragma once
#include <cstdio>
#include <string>
#include "TrackerEvents.h"
using namespace std;

//Serializer Interface 

class ISerializer {
public:
	//int se sustituirá por el tipo evento
	virtual string Serialize(TestEvent event) = 0;
};
