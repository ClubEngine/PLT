#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>

#include <SFML/Graphics.hpp>

class Game
{
public:
    Game();
    virtual ~Game();

    void createWindow();
    sf::RenderWindow* getWindow();

private:
    sf::RenderWindow* mWindow;
};

#endif // GAME_HPP
