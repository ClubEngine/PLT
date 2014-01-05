#ifndef STATE_HPP
#define STATE_HPP


#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

#include "States.hpp"

#include "core/Context.hpp"
#include "core/TextureHolder.hpp"
#include <SFML/Graphics.hpp>


class StateStack;


class State
{
	public:
				
		State(StateStack & stack, Context & context);
		
		virtual void draw() = 0;
		virtual bool update(sf::Time dt) = 0;
		virtual bool handleEvent(const sf::Event & event) = 0; 
		
		
		virtual ~State();
		
	protected:
		void requestStackPush(States::ID stateID);
		void requestStackPop();
		void requestStateClear();

		Context & getContext() const;
		
		
	private:
		
		StateStack & mStack;
		Context & mContext;
};

#endif // STATE_HPP
