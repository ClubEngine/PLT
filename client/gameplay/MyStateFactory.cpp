#include "MyStateFactory.hpp"

#include "game/GameState.hpp"
#include "pause/PauseState.hpp"

MyStateFactory::MyStateFactory()
{
}

AbstractState * MyStateFactory::get(States::ID id, 
							ModelHelper &modelHelper, 
							ViewHelper &viewHelper,
							ControllerHelper &controllerHelper)
{
	
	switch(id) {
		case States::Debug:
			return new DebugState(modelHelper,
								  viewHelper,
								  controllerHelper);
			break;
		
		case States::Game:
			return new GameState(modelHelper,
								 viewHelper,
							     controllerHelper);
			break;
			
		case States::Pause:
			return new PauseState(modelHelper,
								  viewHelper,
								  controllerHelper);
			break;
		
		default:
			return 0;
	}
}
