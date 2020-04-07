#pragma once
#include <stdio.h>
#include "json.hpp"
#include "TrackerEvent.h"
#include <string>
using namespace std;
class TestEvent: public TrackerEvent
{
public:
	TestEvent();
	virtual string toJson();
	~TestEvent();
private:
};

