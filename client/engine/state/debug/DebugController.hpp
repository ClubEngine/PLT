#ifndef DEBUGCONTROLLER_HPP
#define DEBUGCONTROLLER_HPP

#include "Engine.hpp"

class DebugController : public AbstractStateController {
	public:
		DebugController(ControllerHelper & helper);
		
		virtual bool processAuthoritativeMessage();
		
		void exit();
		
};

#endif // DEBUGCONTROLLER_HPP
