#pragma once
#include "IPersistence.h"
#include "FilePersistence.h"

class Tracker
{
public:
	Tracker();
	~Tracker();

	void Init();

	/// <summary>
	/// Returns the singleton for the tracker
	/// </summary>
	static Tracker& GetInstance();

	/// <summary>
	/// Releases the instance created previously
	/// </summary>
	static void ResetInstance();

private:

	static Tracker* _instance;
	IPersistence* _persistence;
};

