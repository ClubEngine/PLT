#include "DebugController.hpp"




DebugController::DebugController(ControllerHelper &helper)
	: AbstractStateController(helper)
{
}

bool DebugController::processAuthoritativeMessage()
{
	return true;
}

void DebugController::exit()
{
	mHelper.requestStateClear();
}
