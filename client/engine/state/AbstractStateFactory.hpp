#ifndef ABSTRACTSTATEFACTORY_HPP
#define ABSTRACTSTATEFACTORY_HPP

#include "States.hpp"

#include "AbstractState.hpp"
#include "debug/DebugState.hpp"


class AbstractStateFactory
{
	public:
		AbstractStateFactory();
		
		virtual AbstractState * get(States::ID id,
							ModelHelper &modelHelper, 
						    ViewHelper &viewHelper,
						    ControllerHelper &controllerHelper) = 0;
		
};

#endif // STATEFACTORY_HPP
