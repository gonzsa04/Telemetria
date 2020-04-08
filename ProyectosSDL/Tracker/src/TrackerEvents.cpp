#include "TrackerEvents.h"
#include "json.hpp"
using namespace nlohmann;

string TrackerEvent::toJson()
{
	json j;
	//Elementos comunes del evento
	j["userID"] = id_;
	j["time"] = timeStamp_;
	j["type"] = type_;
	// TO DO: falta tipo de evento
	string result = j.dump();

	return result;
}

string TrackerEvent::toCSV()
{
	string timeStamp = to_string(timeStamp_);
	string type = to_string(type_); 
	string result = "user id: " + id_ + ",time: " + timeStamp + ",type: " + type;
	//También se puede usar append y sstream, pero de momento lo dejo así que es lo mismo
	return result;
}

string TestEvent::toJson()
{
	//Aquí se meterían los atributos especificos del evento en el json
	return TrackerEvent::toJson();
}

string TestEvent::toCSV()
{
	//Aquí irían los atributos específicos del evento en csv
	return TrackerEvent::toCSV();
}
