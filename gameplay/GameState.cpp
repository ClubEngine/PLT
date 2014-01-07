#include "GameState.hpp"
#include "core/map.hpp"
#include <iostream>
#include <cmath>
#include "gameplay/MyStates.hpp"

using namespace std;

GameState::GameState(StateStack &stack, Context &context)
    : State(stack, context), lol(100), tileSize(25), mouseispressed(false)
{
	//getContext().textures.load(Textures::Patate, "assets/images/patate.png");
    width = getContext().window->getSize().x;
    height = getContext().window->getSize().y;

    //cerr << width/tileSize << "," << height/tileSize << endl;
    map = new Map(context, width/tileSize, height/tileSize);
    //map = new Map(context, 20, 20);

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
        requestStateClear();
        break;
    }
    case sf::Event::MouseButtonPressed :
    {
        mouseispressed = true;

        float a = floor((float)event.mouseButton.x/tileSize)*tileSize;
        float b = floor((float)event.mouseButton.y/tileSize)*tileSize;

        selected.i1.x = a;
        selected.i1.y = b;
        selected.i2.x = selected.i1.x+tileSize;
        selected.i2.y = selected.i1.y+tileSize;

        selected.p1 = selected.i1;
        selected.p2 = selected.i2;

        break;
    }
    case sf::Event::MouseMoved :
    {
        if (mouseispressed){
            sf::Vector2i f = sf::Mouse::getPosition(window);
            sf::Vector2i f1= sf::Vector2i(floor(f.x/tileSize)*tileSize,floor(f.y/tileSize)*tileSize);
            sf::Vector2i f2= f1 + sf::Vector2i(tileSize,tileSize);
            selected.p1.x = min(min(selected.i1.x,selected.i2.x),min(f1.x,f2.x));
            selected.p2.x = max(max(selected.i1.x,selected.i2.x),max(f1.x,f2.x));
            selected.p1.y = min(min(selected.i1.y,selected.i2.y),min(f1.y,f2.y));
            selected.p2.y = max(max(selected.i1.y,selected.i2.y),max(f1.y,f2.y));
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
		if (event.key.code == sf::Keyboard::P)
		{
			requestStackPush(States::Pause);
		}
			
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

    window.clear(sf::Color::White);

    map->Display(getContext().window);

    selection.setSize(sf::Vector2f(selected.p2.x-selected.p1.x,selected.p2.y-selected.p1.y));
    selection.setPosition(sf::Vector2f(selected.p1));
    window.draw(selection);

	
}
