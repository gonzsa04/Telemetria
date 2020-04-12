#include "CSVSerializer.h"



CSVSerializer::CSVSerializer()
{
}

string CSVSerializer::Serialize(const TrackerEvent* event) {
	return event->toCSV();
}

CSVSerializer::~CSVSerializer()
{
}
