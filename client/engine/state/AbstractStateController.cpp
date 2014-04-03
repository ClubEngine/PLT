#include "AbstractStateController.hpp"

#include "StateStackManager.hpp"


AbstractStateController::AbstractStateController(ControllerHelper &helper)
	: mHelper(helper)
{
}

void AbstractStateController::requestStackPush(States::ID stateID)
{
}

void AbstractStateController::requestStateClear()
{
	if (mHelper.mSsM)
		mHelper.mSsM->clearStates();
}

void AbstractStateController::requestStackPop()
{
}
