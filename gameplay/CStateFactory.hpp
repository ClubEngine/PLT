#ifndef CSTATEFACTORY_HPP
#define CSTATEFACTORY_HPP

#include "../core/state/AbstractStateFactory.hpp"

class CStateFactory : public AbstractStateFactory
{
	public:
		CStateFactory();
		
		virtual State * get(States::ID id, StateStack &stateStack, Context & context);
};

#endif // CSTATEFACTORY_HPP
