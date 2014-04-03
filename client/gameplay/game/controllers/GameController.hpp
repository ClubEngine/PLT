#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP

#include "Gameplay.hpp"

class GameModel;
class GameView;

class GameController : public AbstractStateController
{
		
	public:
		GameController(ControllerHelper & helper);
		void setModel(GameModel & model);
		void setView(GameView & view);
		
		virtual bool processAuthoritativeMessage();
				
	private:
		//NetInterface netInterface;
		GameView * mView;
		GameModel * mModel;
};

#endif // GAMECONTROLLER_HPP
