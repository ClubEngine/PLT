#ifndef STATESTACKMANAGER_HPP
#define STATESTACKMANAGER_HPP

#include "StateStack.hpp"
#include "StateFactory.hpp"

namespace Engine
{
    class StateStackManager
    {
        public:
            StateStackManager(StateFactory* factory);
        protected:
            StateFactory* mFactory;
            StateStack mStack;
    };
}
#endif // STATESTACKMANAGER_HPP
