#include "TitleState.hpp"

TitleState::TitleState(StateStack &stack, Context & context) 
	: State(stack, context)
{
}

void TitleState::draw()
{
}

bool TitleState::update(sf::Time dt)
{
}

bool TitleState::handleEvent(const sf::Event &event)
{
}
