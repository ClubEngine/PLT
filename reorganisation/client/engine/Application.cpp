#include "Application.hpp"

namespace Engine
{
    Application::Application(StateFactory* factory) : mStateStackManager(factory)
    {
    }
    void Application::run()
    {
    }
}
