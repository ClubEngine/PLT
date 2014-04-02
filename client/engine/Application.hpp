#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "SoundHolder.hpp"
#include "TextureHolder.hpp"
#include "engine/state/StateStack.hpp"

namespace Engine {

	class Application
	{
	    public:
	        Application(AbstractStateFactory & factory);
			void run();
			void pushState(States::ID id);
			
	    private:
			
			void processInputs();
			void update(sf::Time dt);
			void render();
			
	    private:
			static const sf::Time TimePerFrame;
	        
			sf::Context mGLContext;//to create an OpenGL context before the window creation
			sf::RenderWindow mWindow;
			TextureHolder mTextureHolder;
			SoundHolder mSoundHolder;     
			
	        StateStack mStateStack;
	};

}

#endif // APPLICATION_HPP
