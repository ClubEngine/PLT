#include "MovableEntity.hpp"

MovableEntity::MovableEntity()
{
}

void MovableEntity::setPosition(float x, float y)
{
	mPosition.x = x;
	mPosition.y = y;
}

const sf::Vector2f & MovableEntity::getPosition() const
{
	return mPosition;
}
