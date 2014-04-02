#include "DebugState.hpp"

DebugState::DebugState(StateStack &stack, Context &context)
	: State(stack, context)
{
}

bool DebugState::handleEvent(const sf::Event &event)
{
	if (event.type == sf::Event::KeyPressed &&
		event.key.code == sf::Keyboard::Escape)
	{
		requestStateClear();
	}
		
	return true;
}

bool DebugState::update(sf::Time dt)
{
	return true;
}

void DebugState::draw()
{
}
