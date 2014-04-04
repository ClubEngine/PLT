#ifndef CONTROLLERHELPER_HPP
#define CONTROLLERHELPER_HPP

#include <SFML/System.hpp>

#include "../Context.hpp"

namespace engine {
	class Application;
}

class StateStackManager;
class AbstractStateController;

#include "state/States.hpp"

class ControllerHelper : sf::NonCopyable
{
	public:
		
		void requestStackPush(States::ID stateID);
		void requestStackPop();
		void requestStateClear();
		
	
	private:
		
		friend class engine::Application;
		friend class AbstractStateController;
		
		ControllerHelper();		
		
		void setStateStackManager(StateStackManager & ssM);
	
		void a();
		
		
		Context * context;
		
		StateStackManager * mSsM;
		
};

#endif // CONTROLLERHELPER_HPP
