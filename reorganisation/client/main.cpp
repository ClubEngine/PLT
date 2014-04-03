#include "engine/Application.hpp"
#include "gameplay/states/RTSStateFactory.hpp"

int main()
{
    Gameplay::RTSStateFactory* factory = new Gameplay::RTSStateFactory();
    Engine::Application app = Engine::Application(factory);
    app.run();
	return 0;
}

