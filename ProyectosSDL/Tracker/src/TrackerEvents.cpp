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
	//También se puede usar append y sstream, pero de momento lo dejo así que es lo mismo
	return result;
}

const string TestEvent::toJson() const
{
	//Aquí se meterían los atributos especificos del evento en el json
	string head = TrackerEvent::toJson();
	json j;
	//Elementos comunes del evento
	j["userID"] = id_;
	j["time"] = timeStamp_;
	string info = j.dump();
	string result = head + info;
	return result;
}

const string TestEvent::toCSV() const
{
	//Aquí irían los atributos específicos del evento en csv
	string head = TrackerEvent::toCSV();
	string timeStamp = to_string(timeStamp_);
	string result = head + ",user id: " + id_ + ",time: " + timeStamp;
	return result;
}

const string SceneEvent::toJson() const
{
	//Habría que mirar la legibilidad 
	string head = TrackerEvent::toJson();
	json j;
	j["Number scene"] = numScene_;
	j["Action"] = eventActions[action_];
	string info = j.dump();
	string result = head + info;
	return result;
}

const string SceneEvent::toCSV() const
{
	//Revisar
	string head = TrackerEvent::toCSV();
	string result = head + ",Number scene: " + to_string(numScene_) + ",Action: " + eventActions[action_];
	return result;
}

const string PuzzleEvent::toJson() const
{
	string head = TrackerEvent::toJson();
	json j;
	j["Number puzzle"] = numPuzzle_;
	j["Action"] = eventActions[action_];
	string info = j.dump();
	string result = head + info;
	return result;
}

const string PuzzleEvent::toCSV() const
{
	string head = TrackerEvent::toCSV();
	string result = head + ",Number puzzle: " + to_string(numPuzzle_) + ",Action: " + eventActions[action_];
	return result;
}

const string ClickEvent::toJson() const
{
	string head = TrackerEvent::toJson();
	json j;
	j["Number scene"] = numScene_;
	j["Position_X"] = pos_.first;
	j["Position_Y"] = pos_.second;
	string info = j.dump();
	string result = head + info;
	return result;
}

const string ClickEvent::toCSV() const
{
	string head = TrackerEvent::toCSV();
	string result = head + ",Number puzzle: " + to_string(numScene_) + ",Position_X: " + to_string(pos_.first) +
		",Position_Y: " + to_string(pos_.second);
	return result;
}
