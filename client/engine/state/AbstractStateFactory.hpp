#ifndef ABSTRACTSTATEFACTORY_HPP
#define ABSTRACTSTATEFACTORY_HPP

#include "States.hpp"

#include "State.hpp"
#include "DebugState.hpp"


class StateStackManager;
class Context;

class AbstractStateFactory
{
	public:
		AbstractStateFactory();
		
		virtual State * get(States::ID id, StateStackManager & stateStack, Context & context) = 0;
		
};

#endif // STATEFACTORY_HPP
