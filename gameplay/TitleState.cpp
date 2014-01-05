#include <iostream>

#include "TitleState.hpp"

#include "SFML/Graphics.hpp"


TitleState::TitleState(StateStack &stack, Context & context) 
	: State(stack, context)
{
}

void TitleState::draw()
{
	//std::cout << "TitleState.draw" << std::endl;
	getContext().window.clear(sf::Color::Red);
}

bool TitleState::update(sf::Time dt)
{
	return true;
}

bool TitleState::handleEvent(const sf::Event &event)
{
}
