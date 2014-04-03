#include "PauseModel.hpp"

#include "../views/PauseView.hpp"
#include "../controllers/PauseController.hpp"


PauseModel::PauseModel(ModelHelper &helper)
	: AbstractStateModel(helper)
{
}

void PauseModel::setView(PauseView &view)
{
	mView = &view;
}

void PauseModel::setController(PauseController &controller)
{
	mController = &controller;
}

bool PauseModel::update(sf::Time dt)
{
	return true;
}
