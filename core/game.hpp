#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>

#include <SFML/Graphics.hpp>

class Game
{
    public:
        Game();

        void createWindow();
        sf::RenderWindow* getWindow();

        virtual ~Game();

    private:
        sf::RenderWindow* mWindow;
};

#endif // GAME_HPP
