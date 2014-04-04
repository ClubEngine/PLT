#include "ViewHelper.hpp"

ViewHelper::ViewHelper()
{
	
}



sf::RenderTarget &ViewHelper::getRenderTarget() const
{
	return *mWindow;
}

engine::TextureHolder &ViewHelper::getTextureHolder() const
{
	return *mTextureHolder;
}
