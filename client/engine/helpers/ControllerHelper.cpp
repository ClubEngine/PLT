#include "ControllerHelper.hpp"
#include "state/StateStackManager.hpp"

ControllerHelper::ControllerHelper()
{
}

void ControllerHelper::setStateStackManager(StateStackManager &ssM)
{
	mSsM = &ssM;
}


void ControllerHelper::requestStackPush(States::ID stateID)
{
	if (mSsM)
		mSsM->pushState(stateID);
}

void ControllerHelper::requestStateClear()
{
	if (mSsM)
		mSsM->clearStates();
}

void ControllerHelper::sendToAuthoritativeController(const Command &command)
{
	mNetwork->send(command);
}

void ControllerHelper::requestStackPop()
{
	if (mSsM)
		mSsM->popState();
}

