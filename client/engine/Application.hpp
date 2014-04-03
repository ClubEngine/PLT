#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "SoundHolder.hpp"
#include "TextureHolder.hpp"
#include "state/StateStackManager.hpp"
#include "state/AbstractStateFactory.hpp"

namespace Engine {

	class Application
	{
	    public:
			Application(AbstractStateFactory & factory);
			void pushState(States::ID id);
			void run();
			
			
	    private:
			
			void processNetworkMessages();
			void updateModels(sf::Time dt);
			void processInputs();
			void updateViews(sf::Time dt);
			void render();
			
	    private:
			static const sf::Time TimePerFrame;
	        
			sf::Context mGLContext;//to create an OpenGL context before the window creation
			sf::RenderWindow mWindow;
			TextureHolder mTextureHolder;
			SoundHolder mSoundHolder;     
			
	        StateStackManager mStateStackManager;
			
			
			ModelHelper mModelHelper;
		    ViewHelper mViewHelper;
		    ControllerHelper mControllerHelper;
	};

}

#endif // APPLICATION_HPP
