#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "SoundHolder.hpp"
#include "TextureHolder.hpp"

class Game
{
    public:
        Game();

        int createWindow();
        sf::RenderWindow & getWindow();
        SoundHolder & getSoundHolder();
        TextureHolder & getTextureHolder();

        virtual ~Game();

    private:
        sf::Music mMusic;

		sf::Context mContext;//to create an OpenGL context before the window creation
        sf::RenderWindow mWindow;
        SoundHolder soundHolder;
        TextureHolder textureHolder;
};

#endif // GAME_HPP
