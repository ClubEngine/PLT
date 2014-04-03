#ifndef STATE_HPP
#define STATE_HPP

namespace Engine
{
    typedef int StateID;
    const StateID None = 0; //others : see RTSStatesID.hpp

    class State
    {
        public:
            State();
            virtual StateID getID() const = 0;

    };
}

#endif // STATE_HPP
