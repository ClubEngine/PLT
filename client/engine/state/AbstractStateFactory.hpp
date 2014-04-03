#ifndef ABSTRACTSTATEFACTORY_HPP
#define ABSTRACTSTATEFACTORY_HPP

#include "States.hpp"

#include "State.hpp"
#include "debug/DebugState.hpp"


class StateStackManager;
class Context;

class AbstractStateFactory
{
	public:
		AbstractStateFactory();
		
		virtual State * get(States::ID id,
							ModelHelper &modelHelper, 
						    ViewHelper &viewHelper,
						    ControllerHelper &controllerHelper) = 0;
		
};

#endif // STATEFACTORY_HPP
