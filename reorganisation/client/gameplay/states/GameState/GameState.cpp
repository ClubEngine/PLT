#include "GameState.hpp"

namespace Gameplay
{
    GameState::GameState() : State(), mID(GameStateID)
    {
    }
    RTSStateID GameState::getID() const
    {
        return mID;
    }
}
