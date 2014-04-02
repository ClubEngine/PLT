#include "TestState.hpp"

TestState::TestState(StateStackManager &stack, Context &context)
	: State(stack, context)
{
	
    carte = new Map(context, 20, 20);
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
	sf::RenderWindow & window = *getContext().window;
	carte->Display(&window);
}
