#ifndef MODELHELPER_HPP
#define MODELHELPER_HPP

#include <SFML/System.hpp>

namespace Engine{
	class Application;
}

class ModelHelper : sf::NonCopyable
{
	public:

	private:
		friend class Engine::Application;
		
		ModelHelper();
};

#endif // MODELHELPER_HPP
