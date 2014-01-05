#include "PauseState.hpp"

PauseState::PauseState(StateStack &stack, Context &context)
	: State(stack, context)
{
	
}


bool PauseState::handleEvent(const sf::Event &event)
{
	if (event.type == sf::Event::KeyPressed &&
		event.key.code == sf::Keyboard::P)
	{
		requestStackPop();
	}
	return false;
}

bool PauseState::update(sf::Time dt)
{
	
	return false;
}

void PauseState::draw()
{
	sf::RenderWindow & window = *getContext().window;
	
	sf::RectangleShape rect(sf::Vector2f(800,600));
	rect.setFillColor(sf::Color(0,0,0,128));
	window.draw(rect);
}
