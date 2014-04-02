#include <cmath>
#include "CordinatesHelper.hpp"

const MapCordinates& CordinatesHelper::getCordinated(const sf::Vector2f &realCordinated){
    MapCordinates cordinates;

    cordinates.x = floor(realCordinated.x/Map::tileSize)*Map::tileSize;
    cordinates.y = floor(realCordinated.y/Map::tileSize)*Map::tileSize;

    return cordinates;
}
