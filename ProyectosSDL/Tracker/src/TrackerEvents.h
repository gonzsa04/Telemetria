#pragma once
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

// TIPOS DE LOS EVENTOS
enum EventType	{ 
	TEST_EVENT,
	SESSION_START_EVENT,
	SESSION_END_EVENT,
	SCENE_EVENT,
	LIGHTPUZZLE_EVENT,
	CONNECT4_EVENT,
	CLICK_EVENT,
	CLICK_EVENT_SCENE,
	CLICK_EVENT_PUZZLE
};

const std::string eventTypes[] = {
	"TEST_EVENT",
	"SESSION_START_EVENT",
	"SESSION_END_EVENT",
	"SCENE_EVENT",
	"LIGHTPUZZLE_EVENT",
	"CONNECT4_EVENT",
	"CLICK_EVENT"
	"CLICK_EVENT_SCENE",
	"CLICK_EVENT_PUZZLE"
};

// transforma el tipo de evento en un string (su nombre legible)
inline const std::string EventTypeToString(EventType eventType){
	return eventTypes[eventType];
}

// ACCIONES DE LOS EVENTOS
enum EventAction {
	NONE_ACTION,
	ENTER,
	EXIT,
	COMPLETE
};

const std::string eventActions[] = {
	"NONE_ACTION",
	"ENTER",
	"EXIT",
	"COMPLETE"
};

// transforma la accion de evento en un string (su nombre legible)
inline const std::string EventActionsToString(EventAction eventAction) {
	return eventActions[eventAction];
}

// EVENTOS
// padre de todos los eventos
struct TrackerEvent
{
protected:
	double timeStamp_;
	string id_;
	EventType type_;

public:
	TrackerEvent(double timeStamp, string id, EventType type) : timeStamp_(timeStamp), id_(id), type_(type) {}

	virtual const string toJson() const;	
	virtual const string toCSV() const;

	inline const EventType getType() const { return type_; }
};

// EVENTO PARA TESTING
struct TestEvent : public TrackerEvent {
public:
	TestEvent(double timeStamp, string id) : TrackerEvent(timeStamp, id, TEST_EVENT) {}

	virtual const string toJson() const;
	virtual const string toCSV() const;
};

//EVENTOS DE INICIO Y FIN DE SESION
struct SessionStartEvent : public TrackerEvent {
public:
	SessionStartEvent(double timeStamp, string id) : TrackerEvent(timeStamp, id, SESSION_START_EVENT) { std::cout << "SESSION START " << std::endl; }
};

struct SessionEndEvent : public TrackerEvent {
public:
	SessionEndEvent(double timeStamp, string id) : TrackerEvent(timeStamp, id, SESSION_END_EVENT) { std::cout << "SESSION END " << std::endl; }
};

// EVENTO DE ESCENA
struct SceneEvent : public TrackerEvent {
private:
	int numScene_;
	EventAction action_;

public:
	SceneEvent(double timeStamp, string id) : TrackerEvent(timeStamp, id, SCENE_EVENT), numScene_(0), action_(NONE_ACTION) {}

	inline void setParameters(int numScene, EventAction action) { numScene_ = numScene; action_ = action; std::cout << "SCENE " << numScene_ << " " << eventActions[action] << std::endl; }
	virtual const string toJson() const;
	virtual const string toCSV() const;
};

// EVENTOS DE PUZLE
// padre de LightPuzzle y Connect4
struct PuzzleEvent : public TrackerEvent {
private:
	int numPuzzle_;
	EventAction action_;

protected: // de esta forma no se pueden hacer instancias de PuzzleEvent
	PuzzleEvent(double timeStamp, string id, EventType eventType) : TrackerEvent(timeStamp, id, eventType), numPuzzle_(0), action_(NONE_ACTION) {}

public:
	inline void setParameters(int numPuzzle, EventAction action) { numPuzzle_ = numPuzzle; action_ = action; std::cout << "PUZZLE " << numPuzzle_ << " " << eventActions[action] << std::endl;
	}
	virtual const string toJson() const;
	virtual const string toCSV() const;
};

struct Connect4Event : public PuzzleEvent {
public:
	Connect4Event(double timeStamp, string id) : PuzzleEvent(timeStamp, id, CONNECT4_EVENT) {}
};

struct LightPuzzleEvent : public PuzzleEvent {
public:
	LightPuzzleEvent(double timeStamp, string id) : PuzzleEvent(timeStamp, id, LIGHTPUZZLE_EVENT) {}
};

// EVENTO DE CLICK DEL JUGADOR
struct ClickEvent : public TrackerEvent {
protected:
	std::pair<int, int> pos_;
	ClickEvent(double timeStamp, string id, EventType type) : TrackerEvent(timeStamp, id, type), pos_({ 0, 0 }) {}

public:
	inline void setParameters(std::pair<int, int> pos) { pos_ = pos; }

	virtual const string toJson() const;
	virtual const string toCSV() const;
};

struct ClickSceneEvent : public ClickEvent {
private:
	int numScene_;

public:
	ClickSceneEvent(double timeStamp, string id) : ClickEvent(timeStamp, id, CLICK_EVENT_SCENE), numScene_(0) {}
	inline void setParameters(int numScene, std::pair<int, int> pos) {
		ClickEvent::setParameters(pos),	numScene_ = numScene; std::cout << "CLICK SCENE " << numScene_ << " " << pos_.first << " " << pos_.second << std::endl;
	}
	virtual const string toJson() const;
	virtual const string toCSV() const;
};


struct ClickPuzzleEvent : public ClickEvent {
private:
	int numPuzzle_;

public:
	ClickPuzzleEvent(double timeStamp, string id) : ClickEvent(timeStamp, id, CLICK_EVENT_PUZZLE), numPuzzle_(0) {}
	inline void setParameters(int numPuzzle, std::pair<int, int> pos) {
		ClickEvent::setParameters(pos), numPuzzle_ = numPuzzle; std::cout << "CLICK PUZZLE " << numPuzzle_ << " " << pos_.first << " " << pos_.second << std::endl;
	}
	virtual const string toJson() const;
	virtual const string toCSV() const;
};




