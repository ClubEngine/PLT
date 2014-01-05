#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "../core/state/State.hpp"
#include "../core/map.hpp"

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
        };
        float aux;

        selected selected;

        int width, height;
        int tileSize;
        Map *map;

        sf::Texture grid;
        sf::Sprite gridsprite;
        sf::RectangleShape selection;
};


#endif // GAMESTATE_HPP
