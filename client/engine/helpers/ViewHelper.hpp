#ifndef VIEWHELPER_HPP
#define VIEWHELPER_HPP

#include <SFML/System.hpp>

#include <SFML/Graphics.hpp>

namespace Engine{
	class Application;
	class TextureHolder;
	class SoundHolder;
}

class ViewHelper : sf::NonCopyable
{
	public:
		
		sf::RenderTarget & getRenderTarget() const;
		Engine::TextureHolder & getTextureHolder() const;
		
		int a;
	private:
		friend class Engine::Application;
		
		ViewHelper();
		
		sf::RenderWindow * mWindow;
		Engine::TextureHolder * mTextureHolder;
		Engine::SoundHolder * mSoundHolder; 
		
		
		
};

#endif // VIEWHELPER_HPP
