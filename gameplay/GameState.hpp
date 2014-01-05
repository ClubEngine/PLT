#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "../core/state/State.hpp"

class GameState : public State
{
	public:
		GameState(StateStack & stack, Context &context);
		
		virtual bool handleEvent(const sf::Event & event);
		virtual bool update(sf::Time dt);
		virtual void draw();
		
	private:
		int lol;
};


#endif // GAMESTATE_HPP
