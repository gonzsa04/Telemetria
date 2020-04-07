#include "Tracker.h"


// Static variable for the singleton
Tracker * Tracker::_instance = nullptr;

Tracker::Tracker()
{
}


Tracker::~Tracker()
{
}


void Tracker::Init()
{
	_persistence = new FilePersistence();
	_persistence->Send("test");
}

Tracker & Tracker::GetInstance()
{
	// If there wasn't an instance created, create a new one
	if (Tracker::_instance == nullptr)
		Tracker::_instance = new Tracker();

	return *Tracker::_instance;
}


void Tracker::ResetInstance()
{
	if (_instance != nullptr) {
		delete Tracker::_instance;
		Tracker::_instance = nullptr;
	}
}