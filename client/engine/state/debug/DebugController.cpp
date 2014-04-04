#include "DebugController.hpp"




DebugController::DebugController(ControllerHelper &helper)
	: AbstractStateController(helper)
{
}

bool DebugController::processAuthoritativeMessage(const NetworkMessage &msg)
{
	return true;
}

void DebugController::exit()
{
	mHelper.requestStateClear();
}
