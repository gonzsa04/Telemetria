#include "Tracker.h"
#include "ITrackerAsset.h"
#include "TimeManager.h"
#include "IPersistence.h"
#include "FilePersistence.h"
#include "sha256.h"
#include <ctime>
#include <iostream>

// Static variable for the singleton
Tracker * Tracker::_instance = nullptr;

Tracker::Tracker()
{
}

Tracker::~Tracker()
{
	while (!_persistenceObjects.empty())
	{
		_persistenceObjects.pop_front();
	}
}

void Tracker::Init()
{
	activeTrackers_.push_back(new TestTracker());
	activeTrackers_.push_back(new DifficultyTracker());
	activeTrackers_.push_back(new ClarityTracker());

	generateSessionId();

	_persistenceObjects.push_front(new FilePersistence());
}

void Tracker::End()
{
	for (ITrackerAsset* trackerAsset : activeTrackers_) {
		delete trackerAsset; trackerAsset = nullptr;
	}
	activeTrackers_.clear();
}

Tracker & Tracker::GetInstance()
{
	// If there wasn't an instance created, create a new one
	if (Tracker::_instance == nullptr)
		Tracker::_instance = new Tracker();

	return *Tracker::_instance;
}

void Tracker::ShutDownInstance()
{
	if (_instance != nullptr) {
		delete Tracker::_instance;
		Tracker::_instance = nullptr;
	}
}

void Tracker::trackEvent(const TrackerEvent* trackerEvent)
{
	list<ITrackerAsset*>::iterator it = activeTrackers_.begin();
	while (it != activeTrackers_.end() && !(*it)->accept(trackerEvent)) { it++;	}
	if( it != activeTrackers_.end()){
		for (std::list<IPersistence*>::iterator ite = _persistenceObjects.begin(); ite != _persistenceObjects.end(); ++ite)
			(*ite)->Send(trackerEvent); // TO DO: ipersistance que reciba objetos evento en send (por dentro llamara al serialize de cada uno en flush)
	}
}

SessionStartEvent Tracker::createSessionStartEvent()
{
	return SessionStartEvent(TimeManager::GetSingleton()->getTimeSinceBeginning(), id_);
}

SessionEndEvent Tracker::createSessionEndEvent()
{
	return SessionEndEvent(TimeManager::GetSingleton()->getTimeSinceBeginning(), id_);
}

TestEvent Tracker::createTestEvent()
{
	return TestEvent(TimeManager::GetSingleton()->getTimeSinceBeginning(), id_);
}

SceneEvent Tracker::createSceneEvent()
{
	return SceneEvent(TimeManager::GetSingleton()->getTimeSinceBeginning(), id_);
}

LightPuzzleEvent Tracker::createLightPuzzleEvent()
{
	return LightPuzzleEvent(TimeManager::GetSingleton()->getTimeSinceBeginning(), id_);
}

Connect4Event Tracker::createConnect4Event()
{
	return Connect4Event(TimeManager::GetSingleton()->getTimeSinceBeginning(), id_);
}

ClickSceneEvent Tracker::createClickSceneEvent()
{
	return ClickSceneEvent(TimeManager::GetSingleton()->getTimeSinceBeginning(), id_);
}

ClickPuzzleEvent Tracker::createClickPuzzleEvent()
{
	return ClickPuzzleEvent(TimeManager::GetSingleton()->getTimeSinceBeginning(), id_);
}

void Tracker::generateSessionId()
{
	time_t now = time(0);

	// convert now to string form
	char* dt = ctime(&now);

	id_ = sha256(dt);

	std::cout << id_ << " " << dt << std::endl;
}
