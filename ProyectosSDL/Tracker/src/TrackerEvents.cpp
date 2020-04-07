#include "TrackerEvents.h"
#include "json.hpp"
using namespace nlohmann;

string TrackerEvent::toJson()
{
	json j;
	//Elementos comunes del evento
	j["userID"] = id_;
	j["time"] = timeStamp_;
	// TO DO: falta tipo de evento
	string result = j.dump();

	return result;
}

string TrackerEvent::toCSV()
{
	return string();
}

string TestEvent::toJson()
{
	//Aquí se meterían los atributos especificos del evento en el json
	return TrackerEvent::toJson();
}

string TestEvent::toCSV()
{
	return TrackerEvent::toCSV();
}
