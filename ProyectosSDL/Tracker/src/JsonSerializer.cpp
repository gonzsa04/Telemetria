#include "JsonSerializer.h"

JsonSerializer::JsonSerializer() {

}

string JsonSerializer::Serialize(const TrackerEvent* event) {
	return event->toJson();
}

JsonSerializer::~JsonSerializer()
{
}