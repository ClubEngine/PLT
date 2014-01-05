#include "CStateFactory.hpp"

#include "TitleState.hpp"
#include "GameState.hpp"

CStateFactory::CStateFactory()
{
}

State *CStateFactory::get(States::ID id, StateStack &stateStack, Context &context)
{
	switch(id) {
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
