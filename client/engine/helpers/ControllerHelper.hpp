#ifndef CONTROLLERHELPER_HPP
#define CONTROLLERHELPER_HPP

#include <SFML/System.hpp>
#include "network/NetInterface.hpp"

namespace engine {
	class Application;
}

class StateStackManager;
class AbstractStateController;

#include "state/States.hpp"
#include "MyStates.hpp"

class ControllerHelper : sf::NonCopyable
{
	public:
		
		void requestStackPush(States::ID stateID);
		void requestStackPop();
		void requestStateClear();
	
		void sendToAuthoritativeController(const Command & command);
	
	private:
		
		friend class engine::Application;
		//friend class AbstractStateController;
		
		ControllerHelper();		
		
		void setStateStackManager(StateStackManager & ssM);
	
		StateStackManager * mSsM;
		NetInterface * mNetwork;
		
};

#endif // CONTROLLERHELPER_HPP
