#ifndef PAUSESTATE_HPP
#define PAUSESTATE_HPP


#include "../core/state/State.hpp"

#include "core/map.hpp"

class PauseState : public State
{
	public:
		PauseState(StateStack & stack, Context &context);
		
		virtual bool handleEvent(const sf::Event & event);
		virtual bool update(sf::Time dt);
		virtual void draw();
		
	private:
		
};

#endif // PauseState_HPP
