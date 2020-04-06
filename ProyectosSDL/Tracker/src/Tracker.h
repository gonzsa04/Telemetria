#pragma once
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


};

