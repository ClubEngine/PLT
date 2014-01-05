#include "game.hpp"

using namespace std;

Game::Game()
{
}

Game::~Game()
{
    delete mWindow;
}

int Game::createWindow()
{
    mWindow = new sf::RenderWindow(sf::VideoMode(800, 600), "PLT", sf::Style::Default, sf::ContextSettings(32));

    if (!mMusic.openFromFile("assets/sounds/music.ogg"))
        return -1;
    mMusic.play();

    return 0;
}

sf::RenderWindow* Game::getWindow()
{
    return mWindow;
}
