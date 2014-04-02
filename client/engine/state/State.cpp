#include "State.hpp"

#include "engine/Context.hpp"
#include "engine/state/StateStack.hpp"

State::State(StateStack &stack, Context context)
	: mStack(stack), mContext(context)
{
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



State::~State()
{
}


