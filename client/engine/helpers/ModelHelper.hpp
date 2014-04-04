#ifndef MODELHELPER_HPP
#define MODELHELPER_HPP

#include <SFML/System.hpp>

namespace engine{
	class Application;
}

class ModelHelper : sf::NonCopyable
{
	public:

	private:
		friend class engine::Application;
		
		ModelHelper();
};

#endif // MODELHELPER_HPP
