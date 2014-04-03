#include "PauseState.hpp"

PauseState::PauseState(ModelHelper &modelHelper, 
					 ViewHelper &viewHelper,
				     ControllerHelper &controllerHelper)
    : AbstractState(), 
    mModel(modelHelper), 
    mView(viewHelper), 
    mController(controllerHelper)
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
