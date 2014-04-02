#include <iostream>

#include "TitleState.hpp"




TitleState::TitleState(StateStackManager &stack, Context & context) 
	: State(stack, context)
{
}

void TitleState::draw()
{
	//std::cout << "TitleState.draw" << std::endl;
	getContext().window->clear(sf::Color::Red);
}

bool TitleState::update(sf::Time dt)
{
	
	return true;
}

bool TitleState::handleEvent(const sf::Event &event)
{
	
	return false;
}
