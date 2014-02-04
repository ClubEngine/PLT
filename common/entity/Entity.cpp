#include "Entity.hpp"

EntityId Entity::stNextId = 0;

Entity::Entity() : mId(stNextId++)
{
}

const EntityId Entity::getId() const
{
	return mId;
}

Entity::~Entity()
{
}
