#ifndef CONTEXT_HPP
#define CONTEXT_HPP

namespace sf {
	class RenderWindow;
}
class TextureHolder;

class Context
{
	public:
		Context(sf::RenderWindow& _window, TextureHolder& _textures) 
			: window(_window), textures(_textures)
		{
			
		}

		sf::RenderWindow &        window;
		TextureHolder &           textures;
	
};

#endif // CONTEXT_HPP
