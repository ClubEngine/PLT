#ifndef PAUSECONTROLLER_HPP
#define PAUSECONTROLLER_HPP

#include "Gameplay.hpp"

class PauseModel;
class PauseView;

class PauseController : public AbstractStateController
{
	public:
		PauseController(ControllerHelper & helper);
		void setModel(PauseModel & model);
		void setView(PauseView & view);
		
		virtual bool processAuthoritativeMessage(const NetworkMessage & msg);
		
		void resume();
		void exit();
				
	private:
		PauseView * mView;
		PauseModel * mModel;
};

#endif // PAUSECONTROLLER_HPP
