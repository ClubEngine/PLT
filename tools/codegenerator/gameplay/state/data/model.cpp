#include "<<<CM>>>.hpp"

#include "../views/<<<CV>>>.hpp"
#include "../controllers/<<<CC>>>.hpp"


<<<CM>>>::<<<CM>>>(ModelHelper &helper)
	: AbstractStateModel(helper)
{
}

void <<<CM>>>::setView(<<<CV>>> &view)
{
	mView = &view;
}

void <<<CM>>>::setController(<<<CC>>> &controller)
{
	mController = &controller;
}

bool <<<CM>>>::update(sf::Time dt)
{
	return true;
}
