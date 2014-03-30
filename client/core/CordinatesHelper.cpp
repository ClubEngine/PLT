#include <cmath>
#include "CordinatesHelper.hpp"

const MapCordinates& CordinatesHelper::getCordinated(const sf::Vector2f &realCordinated){
    MapCordinates cordinates;

    cordinates.x = floor(realCordinated.x/Map::tile_size)*Map::tile_size;
    cordinates.y = floor(realCordinated.y/Map::tile_size)*Map::tile_size;

    return cordinates;
}
