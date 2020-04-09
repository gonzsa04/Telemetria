#include "TrackerEvents.h"
#include "json.hpp"
using namespace nlohmann;

const string TrackerEvent::toJson() const
{
	json j;
	//Elementos comunes del evento
	j["userID"] = id_;
	j["time"] = timeStamp_;
	j["type"] = EventTypeToString(type_); // escribe el tipo de forma legible
	string result = j.dump();

	return result;
}

const string TrackerEvent::toCSV() const
{
	string timeStamp = to_string(timeStamp_);
	string type = EventTypeToString(type_); // escribe el tipo de forma legible
	string result = "user id: " + id_ + ",time: " + timeStamp + ",type: " + type;
	//Tambi�n se puede usar append y sstream, pero de momento lo dejo as� que es lo mismo
	return result;
}

const string TestEvent::toJson() const
{
	//Aqu� se meter�an los atributos especificos del evento en el json
	return TrackerEvent::toJson();
}

const string TestEvent::toCSV() const
{
	//Aqu� ir�an los atributos espec�ficos del evento en csv
	return TrackerEvent::toCSV();
}

const string SceneEvent::toJson() const
{
	//Aqu� se meter�an los atributos especificos del evento en el json
	return TrackerEvent::toJson();
}

const string SceneEvent::toCSV() const
{
	//Aqu� ir�an los atributos espec�ficos del evento en csv
	return TrackerEvent::toCSV();
}

const string PuzzleEvent::toJson() const
{
	//Aqu� se meter�an los atributos especificos del evento en el json
	return TrackerEvent::toJson();
}

const string PuzzleEvent::toCSV() const
{
	//Aqu� ir�an los atributos espec�ficos del evento en csv
	return TrackerEvent::toCSV();
}

const string ClickEvent::toJson() const
{
	//Aqu� se meter�an los atributos especificos del evento en el json
	return TrackerEvent::toJson();
}

const string ClickEvent::toCSV() const
{
	//Aqu� ir�an los atributos espec�ficos del evento en csv
	return TrackerEvent::toCSV();
}
