#include <iostream>
#include <SFML/Graphics.hpp>
#include "core/game.hpp"

using namespace std;

int main(int argc, char ** argv) {

    cout << "SFML2 Project" << __DATE__ << " à " << __TIME__ << endl;

    Game game;
    game.createWindow();

    game.getWindow()->setVerticalSyncEnabled(true);
    // /* or */window.setFramerateLimit(60);

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

        game.getWindow()->clear();
        game.getWindow()->draw(c);
        game.getWindow()->display();
    }

    return 0;
}

