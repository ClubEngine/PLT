#ifndef CONTEXT_HPP
#define CONTEXT_HPP

namespace sf {
	class RenderWindow;
}

namespace Engine {
	class TextureHolder;
	class SoundHolder;
}

/** Contain global resources for states
  */
class Context
{
	public:
		Context(sf::RenderWindow & _window, Engine::TextureHolder & _textures,
				Engine::SoundHolder & _sounds) 
			: window(&_window), textures(&_textures),
			  sounds(&_sounds)
		{
		}

		sf::RenderWindow * window;
		Engine::TextureHolder * textures;
		Engine::SoundHolder * sounds;
	
};

#endif // CONTEXT_HPP
