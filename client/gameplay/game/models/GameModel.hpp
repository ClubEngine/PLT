#ifndef GAMEMODEL_HPP
#define GAMEMODEL_HPP

#include "Engine.hpp"

class GameView;
class GameController;

class GameModel : public AbstractStateModel
{
	public:
		GameModel(ModelHelper & helper);
		void setView(GameView & view);
		void setController(GameController & controller);
		
		virtual bool update(sf::Time dt);
	private:
		//EntityManager entities;
		
		GameView * mView;
		GameController * mController;
};

#endif // GAMEMODEL_HPP
