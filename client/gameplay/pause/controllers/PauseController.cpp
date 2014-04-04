#include "PauseController.hpp"

#include "../models/PauseModel.hpp"
#include "../views/PauseView.hpp"


PauseController::PauseController(ControllerHelper & helper)
	: AbstractStateController(helper)
{	
}

void PauseController::setModel(PauseModel &model)
{
	mModel = &model;
}

void PauseController::setView(PauseView &view)
{
	mView = &view;
}

bool PauseController::processAuthoritativeMessage(const NetworkMessage & msg)
{	
	return false;
}

void PauseController::resume()
{
	mHelper.requestStackPop();
}

void PauseController::exit()
{
	mHelper.requestStateClear();
}