#include "Game.hpp"

using namespace std;

Game::Game()
{
    soundHolder.load(Sounds::Test, "assets/sounds/test.ogg");

    textureHolder.load(Textures::Patate,	"assets/images/patate.png");
    textureHolder.load(Textures::Rire,		"assets/images/canard.gif");
	
}

Game::~Game()
{
    
}

int Game::createWindow()
{
    mWindow.create(sf::VideoMode(800, 600), 
				   "PLT", 
				   sf::Style::Default, sf::ContextSettings(32));

    // @TODO: should be moved in the SoundManager
    // if (!mMusic.openFromFile("assets/sounds/music.ogg"))
    //     return -1;
    // mMusic.play();
    //soundHolder->play(Sounds::Test);

    return 0;
}

sf::RenderWindow & Game::getWindow()
{
    return mWindow;
}

SoundHolder & Game::getSoundHolder()
{
    return soundHolder;
}

TextureHolder & Game::getTextureHolder()
{
    return textureHolder;
}
