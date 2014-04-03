#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP


#include "views/GameView.hpp"
#include "models/GameModel.hpp"
#include "controllers/GameController.hpp"

class GameState : public State
{
	public:
		GameState(StateStackManager & stack, Context &context);
		
	private:

		GameView mView;
		GameModel mModel;
		GameController mController;
		
};


#endif // GAMESTATE_HPP
