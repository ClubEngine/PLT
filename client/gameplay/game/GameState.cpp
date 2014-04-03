#include "GameState.hpp"
#include "engine/map.hpp"
#include "engine/CordinatesHelper.hpp"
#include <iostream>
#include <cmath>
#include "gameplay/MyStates.hpp"
#include "../common/commands/gameplay/CommandMove.hpp"
#include "../common/commands/gameplay/CommandBuild.hpp"

using namespace std;

GameState::GameState(ModelHelper &modelHelper, 
					 ViewHelper &viewHelper,
				     ControllerHelper &controllerHelper)
    : AbstractState(), mModel(modelHelper), mView(viewHelper), mController(controllerHelper)
{
	mModel.setView(mView);
	mModel.setController(mController);
	
	mView.setModel(mModel);
	mView.setController(mController);
	
	mController.setModel(mModel);
	mController.setView(mView);
	
	registerController(mController);
	registerModel(mModel);
	registerView(mView);	
}
