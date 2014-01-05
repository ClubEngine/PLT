#include "CStateFactory.hpp"

#include "TitleState.hpp"
#include "GameState.hpp"
#include "TestState.hpp"

CStateFactory::CStateFactory()
{
}

State *CStateFactory::get(States::ID id, StateStack &stateStack, Context &context)
{
	switch(id) {
		case States::Debug:
			return new DebugState(stateStack, context);
			break;
		
		case States::Test:
			return new TestState(stateStack, context);
			break;
			
		case States::Title:
			return new TitleState(stateStack, context);
			break;
		
		case States::Game:
			return new GameState(stateStack, context);
			break;
		
		default:
			return 0;
	}
}
