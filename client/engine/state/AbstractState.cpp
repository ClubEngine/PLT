#include "AbstractState.hpp"

#include "engine/Context.hpp"
#include "StateStackManager.hpp"

AbstractState::AbstractState()
	: mController(0), mModel(0), mView(0)
{
}


bool AbstractState::processController()
{
	if (mController)
		return mController->processAuthoritativeMessage();
	return true;
}

bool AbstractState::updateModel(sf::Time dt)
{
	if (mModel)
		return mModel->update(dt);
	return true;
}

bool AbstractState::processView(const sf::Event & event)
{
	if (mView)
		return mView->processInputs(event);
	return true;
}

bool AbstractState::updateView(sf::Time dt)
{
	if (mView)
		return mView->update(dt);
	return true;
}

void AbstractState::render()
{
	if (mView)
		mView->render();
}



void AbstractState::registerController(AbstractStateController &controller)
{
	mController = &controller;
}

void AbstractState::registerView(AbstractStateView &view)
{
	mView = &view;
}

void AbstractState::registerModel(AbstractStateModel &model)
{
	mModel = &model;
}



AbstractState::~AbstractState()
{
}


