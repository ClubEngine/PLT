#ifndef TESTSTATE_HPP
#define TESTSTATE_HPP


#include "../core/state/State.hpp"

#include "core/map.hpp"

class TestState : public State
{
	public:
		TestState(StateStack & stack, Context &context);
		
		virtual bool handleEvent(const sf::Event & event);
		virtual bool update(sf::Time dt);
		virtual void draw();
		
	private:
		Map* carte;
		
};

#endif // TESTSTATE_HPP
