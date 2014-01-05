#include "map.hpp"
#include "core/TextureHolder.hpp"

using namespace std;


Map::Map(){
    //taille arbitraire 20*20
    nbrows = 20;
    nbcols = 20;
    matrix = (int*)malloc(sizeof(int)*nbrows*nbcols);
    tile_size = 25; //provisoire

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
    TextureHolder textureHolder;
    textureHolder.load(Textures::Mapping, "assets/images/maptileset.bmp");

    sf::Sprite spherbe(textureHolder.get(Textures::Mapping));
    sf::Sprite spterre(textureHolder.get(Textures::Mapping));
    spherbe.setTextureRect(sf::IntRect(10*tile_size, 1*tile_size, tile_size, tile_size));
    spterre.setTextureRect(sf::IntRect(8*tile_size, 10*tile_size, tile_size, tile_size));

    //sf::Sprite spherbe( textureHolder.get(Textures::Herbe) );
    //sf::Sprite spterre( textureHolder.get(Textures::Terre) );

    for(int i = 0; i<nbrows; i++){
        for(int j = 0; j<nbcols; j++){
            switch(getTile(i,j)){
                case 0:
                    DisplayTile(render_win, i,j, spherbe);
                     break;
                case 1:
                    DisplayTile(render_win, i,j, spterre);
                     break;
                default: // error ?
                     break;
            }
         }
    }
}
