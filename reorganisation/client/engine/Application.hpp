#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "state/StateStackManager.hpp"
#include "state/StateFactory.hpp"

namespace Engine
{
    class Application
    {
        public:
            Application(StateFactory* factory);
            void run();
        protected:
            StateStackManager mStateStackManager;
    };
}
#endif // APPLICATION_HPP
