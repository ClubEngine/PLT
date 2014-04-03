#include "ControllerHelper.hpp"



ControllerHelper::ControllerHelper()
{
}


void ControllerHelper::setStateStackManager(StateStackManager &ssM)
{
	mSsM = &ssM;
}




//void State::requestStackPush(States::ID stateID)
//{
//	mStack.pushState(stateID);
//}

//void State::requestStackPop()
//{
//	mStack.popState();
//}

//void State::requestStateClear()
//{
//	mStack.clearStates();
//}
