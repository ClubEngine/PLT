#include "StateFactory.hpp"

namespace Engine
{
    StateFactory::StateFactory() : Factory<State, StateID>()
    {
    }
    StateFactory::~StateFactory()
    {
    }
}
