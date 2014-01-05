#include "TestState.hpp"

TestState::TestState(StateStack &stack, Context &context)
	: State(stack, context)
{
	
	carte = new Map();
    carte->setTile(1,1,1); // on place une terre
}


bool TestState::handleEvent(const sf::Event &event)
{
	
	return true;
}

bool TestState::update(sf::Time dt)
{
	return true;
}

void TestState::draw()
{
	
	carte->Display(application.getWindow());
}
