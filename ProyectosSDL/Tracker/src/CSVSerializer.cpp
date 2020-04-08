#include "CSVSerializer.h"



CSVSerializer::CSVSerializer()
{
}

string CSVSerializer::Serialize(TestEvent event) {
	return event.toCSV();
}

CSVSerializer::~CSVSerializer()
{
}
