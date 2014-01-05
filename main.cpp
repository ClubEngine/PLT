#include <iostream>
#include <SFML/Graphics.hpp>

#include "TextureHolder.hpp"

using namespace std;

int main(int argc, char ** argv) {

    cout << "Long Term Project " << __DATE__ << " at " << __TIME__ << endl;


    sf::RenderWindow window(
                sf::VideoMode(800, 600), "Title", sf::Style::Default);

    window.setVerticalSyncEnabled(true);
    // /* or */window.setFramerateLimit(60);

	TextureHolder textureHolder;
	textureHolder.load(Textures::Patate,	"patate.png");
	//textureHolder.load(Textures::Rire,		"rire.png");
	
	sf::Sprite sp( textureHolder.get(Textures::Patate) );
	sf::Sprite sp2( textureHolder.get(Textures::Rire) );
	
    // run the main loop
    bool running = true;
    while (running) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                running = false;
            }
            else if (event.type == sf::Event::Resized) {
            }
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape)
                    running = false;
                if (event.key.code == sf::Keyboard::Up) {
                } else if (event.key.code == sf::Keyboard::Down) {
                } else if (event.key.code == sf::Keyboard::Left) {
                } else if (event.key.code == sf::Keyboard::Right) {
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

        window.clear();
        window.draw(sp);
		window.draw(sp2);
        window.display();
    }

    return 0;
}

