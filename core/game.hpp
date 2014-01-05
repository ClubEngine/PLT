#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

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
