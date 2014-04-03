#ifndef PAUSESTATE_HPP
#define PAUSESTATE_HPP


#include "../engine/state/State.hpp"

#include "engine/map.hpp"

class PauseState : public AbstractState
{
	public:
		PauseState(StateStackManager & stack, Context &context);
		
		virtual bool handleEvent(const sf::Event & event);
		virtual bool update(sf::Time dt);
		virtual void draw();
		
	private:
		
};

#endif // PauseState_HPP
