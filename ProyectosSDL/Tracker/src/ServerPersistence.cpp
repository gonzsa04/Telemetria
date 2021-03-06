#include "ServerPersistence.h"
#include "ISerializer.h"
#include "HTTPRequest.hpp"

ServerPersistence::ServerPersistence(const std::list<ISerializer*> serializers, const std::string url)
{
	_serializeObjects = serializers;
	_url = url;
}

/// Applies persistence to the stored events in the queue sending them to a server
void ServerPersistence::protectedFlush()
{
	std::string method = "POST";
	http::Request request(_url);

	unsigned int i = 0;
	while (!_eventQueue.empty() && i < MAX_EVENTS) //write pending events
	{
		const TrackerEvent* event = _eventQueue.pop();

		//serializes the event in all availlable formats
		for (std::list<ISerializer*>::iterator it = _serializeObjects.begin(); it != _serializeObjects.end(); ++it)
		{
			try
			{
				std::string stringEvent = (*it)->Serialize(event); //serialized event
				std::string contentType = "Content-Type: application/";
				contentType += (*it)->Format();

				// send a post request
				request.send(method, stringEvent, {	contentType });
			}
			catch (const std::exception & e)
			{
				std::cerr << "Request failed, error: " << e.what() << '\n';
			}

		}

		TrackerEvent::releasePointer(event);
		i++;
	}

	//operation finished, thread is now free
	mutex_.lock();
	threadFinished_ = true;
	mutex_.unlock();
}

// Prepares protected flush operation if thread is free
void ServerPersistence::Flush()
{
	mutex_.lock();

	if (threadFinished_) {
		std::cout << "flushingServer" << std::endl;
		threadFinished_ = false;
		mutex_.unlock();
		if(thread_.joinable())
			thread_.join();

		thread_ = std::thread(&ServerPersistence::protectedFlush, this);
	}
	else {
		mutex_.unlock();
	}
}

ServerPersistence::~ServerPersistence()
{
}
