#include "Entity.hpp"

Entity::Entity()
{
}

void Entity::setPosition(float x, float y)
{
	mPosition.x = x;
	mPosition.y = y;
}

const sf::Vector2f &Entity::getPosition() const
{
	return mPosition;
}
