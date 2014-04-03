#include "AbstractStateController.hpp"

#include "StateStackManager.hpp"


AbstractStateController::AbstractStateController(ControllerHelper &helper)
	: mHelper(helper)
{
}

void AbstractStateController::requestStackPush(States::ID stateID)
{
	if (mHelper.mSsM)
		mHelper.mSsM->pushState(stateID);
}

void AbstractStateController::requestStateClear()
{
	if (mHelper.mSsM)
		mHelper.mSsM->clearStates();
}

void AbstractStateController::requestStackPop()
{
	if (mHelper.mSsM)
		mHelper.mSsM->popState();
}
