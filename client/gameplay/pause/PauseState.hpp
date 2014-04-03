#ifndef PAUSESTATE_HPP
#define PAUSESTATE_HPP

#include "Gameplay.hpp"

#include "views/PauseView.hpp"
#include "models/PauseModel.hpp"
#include "controllers/PauseController.hpp"


class PauseState : public AbstractState
{
	public:
		PauseState(ModelHelper &modelHelper, 
				  ViewHelper &viewHelper,
			      ControllerHelper &controllerHelper);
		
	private:
		PauseModel mModel;
		PauseView mView;
		PauseController mController;
};


#endif // PAUSESTATE_HPP
