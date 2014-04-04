#ifndef ABSTRACTSTATECONTROLLER_HPP
#define ABSTRACTSTATECONTROLLER_HPP

#include "Helpers.hpp"

class AbstractStateController : sf::NonCopyable
{
	public:
		AbstractStateController(ControllerHelper & helper);
		
		virtual bool processAuthoritativeMessage() = 0;
	
	protected:
		ControllerHelper & mHelper;
		
	private:
		
};

#endif // ABSTRACTSTATECONTROLLER_HPP
