#include "TestEvent.h"



TestEvent::TestEvent()
{
}

string TestEvent::toJson() {
	json j;
	//Aqu� se meter�an los atributos del evento en el json
	string result = j.dump();
	return result;
}

TestEvent::~TestEvent()
{
}
