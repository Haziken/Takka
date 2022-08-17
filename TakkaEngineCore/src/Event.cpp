#include "../include/Event.h"
#include "../include/EventManager.h"

Takka::Event::Event() noexcept
{
	REGEVENT;
}

Takka::Event::~Event() noexcept
{
	DELEVENT
}
