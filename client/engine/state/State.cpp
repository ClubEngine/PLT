#include "State.hpp"

#include "engine/Context.hpp"
#include "StateStackManager.hpp"

State::State()
	: mController(0), mModel(0), mView(0)
{
}


bool State::processController()
{
	if (mController)
		return mController->processAuthoritativeMessage();
	return true;
}

bool State::updateModel(sf::Time dt)
{
	if (mModel)
		return mModel->update(dt);
	return true;
}

bool State::processView(const sf::Event & event)
{
	if (mView)
		return mView->processInputs(event);
	return true;
}

bool State::updateView(sf::Time dt)
{
	if (mView)
		return mView->update(dt);
	return true;
}

void State::render()
{
	if (mView)
		mView->render();
}



void State::registerController(AbstractStateController &controller)
{
	mController = &controller;
}

void State::registerView(AbstractStateView &view)
{
	mView = &view;
}

void State::registerModel(AbstractStateModel &model)
{
	mModel = &model;
}



State::~State()
{
}


