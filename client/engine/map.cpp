#include "map.hpp"
#include <iostream>

using namespace std;

using namespace Engine;

Map::Map(Engine::TextureHolder & textures, int nbCols, int nbRows){

    nbcols = nbRows;
    nbrows = nbCols; // Oh ta gueule toi...

    matrix = (int*)malloc(sizeof(int)*nbrows*nbcols);


    spriteHerbe.setTexture(textures.get(Textures::Mapping));
    spriteTerre.setTexture(textures.get(Textures::Mapping));
    spriteStone.setTexture(textures.get(Textures::Mapping));
    spriteHTupleft.setTexture(textures.get(Textures::Mapping));
    spriteHTupright.setTexture(textures.get(Textures::Mapping));
    spriteHTdownleft.setTexture(textures.get(Textures::Mapping));
    spriteHTdownright.setTexture(textures.get(Textures::Mapping));
    spriteHTupseg.setTexture(textures.get(Textures::Mapping));
    spriteHTdownseg.setTexture(textures.get(Textures::Mapping));
    spriteHTleftseg.setTexture(textures.get(Textures::Mapping));
    spriteHTrightseg.setTexture(textures.get(Textures::Mapping));

    spriteHerbe.setTextureRect(sf::IntRect(10*tileSize, 1*tileSize, tileSize, tileSize));
    spriteTerre.setTextureRect(sf::IntRect(3*tileSize, 4*tileSize, tileSize, tileSize));
    spriteStone.setTextureRect(sf::IntRect(5*tileSize, 7*tileSize, tileSize, tileSize));
    spriteHTupleft.setTextureRect(sf::IntRect(7*tileSize, 0*tileSize, tileSize, tileSize));
    spriteHTupright.setTextureRect(sf::IntRect(8*tileSize, 0*tileSize, tileSize, tileSize));
    spriteHTdownleft.setTextureRect(sf::IntRect(7*tileSize, 1*tileSize, tileSize, tileSize));
    spriteHTdownright.setTextureRect(sf::IntRect(8*tileSize, 1*tileSize, tileSize, tileSize));
    spriteHTupseg.setTextureRect(sf::IntRect(10*tileSize, 2*tileSize, tileSize, tileSize));
    spriteHTdownseg.setTextureRect(sf::IntRect(10*tileSize, 0*tileSize, tileSize, tileSize));
    spriteHTleftseg.setTextureRect(sf::IntRect(11*tileSize, 1*tileSize, tileSize, tileSize));
    spriteHTrightseg.setTextureRect(sf::IntRect(9*tileSize, 1*tileSize, tileSize, tileSize));

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

void Map::DisplayTile(sf::RenderTarget& render_win, int i, int j, sf::Sprite sp){
    sp.setPosition(i*tileSize, j*tileSize);
    render_win.draw(sp);
}

void Map::Display(sf::RenderTarget &render_win){

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
