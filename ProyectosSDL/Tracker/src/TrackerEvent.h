#pragma once
#include <string>
#include <stdio.h>
#include "json.hpp"
using namespace nlohmann;
using namespace std;

class TrackerEvent
{
public:
	TrackerEvent();
	virtual string toJson();
	string getuserId() {
		return userId_;
	}
	string gettimeStamp() {
		return timeStamp_;
	}
	~TrackerEvent();
private:
	string userId_;
	string timeStamp_;

};

