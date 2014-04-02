#ifndef TESTSTATE_HPP
#define TESTSTATE_HPP


#include "../engine/state/State.hpp"

#include "engine/map.hpp"

class TestState : public State
{
	public:
		TestState(StateStackManager & stack, Context &context);
		
		virtual bool handleEvent(const sf::Event & event);
		virtual bool update(sf::Time dt);
		virtual void draw();
		
	private:
		Map* carte;
		
};

#endif // TESTSTATE_HPP
