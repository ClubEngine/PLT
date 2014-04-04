#ifndef VIEWHELPER_HPP
#define VIEWHELPER_HPP

#include <SFML/System.hpp>

#include <SFML/Graphics.hpp>

namespace engine{
	class Application;
	class TextureHolder;
	class SoundHolder;
}

class ViewHelper : sf::NonCopyable
{
	public:
		
		sf::RenderTarget & getRenderTarget() const;
		engine::TextureHolder & getTextureHolder() const;
		
		int a;
	private:
		friend class engine::Application;
		
		ViewHelper();
		
		sf::RenderWindow * mWindow;
		engine::TextureHolder * mTextureHolder;
		engine::SoundHolder * mSoundHolder; 
			
};

#endif // VIEWHELPER_HPP
