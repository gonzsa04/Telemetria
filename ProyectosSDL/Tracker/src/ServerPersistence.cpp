#include "ServerPersistence.h"
#include "HTTPRequest.hpp"
#include "JsonSerializer.h"
#include "CSVSerializer.h"

ServerPersistence::ServerPersistence()
{
	_serializeObjects.push_back(new JsonSerializer());
	_serializeObjects.push_back(new CSVSerializer());
}

void ServerPersistence::Send(const TrackerEvent * trackerEvent)
{
	_events.push(trackerEvent);
	std::cout << "event sent" << std::endl;
}


void ServerPersistence::Flush()
{

	if (!_events.empty())
	{

		http::Request request("http://test.com/test");

		while (!_events.empty()) //write pending events
		{
			const TrackerEvent* tEvent = _events.pop();

			for (std::list<ISerializer*>::iterator it = _serializeObjects.begin(); it != _serializeObjects.end(); ++it)
			{
				try
				{
					std::string event = (*it)->Serialize(tEvent);
					std::string contentType = "Content-Type: application/";
					contentType += (*it)->Format();

					// send a post request
					const http::Response response = request.send("POST", event, {
						contentType
						});
					std::cout << std::string(response.body.begin(), response.body.end()) << '\n'; // print the result
				}
				catch (const std::exception& e)
				{
					std::cerr << "Request failed, error: " << e.what() << '\n';
				}
			}
		}
	}
}

ServerPersistence::~ServerPersistence()
{
}
