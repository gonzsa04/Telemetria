#include "TestEvent.h"



TestEvent::TestEvent()
{
}

string TestEvent::toJson() {
	json j;
	//Aquí se meterían los atributos del evento en el json
	string result = j.dump();
	return result;
}

TestEvent::~TestEvent()
{
}
