#include "map.hpp"
#include <iostream>

using namespace std;


Map::Map(Context &context, int nbCols, int nbRows){

    nbcols = nbRows;
    nbrows = nbCols; // Oh ta gueule toi...

    matrix = (int*)malloc(sizeof(int)*nbrows*nbcols);


    spriteHerbe.setTexture(context.textures->get(Textures::Mapping));
    spriteTerre.setTexture(context.textures->get(Textures::Mapping));
    spriteStone.setTexture(context.textures->get(Textures::Mapping));
    spriteHTupleft.setTexture(context.textures->get(Textures::Mapping));
    spriteHTupright.setTexture(context.textures->get(Textures::Mapping));
    spriteHTdownleft.setTexture(context.textures->get(Textures::Mapping));
    spriteHTdownright.setTexture(context.textures->get(Textures::Mapping));
    spriteHTupseg.setTexture(context.textures->get(Textures::Mapping));
    spriteHTdownseg.setTexture(context.textures->get(Textures::Mapping));
    spriteHTleftseg.setTexture(context.textures->get(Textures::Mapping));
    spriteHTrightseg.setTexture(context.textures->get(Textures::Mapping));

    spriteHerbe.setTextureRect(sf::IntRect(10*tile_size, 1*tile_size, tile_size, tile_size));
    spriteTerre.setTextureRect(sf::IntRect(3*tile_size, 4*tile_size, tile_size, tile_size));
    spriteStone.setTextureRect(sf::IntRect(5*tile_size, 7*tile_size, tile_size, tile_size));
    spriteHTupleft.setTextureRect(sf::IntRect(7*tile_size, 0*tile_size, tile_size, tile_size));
    spriteHTupright.setTextureRect(sf::IntRect(8*tile_size, 0*tile_size, tile_size, tile_size));
    spriteHTdownleft.setTextureRect(sf::IntRect(7*tile_size, 1*tile_size, tile_size, tile_size));
    spriteHTdownright.setTextureRect(sf::IntRect(8*tile_size, 1*tile_size, tile_size, tile_size));
    spriteHTupseg.setTextureRect(sf::IntRect(10*tile_size, 2*tile_size, tile_size, tile_size));
    spriteHTdownseg.setTextureRect(sf::IntRect(10*tile_size, 0*tile_size, tile_size, tile_size));
    spriteHTleftseg.setTextureRect(sf::IntRect(11*tile_size, 1*tile_size, tile_size, tile_size));
    spriteHTrightseg.setTextureRect(sf::IntRect(9*tile_size, 1*tile_size, tile_size, tile_size));

    //initialisation avec des 0
    for(int i = 0; i<(nbcols * nbrows); i++){
        matrix[i]=1;
    }
}

// i : Ligne
// j : Colonne
int Map::getTile(int i, int j){
    return matrix[i*nbcols + j];
}

void Map::setTile(int i, int j, int state){
    matrix[i*nbcols +j] = state;
}

void Map::DisplayTile(sf::RenderWindow* render_win, int i, int j, sf::Sprite sp){
    sp.setPosition(i*tile_size, j*tile_size);
    render_win->draw(sp);
}

void Map::Display(sf::RenderWindow* render_win){

    for(int i = 0; i<nbrows; i++){
        for(int j = 0; j<nbcols; j++){
            switch(getTile(i,j)){
            case 1:
                    DisplayTile(render_win, i,j, spriteHerbe);
                     break;
            case 11:
                DisplayTile(render_win, i,j, spriteHTupleft);
                break;
            case 12:
                DisplayTile(render_win, i,j, spriteHTupright);
                break;
            case 13:
                DisplayTile(render_win, i,j, spriteHTdownright);
                break;
            case 14:
                DisplayTile(render_win, i,j, spriteHTdownleft);
                break;

            case 15:
                DisplayTile(render_win, i,j, spriteHTupseg);
                break;
            case 16:
                DisplayTile(render_win, i,j, spriteHTdownseg);
                break;
            case 17:
                DisplayTile(render_win, i,j, spriteHTleftseg);
                break;
            case 18:
                DisplayTile(render_win, i,j, spriteHTrightseg);
                break;

                case 2:
                    DisplayTile(render_win, i,j, spriteTerre);
                     break;
                case 3:
                    DisplayTile(render_win, i,j, spriteStone);
                    break;
                default: // error ?
                     break;
            }
         }
    }
}
