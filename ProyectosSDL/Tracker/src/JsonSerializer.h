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
	string Serialize(TestEvent event);
	~JsonSerializer();
};
