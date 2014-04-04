#ifndef DEBUGCONTROLLER_HPP
#define DEBUGCONTROLLER_HPP

#include "../AbstractStateController.hpp"

class DebugController : public AbstractStateController {
	public:
		DebugController(ControllerHelper & helper);
		
		virtual bool processAuthoritativeMessage(const NetworkMessage & msg);
		
		void exit();
		
};

#endif // DEBUGCONTROLLER_HPP
