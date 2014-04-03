#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP


#include "views/GameView.hpp"
#include "models/GameModel.hpp"
#include "controllers/GameController.hpp"

class GameState : public State
{
	public:
		GameState(ModelHelper &modelHelper, 
				  ViewHelper &viewHelper,
			      ControllerHelper &controllerHelper);
		
	private:

		GameModel mModel;
		GameView mView;
		GameController mController;
		
};


#endif // GAMESTATE_HPP
