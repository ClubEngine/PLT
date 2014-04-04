#include "ViewHelper.hpp"

ViewHelper::ViewHelper()
{
	
}



sf::RenderTarget &ViewHelper::getRenderTarget() const
{
	return *mWindow;
}

Engine::TextureHolder &ViewHelper::getTextureHolder() const
{
	return *mTextureHolder;
}
