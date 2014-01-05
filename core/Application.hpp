#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "SoundHolder.hpp"
#include "TextureHolder.hpp"

class Application
{
    public:
        Application();

        int createWindow();
        sf::RenderWindow & getWindow();
        SoundHolder & getSoundHolder();
        TextureHolder & getTextureHolder();

        virtual ~Application();

    private:
        sf::Music mMusic;

		sf::Context mContext;//to create an OpenGL context before the window creation
        sf::RenderWindow mWindow;
        SoundHolder soundHolder;
        TextureHolder textureHolder;
};

#endif // APPLICATION_HPP
