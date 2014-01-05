#include <iostream>
#include <SFML/Graphics.hpp>
#include "core/game.hpp"

#include "TextureHolder.hpp"

using namespace std;

int main(int argc, char ** argv) {

    cout << "Long Term Project " << __DATE__ << " at " << __TIME__ << endl;

    Game game;
    game.createWindow();
    game.getWindow()->setVerticalSyncEnabled(true);
    // /* or */window.setFramerateLimit(60);

	TextureHolder textureHolder;
	textureHolder.load(Textures::Patate,	"patate.png");
	//textureHolder.load(Textures::Rire,		"rire.png");
	
	sf::Sprite sp( textureHolder.get(Textures::Patate) );
	sf::Sprite sp2( textureHolder.get(Textures::Rire) );
	
    sf::Texture canardText;
    if (!canardText.loadFromFile("assets/images/canard.gif"))
    {
        cerr << "Erreur lors du chargement de la texture" << endl;
    }
    canardText.setSmooth(true);
    sf::Sprite canardSprite;
    canardSprite.setTexture(canardText);
    canardSprite.setScale(sf::Vector2f(0.2f, 0.2f));

    sf::CircleShape c;
    c.setRadius(10);
    c.setFillColor(sf::Color::Red);

    // run the main loop
    bool running = true;
    while (running) {

        sf::Event event;
        while (game.getWindow()->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                running = false;
            }
            else if (event.type == sf::Event::Resized) {
            }
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape)
                    running = false;
                if (event.key.code == sf::Keyboard::Up) {
                    canardSprite.move(0, -5);
                } else if (event.key.code == sf::Keyboard::Down) {
                    canardSprite.move(0, 5);
                } else if (event.key.code == sf::Keyboard::Left) {
                    canardSprite.move(-5, 0);
                } else if (event.key.code == sf::Keyboard::Right) {
                    canardSprite.move(5, 0);
                }
            }
            else if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Up) {
                } else if (event.key.code == sf::Keyboard::Down) {
                } else if (event.key.code == sf::Keyboard::Left) {
                } else if (event.key.code == sf::Keyboard::Right) {
                }
            }
            else if (event.type == sf::Event::MouseMoved) {
                //event.mouseMove.x
                //event.mouseMove.y
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                //event.mouseButton.button == sf::Mouse::Left
            }
            else if (event.type == sf::Event::MouseButtonReleased) {
            }
        }

        game.getWindow()->clear();
        game.getWindow()->draw(sp);
        game.getWindow()->draw(sp2);
        game.getWindow()->draw(c);
        game.getWindow()->draw(canardSprite);
        game.getWindow()->display();
    }

    return 0;
}

