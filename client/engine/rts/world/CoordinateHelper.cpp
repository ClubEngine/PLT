#include <cmath>
#include "CoordinateHelper.hpp"

const MapCoordinates& CoordinateHelper::getCoordinates(const sf::Vector2f &realCoordinates){
    MapCoordinates cordinates;

    cordinates.x = floor(realCoordinates.x/Map::tileSize)*Map::tileSize;
    cordinates.y = floor(realCoordinates.y/Map::tileSize)*Map::tileSize;

    return cordinates;
}
