#include "GameModel.hpp"

GameModel::GameModel(ModelHelper &helper)
	: AbstractStateModel(helper)
{
//	MovableEntity * entity;
//	entity = new MovableEntity(); entity->setPosition(0,0); entities.add(entity);
//	entity = new MovableEntity(); entity->setPosition(100,10); entities.add(entity);
//	entity = new MovableEntity(); entity->setPosition(10,100); entities.add(entity);
	
}

void GameModel::setView(GameView &view)
{
	mView = &view;
}

void GameModel::setController(GameController &controller)
{
	mController = &controller;
}

bool GameModel::update(sf::Time dt)
{
	return true;
}
