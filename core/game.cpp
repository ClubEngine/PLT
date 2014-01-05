#include "game.hpp"

using namespace std;

Game::Game()
{
    cout << "test" << endl;
}

Game::~Game()
{
    delete mWindow;
}

void Game::createWindow()
{
    mWindow = new sf::RenderWindow(sf::VideoMode(800, 600), "PLT", sf::Style::Default, sf::ContextSettings(32));
}

sf::RenderWindow* Game::getWindow()
{
    return mWindow;
}
