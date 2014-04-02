#include "State.hpp"

#include "engine/Context.hpp"
#include "engine/state/StateStack.hpp"

State::State(StateStackManager &stack, Context context)
	: mStack(stack), mContext(context),
	  mController(0), mModel(0), mView(0)
{
}


void State::processController()
{
	if (mController)
		mController->processAuthoritativeMessage();
}

void State::updateModel(sf::Time dt)
{
	if (mModel)
		mModel->update();
}

bool State::processView(const sf::Event & event)
{
	handleEvent(event);
	if (mView)
		return mView->processInputs();
	return true;
}

void State::updateView(sf::Time dt)
{
	update(dt);//test
	if (mView)
		mView->update();
}

void State::render()
{
	draw();
	if (mView)
		mView->render();
}


void State::requestStackPush(States::ID stateID)
{
	mStack.pushState(stateID);
}

void State::requestStackPop()
{
	mStack.popState();
}

void State::requestStateClear()
{
	mStack.clearStates();
}

Context State::getContext() const
{
	return mContext;
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


