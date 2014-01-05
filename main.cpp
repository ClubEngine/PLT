#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "core/state/StateStack.hpp"
#include "gameplay/CStateFactory.hpp"
#include "core/Context.hpp"
#include "core/Application.hpp"
#include "core/TextureHolder.hpp"
#include "core/map.hpp"

using namespace std;

int main(int argc, char ** argv) {

    cout << "Long Term Project " << __DATE__ << " at " << __TIME__ << endl;
	
    Application application;
    application.createWindow();
    application.getWindow().setVerticalSyncEnabled(true);
    // or application.getWindow()->setFramerateLimit(60);

    Context context(application.getWindow(), application.getTextureHolder(),
                    application.getSoundHolder());
	
	CStateFactory factory;
	StateStack stack(factory, context);
    stack.pushState(States::Title);
	stack.pushState(States::Game);
	
    sf::Sprite sp(application.getTextureHolder().get(Textures::Patate));
    
    sf::Sprite canardSprite;
    canardSprite.setTexture(application.getTextureHolder().get(Textures::Rire));
    canardSprite.setScale(sf::Vector2f(0.2f, 0.2f));

    Map* carte = new Map();
    carte->setTile(1,1,1); // on place une terre


    // run the main loop
    bool running = true;
    while (running) {

        sf::Event event;
        while (application.getWindow().pollEvent(event)) {
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
				
			stack.handleEvent(event);
        }

        // *** AFFICHAGE ***
        application.getWindow().clear();
        stack.draw();
        //carte->Display(application.getWindow());
        application.getWindow().draw(canardSprite);
        application.getWindow().display();
    }

    return 0;
}

