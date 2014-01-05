#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>

class Map
{
    public:
        Map(); //taille arbitraire 20*20

        int getTile(int i,int j);
        void setTile(int i,int j, int state);
        void Display(sf::RenderWindow* render_win);

    private:
        int* matrix;
        int nbrows;
        int nbcols;
        int tile_size;
        void DisplayTile(sf::RenderWindow* render_win, int i, int j, sf::Sprite sp);
};


#endif // MAP_HPP
