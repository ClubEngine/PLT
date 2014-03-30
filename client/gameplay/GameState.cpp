#include "GameState.hpp"
#include "core/map.hpp"
#include "core/CordinatesHelper.hpp"
#include <iostream>
#include <cmath>
#include "gameplay/MyStates.hpp"
#include "../common/commands/gameplay/CommandMove.hpp"
#include "../common/commands/gameplay/CommandBuild.hpp"

using namespace std;

GameState::GameState(StateStack &stack, Context &context)
    : State(stack, context), mouseispressed(false),
	  camera(*(context.window)), netInterface(),
	  entities()
{
	//getContext().textures.load(Textures::Patate, "assets/images/patate.png");
    width = getContext().window->getSize().x;
    height = getContext().window->getSize().y;

    //cerr << width/Map::tile_size << "," << height/Map::tile_size << endl;
    map = new Map(context, width/Map::tileSize, height/Map::tileSize);
    //map = new Map(context, 20, 20);

    selection.setFillColor(sf::Color(255,0,0,63));
    selection.setOutlineThickness(0.5);
    selection.setOutlineColor(sf::Color::White);

    upright.setFillColor(sf::Color(255,0,0,188));
    upright.setOutlineThickness(0.5);
    upright.setOutlineColor(sf::Color::White);

    upleft.setFillColor(sf::Color(255,0,0,188));
    upleft.setOutlineThickness(0.5);
    upleft.setOutlineColor(sf::Color::White);

    downright.setFillColor(sf::Color(255,0,0,188));
    downright.setOutlineThickness(0.5);
    downright.setOutlineColor(sf::Color::White);

    downleft.setFillColor(sf::Color(255,0,0,188));
    downleft.setOutlineThickness(0.5);
    downleft.setOutlineColor(sf::Color::White);

    upseg.setFillColor(sf::Color(255,0,0,125));
    upseg.setOutlineThickness(0.5);
    upseg.setOutlineColor(sf::Color::White);

    downseg.setFillColor(sf::Color(255,0,0,125));
    downseg.setOutlineThickness(0.5);
    downseg.setOutlineColor(sf::Color::White);

    leftseg.setFillColor(sf::Color(255,0,0,125));
    leftseg.setOutlineThickness(0.5);
    leftseg.setOutlineColor(sf::Color::White);

    rightseg.setFillColor(sf::Color(255,0,0,125));
    rightseg.setOutlineThickness(0.5);
    rightseg.setOutlineColor(sf::Color::White);
	
	// ***
	
	netInterface.init("localhost", 55001);
	
	MovableEntity * entity;
	entity = new MovableEntity(); entity->setPosition(0,0); entities.add(entity);
	entity = new MovableEntity(); entity->setPosition(100,10); entities.add(entity);
	entity = new MovableEntity(); entity->setPosition(10,100); entities.add(entity);
}

bool GameState::handleEvent(const sf::Event &event)
{
	sf::RenderWindow & window = *getContext().window;
	
    switch (event.type) {
    case sf::Event::MouseButtonPressed :
    {
			if (event.mouseButton.button == sf::Mouse::Left) {
				mouseispressed = true;
				
				sf::Vector2f mousepos = window.mapPixelToCoords(
											sf::Vector2i(event.mouseButton.x, event.mouseButton.y),
											camera.getView());
		
                float a = floor(mousepos.x/Map::tileSize)*Map::tileSize;
                float b = floor(mousepos.y/Map::tileSize)*Map::tileSize;
		
				selected.i1.x = a;
				selected.i1.y = b;
                selected.i2.x = selected.i1.x+Map::tileSize;
                selected.i2.y = selected.i1.y+Map::tileSize;
		
				selected.p1 = selected.i1;
				selected.p2 = selected.i2;
			} else if (event.mouseButton.button == sf::Mouse::Right) {
				const EntityVector & selectedEntities = entities.getAll(); // test with all
				sf::Vector2f target = window.mapPixelToCoords(
										  sf::Vector2i(event.mouseButton.x, 
													   event.mouseButton.y));
				
				CommandMove command(selectedEntities, target);
				netInterface.send(command);
				//cout << "MOVE send" << endl;
			}

        break;
    }
    case sf::Event::MouseMoved :
    {
        if (mouseispressed){
			sf::Vector2f f = window.mapPixelToCoords(
								 sf::Vector2i(event.mouseMove.x, event.mouseMove.y), 
								 camera.getView());
            sf::Vector2i f1 = CordinatesHelper::getCordinated(f);
            //sf::Vector2i f1= sf::Vector2i(floor(f.x/Map::tile_size)*Map::tile_size,floor(f.y/Map::tile_size)*Map::tile_size);
            sf::Vector2i f2= f1 + sf::Vector2i(Map::tileSize,Map::tileSize);
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


        for (int i = selected.p1.x/Map::tileSize ; i < selected.p2.x/Map::tileSize ; i++)
        {
            for (int j = selected.p1.y/Map::tileSize ; j < selected.p2.y/Map::tileSize ; j++)
            {
                switch (event.key.code)
                {
                // ERASE TILE LEAVING A BLANK ONE
                case sf::Keyboard::BackSpace : {
                     map->setTile(i,j,0);
                    break;
                }
                // CREATE GRASS TILE
                case sf::Keyboard::H : {
                     map->setTile(i,j,1);
                    break;
                }
                // CREATE SOIL TILE
                case sf::Keyboard::T : {
                    if ( j == selected.p1.y/Map::tileSize ) {
                        if ( i == selected.p1.x/Map::tileSize )
                            map->setTile(i,j,11);
                        else if ( i == selected.p2.x/Map::tileSize-1 )
                            map->setTile(i,j,12);
                        else
                            map->setTile(i,j,15);
                    } else if ( j == selected.p2.y/Map::tileSize-1 ) {
                        if ( i == selected.p1.x/Map::tileSize )
                            map->setTile(i,j,14);
                        else if ( i == selected.p2.x/Map::tileSize-1 )
                            map->setTile(i,j,13);
                        else
                            map->setTile(i,j,16);
                    } else {
                        if ( i == selected.p1.x/Map::tileSize )
                            map->setTile(i,j,17);
                        else if ( i == selected.p2.x/Map::tileSize-1 )
                            map->setTile(i,j,18);
                        else
                            map->setTile(i,j,2);
                    }

                    if ( selected.p1.x == selected.p2.x + Map::tileSize ) {
                      map->setTile(i,j,2);
                    } // normalement ici je verifie que si on selectionne juste une
                      // case je met la tile 2 mais il veux pas pour je ne sais quelle
                      // raison :-(
                   break;
                }

                // Create building
                case sf::Keyboard::B : {
                    cout << "Here" <<endl;
                    CommandBuild command(selected.p1, 0);
                    netInterface.send(command);
                    break;
                }
                // CREATE STONE TILE
                case sf::Keyboard::S : {
                    map->setTile(i,j,3);
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
	
	{
		sf::Packet packet;
		bool hasone=false;
		while (netInterface.getPacket(packet)) {
			hasone = true;
			std::cout << "* Receive : ";
			std::string s;
			if (packet >> s)
				std::cout << s;
			cout << endl;
			s = "Patate !";
			packet.clear();
			packet << s;
			netInterface.send(packet);
			netInterface.send(packet);
			netInterface.send(packet);
		}
		if (hasone)
			std::cout << "end" << endl;
	}
	
	
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
	
	{
		sf::RectangleShape sprite(sf::Vector2f(32,32));
		sprite.setFillColor(sf::Color(255,128,64));
		const EntityVector & allEntities = entities.getAll();
		for(EntityVector::const_iterator it = allEntities.begin();
			it != allEntities.end(); ++it) {
			const MovableEntity * mentity = dynamic_cast<const MovableEntity*>(*it);
			if (mentity != 0) {
				sprite.setPosition(mentity->getPosition());
				window.draw(sprite);
			}
		}
	}

    upleft.setSize(sf::Vector2f(Map::tileSize,Map::tileSize));
    upright.setSize(sf::Vector2f(Map::tileSize,Map::tileSize));
    downright.setSize(sf::Vector2f(Map::tileSize,Map::tileSize));
    downleft.setSize(sf::Vector2f(Map::tileSize,Map::tileSize));

    upleft.setPosition(selected.p1.x, selected.p1.y);
    upright.setPosition(selected.p2.x-Map::tileSize, selected.p1.y);
    downright.setPosition(selected.p2.x-Map::tileSize, selected.p2.y-Map::tileSize);
    downleft.setPosition(selected.p1.x, selected.p2.y-Map::tileSize);


    upseg.setSize(sf::Vector2f(selected.p2.x-selected.p1.x-2*Map::tileSize,Map::tileSize));
    downseg.setSize(sf::Vector2f(selected.p2.x-selected.p1.x-2*Map::tileSize,Map::tileSize));
    leftseg.setSize(sf::Vector2f(Map::tileSize,selected.p2.y-selected.p1.y-2*Map::tileSize));
    rightseg.setSize(sf::Vector2f(Map::tileSize,selected.p2.y-selected.p1.y-2*Map::tileSize));

    upseg.setPosition(selected.p1.x+Map::tileSize,selected.p1.y);
    downseg.setPosition(selected.p1.x+Map::tileSize,selected.p2.y-Map::tileSize);
    leftseg.setPosition(selected.p1.x,selected.p1.y+Map::tileSize);
    rightseg.setPosition(selected.p2.x-Map::tileSize,selected.p1.y+Map::tileSize);


    selection.setSize(sf::Vector2f(selected.p2.x-selected.p1.x-2*Map::tileSize,selected.p2.y-selected.p1.y-2*Map::tileSize));

    selection.setPosition(selected.p1.x+Map::tileSize,selected.p1.y+Map::tileSize);

    window.draw(selection);
    window.draw(upright);
    window.draw(upleft);
    window.draw(downleft);
    window.draw(downright);
    window.draw(upseg);
    window.draw(downseg);
    window.draw(leftseg);
    window.draw(rightseg);

	
}
