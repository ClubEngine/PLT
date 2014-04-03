#include "RTSStateFactory.hpp"

#include "GameState/GameState.hpp"

namespace Gameplay
{
    RTSStateFactory::RTSStateFactory() : Engine::StateFactory()
    {
    }
    Engine::State* RTSStateFactory::create(RTSStateID id)
    {
        Engine::State* res = 0;
        switch(id)
        {
            case GameStateID:
                res = new GameState();
                break;
        }
        return res;
    }
}
