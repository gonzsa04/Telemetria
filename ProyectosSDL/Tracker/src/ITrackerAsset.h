#pragma once
#include "TrackerEvents.h"

struct ITrackerAsset
{
private:
	EventType acceptedType_;

public:
	ITrackerAsset(EventType type) : acceptedType_(type) {}

	inline const bool accept(TrackerEvent* trackerEvent) const { return acceptedType_ == trackerEvent->getType(); }
};

struct TestTracker : public ITrackerAsset {
public:
	TestTracker() : ITrackerAsset(TEST_EVENT) {}
};