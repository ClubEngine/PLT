#ifndef TITLESTATE_HPP
#define TITLESTATE_HPP

#include "../engine/state/State.hpp"

class TitleState : public State
{
	public:
		TitleState(StateStackManager & stack, Context &context);
		
		virtual void draw();
		virtual bool update(sf::Time dt);
		virtual bool handleEvent(const sf::Event & event);
		
};

#endif // TITLESTATE_HPP
