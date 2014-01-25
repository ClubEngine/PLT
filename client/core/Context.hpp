#ifndef CONTEXT_HPP
#define CONTEXT_HPP

namespace sf {
	class RenderWindow;
}
class TextureHolder;
class SoundHolder;

/** Contain global resources for states
  */
class Context
{
	public:
		Context(sf::RenderWindow & _window, TextureHolder & _textures,
				SoundHolder & _sounds) 
			: window(&_window), textures(&_textures),
			  sounds(&_sounds)
		{
		}

		sf::RenderWindow * window;
		TextureHolder * textures;
		SoundHolder * sounds;
	
};

#endif // CONTEXT_HPP
