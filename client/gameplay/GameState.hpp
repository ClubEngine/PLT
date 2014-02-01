#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "../core/state/State.hpp"
#include "../core/map.hpp"
#include "../core/Camera.hpp"
#include "../core/network/NetInterface.hpp"
#include "../entity/EntityManager.hpp"
#include "commands/MyCommandFactory.hpp"

class GameState : public State
{
	public:
		GameState(StateStack & stack, Context &context);
		
		virtual bool handleEvent(const sf::Event & event);
		virtual bool update(sf::Time dt);
		virtual void draw();
		
	private:
        int lol;

        bool mouseispressed;

        struct selected {
            sf::Vector2i p1;
            sf::Vector2i p2;
            sf::Vector2i i1;
            sf::Vector2i i2;
        };
        float aux;

        selected selected;

        int width, height;
        int tileSize;
        Map *map;

        sf::Texture grid;
        sf::Sprite gridsprite;
        sf::RectangleShape selection;
        sf::RectangleShape upleft;
        sf::RectangleShape upright;
        sf::RectangleShape downright;
        sf::RectangleShape downleft;
        sf::RectangleShape upseg;
        sf::RectangleShape rightseg;
        sf::RectangleShape leftseg;
        sf::RectangleShape downseg;
		
		Camera camera;
		NetInterface netInterface;
		EntityManager entities;
		MyCommandFactory commandFactory;
};


#endif // GAMESTATE_HPP
