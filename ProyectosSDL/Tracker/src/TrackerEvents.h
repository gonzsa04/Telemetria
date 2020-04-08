#pragma once
#include <string>
#include <sstream>
using namespace std;

enum EventType	{ TEST_EVENT };

struct TrackerEvent
{
protected:
	double timeStamp_;
	string id_;
	EventType type_;

public:
	TrackerEvent(double timeStamp, string id, EventType type) : timeStamp_(timeStamp), id_(id), type_(type) {}

	virtual string toJson();	
	virtual string toCSV();

	inline const EventType getType() const { return type_; }
};

struct TestEvent : public TrackerEvent {
public:
	TestEvent(double timeStamp, string id) : TrackerEvent(timeStamp, id, TEST_EVENT) {}

	virtual string toJson();
	virtual string toCSV();
};

