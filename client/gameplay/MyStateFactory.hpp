#ifndef MYSTATEFACTORY_HPP
#define MYSTATEFACTORY_HPP

#include "../engine/state/AbstractStateFactory.hpp"
#include "gameplay/MyStates.hpp"

class MyStateFactory : public AbstractStateFactory
{
	public:
		MyStateFactory();
		
		virtual State * get(States::ID id, StateStackManager &stateStack, Context & context);
};

#endif // CSTATEFACTORY_HPP
