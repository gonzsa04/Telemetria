#pragma once
#include "ISerializer.h"
#include <fstream>
#include "json.hpp"
#include <string>


using namespace nlohmann;
using namespace std;

class CSVSerializer: public ISerializer
{
public:
	CSVSerializer();
	string Serialize(TestEvent event);
	~CSVSerializer();
};

