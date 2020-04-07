#include "TrackerEvent.h"



TrackerEvent::TrackerEvent()
{
	//Valores que se obtendrán del juego
	timeStamp_ = "0";
	userId_ = "1";
}

string TrackerEvent::toJson() {
	json j;
	//Elementos comunes del evento
	j["userID"] = getuserId();
	j["time"] = gettimeStamp();
	string result = j.dump();
	return result;
}

TrackerEvent::~TrackerEvent()
{
}
