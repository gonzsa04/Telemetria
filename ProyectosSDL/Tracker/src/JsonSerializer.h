#pragma once
#include "ISerializer.h"
#include <fstream>
#include "json.hpp"
#include <string>


using namespace nlohmann;
using namespace std;

class JsonSerializer : public ISerializer 
{
public:
	JsonSerializer();
	
	string Serialize(const TrackerEvent* event);

	inline string Format() { return "json"; };

	~JsonSerializer();
};
