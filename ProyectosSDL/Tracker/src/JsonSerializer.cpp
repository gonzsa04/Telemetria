#include "JsonSerializer.h"

JsonSerializer::JsonSerializer() {

}

string JsonSerializer::Serialize(TestEvent event) {
	return event.toJson();
}

JsonSerializer::~JsonSerializer()
{
}