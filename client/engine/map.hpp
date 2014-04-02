#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>
#include "engine/TextureHolder.hpp"
#include "engine/Context.hpp"

typedef sf::Vector2i MapCordinates;

class Map
{
    public:
        Map(Context &context, int nbcols, int nbrows);

        int getTile(int i,int j);
        void setTile(int i,int j, int state);
        void Display(sf::RenderWindow* render_win);

        const static int tileSize = 25;

    private:
        int* matrix;
        int nbrows;
        int nbcols;

        void DisplayTile(sf::RenderWindow* render_win, int i, int j, sf::Sprite sp);

        sf::Sprite spriteHerbe;
        sf::Sprite spriteTerre;
        sf::Sprite spriteStone;

        sf::Sprite spriteHTupleft;
        sf::Sprite spriteHTupright;
        sf::Sprite spriteHTdownright;
        sf::Sprite spriteHTdownleft;

        sf::Sprite spriteHTupseg;
        sf::Sprite spriteHTdownseg;
        sf::Sprite spriteHTleftseg;
        sf::Sprite spriteHTrightseg;
};


#endif // MAP_HPP
