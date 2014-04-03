#ifndef ABSTRACTSTATECONTROLLER_HPP
#define ABSTRACTSTATECONTROLLER_HPP

#include <SFML/System/NonCopyable.hpp>

#include "helpers/ModelHelper.hpp"
#include "helpers/ViewHelper.hpp"

#include "helpers/ControllerHelper.hpp"
#include "States.hpp"


class AbstractStateController : sf::NonCopyable
{
	public:
		AbstractStateController(ControllerHelper & helper);
		
		virtual bool processAuthoritativeMessage() = 0;
	
	protected:
		void requestStackPush(States::ID stateID);
		void requestStackPop();
		void requestStateClear();
	
	private:
		ControllerHelper & mHelper;
		
};

#endif // ABSTRACTSTATECONTROLLER_HPP
