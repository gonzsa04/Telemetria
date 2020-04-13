#pragma once
#include "TrackerEvents.h"

struct ITrackerAsset
{
public:
	ITrackerAsset() {}

	virtual inline const bool accept(const TrackerEvent* trackerEvent) const = 0;
};

struct TestTracker : public ITrackerAsset {
public:
	TestTracker() : ITrackerAsset() {}
	virtual inline const bool accept(const TrackerEvent* trackerEvent)const { return trackerEvent->getType() == TEST_EVENT; }
};

// tracker asset que acepta eventos relacionados con el objetivo "Dificultad del juego" (eventos de puzles)
struct DifficultyTracker : public ITrackerAsset {
public:
	DifficultyTracker() : ITrackerAsset() {}
	virtual inline const bool accept(const TrackerEvent* trackerEvent)const { return trackerEvent->getType() == LIGHTPUZZLE_EVENT || trackerEvent->getType() == CONNECT4_EVENT || trackerEvent->getType() == CLICK_EVENT_PUZZLE; }
};

// tracker asset que acepta eventos relacionados con el objetivo "Claridad del juego" (eventos de progreso de escenas y clicks)
struct ClarityTracker : public ITrackerAsset {
public:
	ClarityTracker() : ITrackerAsset() {}
	virtual inline const bool accept(const TrackerEvent* trackerEvent)const { return trackerEvent->getType() == SCENE_EVENT || trackerEvent->getType() == CLICK_EVENT_SCENE; }
};

// tracker asset que acepta eventos relacionados con la sesion actual
struct SessionTracker : public ITrackerAsset {
public:
	SessionTracker() : ITrackerAsset() {}
	virtual inline const bool accept(const TrackerEvent* trackerEvent)const { return trackerEvent->getType() == SESSION_START_EVENT || trackerEvent->getType() == SESSION_END_EVENT; }
};
