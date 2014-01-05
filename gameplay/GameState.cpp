#include "GameState.hpp"
#include "core/map.hpp"
#include <iostream>
#include <cmath>

using namespace std;

GameState::GameState(StateStack &stack, Context &context)
    : State(stack, context), lol(100), tileSize(25), mouseispressed(false)
{
	//getContext().textures.load(Textures::Patate, "assets/images/patate.png");
    width = getContext().window->getSize().x;
    height = getContext().window->getSize().y;

    map = new Map();

    if (!grid.loadFromFile("assets/images/grid.png", sf::IntRect(0,0,width,height)))
    {
        cerr << "Unable to load grid file." << endl;
    }

    gridsprite.setTexture(grid);

    selection.setSize(sf::Vector2f(10,10));
    selection.setFillColor(sf::Color(255,0,0,127));
    selection.setOutlineThickness(0.5);
    selection.setOutlineColor(sf::Color::White);
}

bool GameState::handleEvent(const sf::Event &event)
{
	sf::RenderWindow & window = *getContext().window;
	
    switch (event.type) {
    case sf::Event::Closed :
    {
        getContext().window->close();
        break;
    }
    case sf::Event::MouseButtonPressed :
    {
        mouseispressed = true;

        float a = floor((float)event.mouseButton.x/tileSize)*tileSize;
        float b = floor((float)event.mouseButton.y/tileSize)*tileSize;

        selected.p1.x = a;
        selected.p1.y = b;
        selected.p2.x = a+tileSize;
        selected.p2.y = b+tileSize;

        break;
    }
    case sf::Event::MouseMoved :
    {
        if (mouseispressed){
            selected.p2.x = ceil(sf::Mouse::getPosition(window).x/tileSize)*tileSize;
            selected.p2.y = ceil(sf::Mouse::getPosition(window).y/tileSize)*tileSize;
        }
        break;
    }
    case sf::Event::MouseButtonReleased :
    {
        if (selected.p1.x > selected.p2.x)
        {
            aux = selected.p1.x;
            selected.p1.x = selected.p2.x;
            selected.p2.x = aux;
        }

        if (selected.p1.y > selected.p2.y)
        {
            aux = selected.p1.y;
            selected.p1.y = selected.p2.y;
            selected.p2.y = aux;
        }

        if (selected.p2.x > width){
            selected.p2.x = width;
        }
        if (selected.p2.y > height){
            selected.p2.y = height;
        }

        if (selected.p1.x < 0){
            selected.p1.x = 0;
        }
        if (selected.p1.y < 0){
            selected.p1.y = 0;
        }
        mouseispressed = false;

        break;
    }
    case sf::Event::KeyPressed :
    {
        for (int i = selected.p1.x/tileSize ; i < selected.p2.x/tileSize ; i++)
        {
            for (int j = selected.p1.y/tileSize ; j < selected.p2.y/tileSize ; j++)
            {
                switch (event.key.code)
                {
                case sf::Keyboard::H : {
                    map->setTile(i,j,1);
                    break;
                }
                case sf::Keyboard::R : {
                     map->setTile(i,j,2);
                    break;
                }
                case sf::Keyboard::P : {
                    map->setTile(i,j,3);
                    break;
                }
                case sf::Keyboard::BackSpace : {
                    map->setTile(i,j,0);
                    break;
                }
					default:;
                }
            }
        }
        break;
    }
    default:
        break;
    }
	return false;
}

bool GameState::update(sf::Time dt)
{
	return true;
}

void GameState::draw()
{

	sf::RenderWindow & window = *getContext().window;

    map->Display(getContext().window);

    selection.setSize((sf::Vector2f)(selected.p2-selected.p1));
    selection.setPosition((sf::Vector2f)selected.p1);
    window.draw(selection);

	
}
