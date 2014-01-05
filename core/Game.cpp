#include "Game.hpp"

using namespace std;

Game::Game()
{
    soundHolder = new SoundHolder();
    soundHolder->load(Sounds::Test, "assets/sounds/test.ogg");

    textureHolder = new TextureHolder();
    textureHolder->load(Textures::Patate,	"assets/images/patate.png");
    textureHolder->load(Textures::Rire,		"assets/images/canard.gif");

    mWindow = 0;
}

Game::~Game()
{
    delete textureHolder;
    delete soundHolder;

    if (mWindow != 0) {
        delete mWindow;
    }
}

int Game::createWindow()
{
    mWindow = new sf::RenderWindow(sf::VideoMode(800, 600), "PLT", sf::Style::Default, sf::ContextSettings(32));

    // @TODO: should be moved in the SoundManager
    // if (!mMusic.openFromFile("assets/sounds/music.ogg"))
    //     return -1;
    // mMusic.play();
    soundHolder->play(Sounds::Test);

    return 0;
}

sf::RenderWindow * Game::getWindow()
{
    return mWindow;
}

SoundHolder * Game::getSoundHolder()
{
    return soundHolder;
}

TextureHolder * Game::getTextureHolder()
{
    return textureHolder;
}
