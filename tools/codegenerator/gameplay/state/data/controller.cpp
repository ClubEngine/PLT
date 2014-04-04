#include "<<<CC>>>.hpp"

#include "../models/<<<CM>>>.hpp"
#include "../views/<<<CV>>>.hpp"


<<<CC>>>::<<<CC>>>(ControllerHelper & helper)
	: AbstractStateController(helper)
{	
}

void <<<CC>>>::setModel(<<<CM>>> &model)
{
	mModel = &model;
}

void <<<CC>>>::setView(<<<CV>>> &view)
{
	mView = &view;
}

bool <<<CC>>>::processAuthoritativeMessage(const NetworkMessage & msg)
{	
	return true;
}
