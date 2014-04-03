#ifndef RTSSTATEFACTORY_HPP
#define RTSSTATEFACTORY_HPP

#include "../../engine/state/StateFactory.hpp"
#include "../../engine/state/State.hpp"
#include "RTSStatesID.hpp"

namespace Gameplay
{
    class RTSStateFactory : public Engine::StateFactory
    {
        public:
            RTSStateFactory();
            virtual Engine::State* create(RTSStateID id);
    };
}

#endif // RTSSTATEFACTORY_HPP
