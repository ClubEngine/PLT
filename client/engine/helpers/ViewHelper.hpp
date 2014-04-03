#ifndef VIEWHELPER_HPP
#define VIEWHELPER_HPP

#include <SFML/System.hpp>

namespace Engine{
	class Application;
}

class ViewHelper : sf::NonCopyable
{
	public:
		
		int a;
	private:
		friend class Engine::Application;
		
		ViewHelper();
		
		
};

#endif // VIEWHELPER_HPP
