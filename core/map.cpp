#include "map.hpp"

using namespace std;


Map::Map(){
    //taille arbitraire 20*20
    nbrows = 20;
    nbcols = 20;
    matrix = (int*)malloc(sizeof(int)*nbrows*nbcols);
    tile_size = 25; //provisoire

    textureHolder.load(Textures::Mapping, "assets/images/maptileset.bmp");

    spriteHerbe.setTexture(textureHolder.get(Textures::Mapping));
    spriteTerre.setTexture(textureHolder.get(Textures::Mapping));
    spriteHerbe.setTextureRect(sf::IntRect(10*tile_size, 1*tile_size, tile_size, tile_size));
    spriteTerre.setTextureRect(sf::IntRect(8*tile_size, 10*tile_size, tile_size, tile_size));

    //initialisation avec des 0
    for(int i = 0; i<(nbrows* nbrows); i++){
        matrix[i]=0;
    }
}

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
                case 0:
                    DisplayTile(render_win, i,j, spriteHerbe);
                     break;
                case 1:
                    DisplayTile(render_win, i,j, spriteTerre);
                     break;
                default: // error ?
                     break;
            }
         }
    }
}
