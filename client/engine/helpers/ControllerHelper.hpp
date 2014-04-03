#ifndef CONTROLLERHELPER_HPP
#define CONTROLLERHELPER_HPP

#include <SFML/System.hpp>

#include "../Context.hpp"

namespace Engine{
	class Application;
}

class StateStackManager;
class AbstractStateController;

class ControllerHelper : sf::NonCopyable
{
	public:
		
		
		
	
	private:
		
		friend class Engine::Application;
		friend class AbstractStateController;
		
		ControllerHelper();		
		
		void setStateStackManager(StateStackManager & ssM);
	
		void a();
		
		
		Context * context;
		
		StateStackManager * mSsM;
		
};

#endif // CONTROLLERHELPER_HPP
