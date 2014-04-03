#ifndef STATEFACTORY_HPP
#define STATEFACTORY_HPP

#include "../../tools/Factory.hpp"
#include "State.hpp"

namespace Engine
{
    class StateFactory : public Factory<State, StateID>
    {
        public:
            StateFactory();
            virtual ~StateFactory();
		
            virtual State* create(StateID) = 0;
		
    };
}

#endif // STATEFACTORY_HPP
