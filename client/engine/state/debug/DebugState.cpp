#include "DebugState.hpp"

DebugState::DebugState(ModelHelper &modelHelper, 
					   ViewHelper &viewHelper,
					   ControllerHelper &controllerHelper)
	: State(), mView(viewHelper),
	  mController(controllerHelper)
{
	mView.setController(mController);
	
	registerController(mController);
	registerView(mView);
}



bool DebugState::DebugView::processInputs(const sf::Event &event)
{
	if (event.type == sf::Event::KeyPressed &&
		event.key.code == sf::Keyboard::Escape)
	{
		mController->resume();
	}
	
	return true;
}

bool DebugState::DebugView::update(sf::Time dt)
{
	return true;
}

void DebugState::DebugView::render()
{
}

void DebugState::DebugView::setController(DebugController &controller)
{
	mController = & controller;
}

DebugState::DebugView::DebugView(ViewHelper &h)
	: AbstractStateView(h)
{
}
