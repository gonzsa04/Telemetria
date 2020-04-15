#pragma once

#include <list>
#include "TrackerEvents.h"
#include <string>
#include <thread>

struct ITrackerAsset;
class IPersistence;

class Tracker
{
public:
	Tracker();
	~Tracker();

	void Init(const std::list<ITrackerAsset*>& trackerAssetList, const std::list<IPersistence*>& persistenceList);
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

	TestEvent* createTestEvent();
	SceneEvent* createSceneEvent();
	LightPuzzleEvent* createLightPuzzleEvent();
	Connect4Event* createConnect4Event();
	ClickSceneEvent* createClickSceneEvent();
	ClickPuzzleEvent* createClickPuzzleEvent();
	SessionStartEvent* createSessionStartEvent();
	SessionEndEvent* createSessionEndEvent();

	inline std::string GetSessionID() { return id_; };

private:
	unsigned int listSize_;
	void generateSessionId();

	std::list<ITrackerAsset*> activeTrackers_;

	std::string id_;

	static Tracker* _instance;
	std::list<IPersistence*> _persistenceObjects; //active persistence types
};
