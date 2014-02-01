#include "EntityManager.hpp"

EntityManager::EntityManager() :
	mAll()
{
}

const EntityVector EntityManager::getSelectedEntity(const sf::FloatRect &selection) const
{
	EntityVector selectedEntities;
	
	// selection.contains()
	
	return selectedEntities;
}

const EntityVector EntityManager::getAll() const
{
	return mAll;
}

void EntityManager::add(Entity entity)
{
	mAll.push_back(entity);
}
