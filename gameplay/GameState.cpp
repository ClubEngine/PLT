#include "GameState.hpp"
#include "core/map.hpp"
#include <iostream>
#include <cmath>
#include "gameplay/MyStates.hpp"

using namespace std;

GameState::GameState(StateStack &stack, Context &context)
    : State(stack, context), lol(100), tileSize(25), mouseispressed(false),
	  camera(*(context.window))
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
		
		sf::Vector2f mousepos = window.mapPixelToCoords(
									sf::Vector2i(event.mouseButton.x, event.mouseButton.y),
									camera.getView());

        float a = floor(mousepos.x/tileSize)*tileSize;
        float b = floor(mousepos.y/tileSize)*tileSize;

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
			sf::Vector2f f = window.mapPixelToCoords(
								 sf::Vector2i(event.mouseMove.x, event.mouseMove.y), 
								 camera.getView());
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
                // ERASE TILE LEAVING A BLANK ONE
                case sf::Keyboard::BackSpace : {
                     map->setTile(i,j,2);
                    break;
                }
                // CREATE DUST TILE
                case sf::Keyboard::T : {
                    map->setTile(i,j,1);
                    break;
                }
                // CREATE STONE TILE
                case sf::Keyboard::S : {
                    map->setTile(i,j,3);
                    break;
                }
                // CREATE GRASS TILE
                case sf::Keyboard::H : {
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
	
	camera.handleEvent(event);
	
	
	return false;
}

bool GameState::update(sf::Time dt)
{
	camera.update(dt);
	
	return true;
}

void GameState::draw()
{

    sf::RenderWindow & window = *getContext().window;

	window.setView(camera.getView());
	
    window.clear(sf::Color::White);

    map->Display(getContext().window);

    selection.setSize((sf::Vector2f)(selected.p2-selected.p1));
    selection.setPosition((sf::Vector2f)(selected.p1));
    window.draw(selection);

	
}
