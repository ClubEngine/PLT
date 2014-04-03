#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "../../../engine/state/State.hpp"
#include "../RTSStatesID.hpp"

namespace Gameplay
{
    class GameState : public Engine::State
    {
        public:
            GameState();
            RTSStateID getID() const;
        protected:
            RTSStateID mID;
    };
}
#endif // GAMESTATE_HPP
