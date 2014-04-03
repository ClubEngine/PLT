#include "MyStateFactory.hpp"

#include "TitleState.hpp"
#include "game/GameState.hpp"
//#include "TestState.hpp"
#include "PauseState.hpp"

MyStateFactory::MyStateFactory()
{
}

State * MyStateFactory::get(States::ID id, 
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
		
//		case States::Test:
//			return new TestState(modelHelper,
//								 viewHelper,
//							     controllerHelper);
//			break;
			
//		case States::Title:
//			return new TitleState(modelHelper,
//								  viewHelper,
//								  controllerHelper);
//			break;
		
		case States::Game:
			return new GameState(modelHelper,
								 viewHelper,
							     controllerHelper);
			break;
			
//		case States::Pause:
//			return new PauseState(modelHelper,
//								  viewHelper,
//								  controllerHelper);
//			break;
		
		default:
			return 0;
	}
}
