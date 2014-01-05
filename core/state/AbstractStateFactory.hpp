#ifndef ABSTRACTSTATEFACTORY_HPP
#define ABSTRACTSTATEFACTORY_HPP

#include "States.hpp"

#include "State.hpp"



class StateStack;
class Context;

class AbstractStateFactory
{
	public:
		AbstractStateFactory();
		
		virtual State * get(States::ID id, StateStack & stateStack, Context & context) = 0;
		
};

#endif // STATEFACTORY_HPP
