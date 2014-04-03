#ifndef STATESTACK_HPP
#define STATESTACK_HPP

#include <stack>
#include "State.hpp"

namespace Engine
{
    class StateStack : std::stack<State*>
    {
        public:
            StateStack();
    };
}

#endif // STATESTACK_HPP
