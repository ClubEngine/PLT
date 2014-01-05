#include "GameState.hpp"
#include <iostream>
#include <cmath>

using namespace std;

GameState::GameState(StateStack &stack, Context &context)
    : State(stack, context), lol(100), tileSize(10), mouseispressed(false)
{
	//getContext().textures.load(Textures::Patate, "assets/images/patate.png");
    width = getContext().window.getSize().x;
    height = getContext().window.getSize().y;

    // map.init();
    for (int i = 0 ; i < width/10 ; i++)
    {
        for (int j = 0 ; j < height/10 ; j++)
        {
            map[i][j] = 0;
        }
    };

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
    switch (event.type) {
    case sf::Event::Closed :
    {
        getContext().window.close();
        break;
    }
    case sf::Event::MouseButtonPressed :
    {
        mouseispressed = true;

        float a = floor((float)event.mouseButton.x/10.0)*10.0;
        float b = floor((float)event.mouseButton.y/10.0)*10.0;

        selected.p1.x = a;
        selected.p1.y = b;
        selected.p2.x = a+10;
        selected.p2.y = b+10;

        break;
    }
    case sf::Event::MouseMoved :
    {
        if (mouseispressed){
            selected.p2.x = ceil(sf::Mouse::getPosition(getContext().window).x/10.0)*10.0;
            selected.p2.y = ceil(sf::Mouse::getPosition(getContext().window).y/10.0)*10.0;
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
        for (int i = selected.p1.x/10 ; i < selected.p2.x/10 ; i++)
        {
            for (int j = selected.p1.y/10 ; j < selected.p2.y/10 ; j++)
            {
                switch (event.key.code)
                {
                case sf::Keyboard::H : {
                    map[i][j] = 1;
                    break;
                }
                case sf::Keyboard::R : {
                    map[i][j] = 2;
                    break;
                }
                case sf::Keyboard::P : {
                    map[i][j] = 3;
                    break;
                }
                case sf::Keyboard::BackSpace : {
                    map[i][j] = 0;
                    break;
                }
                }
            }
        }
        break;
    }
    default:
        break;
    }
}

bool GameState::update(sf::Time dt)
{
}

void GameState::draw()
{
    getContext().window.clear(sf::Color::White);

    // map.draw();
    for (int i = 0 ; i < width/10 ; i++)
    {
        for (int j = 0 ; j < height/10 ; j++)
        {
            switch (map[i][j]) {
            case 1:
            {
                sf::RectangleShape text(sf::Vector2f(10,10));
                text.setFillColor(sf::Color(50,200,50));
                text.setPosition(sf::Vector2f(i*10, j*10));
                getContext().window.draw(text);
                break;
            }
            case 2:
            {
                sf::RectangleShape text(sf::Vector2f(10,10));
                text.setFillColor(sf::Color(150,150,150));
                text.setPosition(sf::Vector2f(i*10, j*10));
                getContext().window.draw(text);
                break;
            }
            case 3:
            {
                sf::RectangleShape text(sf::Vector2f(10,10));
                text.setFillColor(sf::Color(50,200,50));
                text.setPosition(sf::Vector2f(i*10, j*10));
                getContext().window.draw(text);
                break;
            }
            default:
                break;
            }
        }
    };
    getContext().window.draw(gridsprite);

    selection.setSize((sf::Vector2f)(selected.p2-selected.p1));
    selection.setPosition((sf::Vector2f)selected.p1);
    getContext().window.draw(selection);

	sf::Sprite sp( getContext().textures.get(Textures::Patate) );
	sp.setPosition(lol,lol);
	lol+=1;
	
	getContext().window.draw(sp);
	
}
