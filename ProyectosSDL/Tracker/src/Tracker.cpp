#include "Tracker.h"
#include "ITrackerAsset.h"
#include "TimeManager.h"
#include "IPersistence.h"
#include "FilePersistence.h"

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

void Tracker::trackEvent(TrackerEvent* trackerEvent)
{
	list<ITrackerAsset*>::iterator it = activeTrackers_.begin();
	while (it != activeTrackers_.end() && !(*it)->accept(trackerEvent)) { it++;	}
	if( it != activeTrackers_.end()){
		// Bucle por IPersistance haciendo send del event
		for (std::list<IPersistence*>::iterator ite = _persistenceObjects.begin(); ite != _persistenceObjects.end(); ++ite)
			(*ite)->Send(trackerEvent->toJson());
	}
}

TestEvent Tracker::createTestEvent()
{
	return TestEvent(TimeManager::GetSingleton()->getTimeSinceBeginning(), "kk");
}
