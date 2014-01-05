#include "GameState.hpp"


GameState::GameState(StateStack &stack, Context &context)
	: State(stack, context)
{
	//getContext().textures.load(Textures::Patate, "assets/images/patate.png");
}

bool GameState::handleEvent(const sf::Event &event)
{
}

bool GameState::update(sf::Time dt)
{
}

void GameState::draw()
{
	sf::Sprite sp( getContext().textures.get(Textures::Patate) );
	
	getContext().window.draw(sp);
}
