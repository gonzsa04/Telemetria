#pragma once

#include <list>
#include "TrackerEvents.h"

struct ITrackerAsset;
class IPersistence;

class Tracker
{
public:
	Tracker();
	~Tracker();

	void Init();
	void End();

	/// <summary>
	/// Returns the singleton for the tracker
	/// </summary>
	static Tracker& GetInstance();

	/// <summary>
	/// Releases the instance created previously
	/// </summary>
	static void ShutDownInstance();

	void trackEvent(const TrackerEvent* trackerEvent);

	TestEvent createTestEvent();
	SceneEvent createSceneEvent();
	LightPuzzleEvent createLightPuzzleEvent();
	Connect4Event createConnect4Event();
	ClickEvent createClickEvent();

private:
	std::list<ITrackerAsset*> activeTrackers_;

	static Tracker* _instance;
	std::list<IPersistence*> _persistenceObjects;
};
