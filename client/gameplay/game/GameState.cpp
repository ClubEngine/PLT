#include "GameState.hpp"
#include "engine/map.hpp"
#include "engine/CordinatesHelper.hpp"
#include <iostream>
#include <cmath>
#include "gameplay/MyStates.hpp"
#include "../common/commands/gameplay/CommandMove.hpp"
#include "../common/commands/gameplay/CommandBuild.hpp"

using namespace std;

GameState::GameState(StateStackManager &stack, Context &context)
    : State(stack, context), mController(), mView(), mModel()
{
	// mController.registerView(mView)
	// etc.
	
	registerController(mController);
	registerModel(mModel);
	registerView(mView);	
}
