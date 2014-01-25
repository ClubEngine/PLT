#ifndef DEBUGSTATE_HPP
#define DEBUGSTATE_HPP

#include "State.hpp"

class DebugState : public State
{
	public:
		DebugState(StateStack & stack, Context &context);
		
		virtual bool handleEvent(const sf::Event & event);
		virtual bool update(sf::Time dt);
		virtual void draw();
};

#endif // DEBUGSTATE_HPP
