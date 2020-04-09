#include "Puzzle.h"
#include <Tracker.h>

Puzzle::~Puzzle()
{
	delete timingSalida;
}

void Puzzle::handleEvent(SDL_Event& e)
{
	GameState::handleEvent(e);
	if (e.type == SDL_MOUSEBUTTONDOWN) { 
		// USABILIDAD
		ClickEvent trackEvent = Tracker::GetInstance().createClickEvent();
		trackEvent.setParameters(0, { e.button.x, e.button.y }); // TO DO numPuzle (dos eventos click?)
		Tracker::GetInstance().trackEvent(&trackEvent);
	}
}
