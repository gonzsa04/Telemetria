#include "ServerPersistence.h"
#include "JsonSerializer.h"
#include "CSVSerializer.h"
#include "HTTPRequest.hpp"

ServerPersistence::ServerPersistence()
{
	_serializeObjects.push_back(new JsonSerializer());
	_serializeObjects.push_back(new CSVSerializer());
}

/// A tracker event is stored in the queue
void ServerPersistence::protectedSend(const TrackerEvent * trackerEvent)
{
	_events.push(trackerEvent);
	if (_events.size() >= MAX_EVENTS)
		Flush();
}

/// Applies persistence to the stored events in the queue sending them to a server
void ServerPersistence::protectedFlush()
{
	mutex_.lock();

	if (!_events.empty())
	{
		std::string url = "http://ptsv2.com/t/1s8b7-1586791589/post";
		std::string method = "POST";
		http::Request request(url);

		while (!_events.empty()) //write pending events
		{
			const TrackerEvent* tEvent = _events.pop();

			//serializes the event in all availlable formats
			for (std::list<ISerializer*>::iterator it = _serializeObjects.begin(); it != _serializeObjects.end(); ++it)
			{
				try
				{
					std::string event = (*it)->Serialize(tEvent); //serialized event
					std::string contentType = "Content-Type: application/";
					contentType += (*it)->Format();

					// send a post request
					const http::Response response = request.send(method, event, {
						contentType
						});
					std::cout << std::string(response.body.begin(), response.body.end()) << '\n'; // print the result
				}
				catch (const std::exception& e)
				{
					std::cerr << "Request failed, error: " << e.what() << '\n';
				}
			}
			// delete tEvent;
		}
	}

	mutex_.unlock();
}

void ServerPersistence::Flush()
{
	if (thread_.joinable())
		thread_.join();

	thread_ = std::thread(&ServerPersistence::protectedFlush, this);
}

ServerPersistence::~ServerPersistence()
{
	while (!_serializeObjects.empty())
	{
		_serializeObjects.pop_back();
	}
}
