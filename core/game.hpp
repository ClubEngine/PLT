#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Game
{
    public:
        Game();

        int createWindow();
        sf::RenderWindow* getWindow();

        virtual ~Game();

    private:
        sf::RenderWindow* mWindow;
        sf::Music mMusic;
};

#endif // GAME_HPP
