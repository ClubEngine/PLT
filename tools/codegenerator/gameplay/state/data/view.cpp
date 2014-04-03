#include "<<<CV>>>.hpp"

#include "../models/<<<CM>>>.hpp"
#include "../controllers/<<<CC>>>.hpp"


<<<CV>>>::<<<CV>>>(ViewHelper &helper)
	: AbstractStateView(helper)
{
}

void <<<CV>>>::setModel(<<<CM>>> &model)
{
	mModel = &model;
}

void <<<CV>>>::setController(<<<CC>>> &controller)
{
	mController = &controller;
}

bool <<<CV>>>::processInputs(const sf::Event & event)
{
	return true;
}

bool <<<CV>>>::update(sf::Time dt)
{
	return true;
}

void <<<CV>>>::render()
{
}
