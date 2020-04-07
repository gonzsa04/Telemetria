#pragma once
#include <cstdio>
#include <string>
#include "TestEvent.h"
using namespace std;

//Serializer Interface 

class ISerializer {
public:
	//int se sustituir� por el tipo evento
	virtual string Serialize(TestEvent event) = 0;
};
