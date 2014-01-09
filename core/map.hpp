#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>
#include "core/TextureHolder.hpp"
#include "core/Context.hpp"

class Map
{
    public:
        Map(Context &context, int nbcols, int nbrows);

        int getTile(int i,int j);
        void setTile(int i,int j, int state);
        void Display(sf::RenderWindow* render_win);

    private:
        int* matrix;
        int nbrows;
        int nbcols;
        int tile_size;
        void DisplayTile(sf::RenderWindow* render_win, int i, int j, sf::Sprite sp);

        sf::Sprite spriteHerbe;
        sf::Sprite spriteTerre;
        sf::Sprite spriteStone;
};


#endif // MAP_HPP
