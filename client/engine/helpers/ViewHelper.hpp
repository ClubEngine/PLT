#ifndef VIEWHELPER_HPP
#define VIEWHELPER_HPP

#include <SFML/System.hpp>

#include <SFML/Graphics.hpp>

namespace Engine{
	class Application;
}

class ViewHelper : sf::NonCopyable
{
	public:
		
		sf::RenderTarget & getRenderTarget() const;
		
		int a;
	private:
		friend class Engine::Application;
		
		ViewHelper();
		
		sf::RenderWindow * mWindow;
		
		
};

#endif // VIEWHELPER_HPP
