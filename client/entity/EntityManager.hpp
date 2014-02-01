#ifndef ENTITYMANAGER_HPP
#define ENTITYMANAGER_HPP

#include <vector>
#include <SFML/System.hpp>
#include <SFML/Graphics/Rect.hpp>
#include "Entity.hpp"

typedef std::vector<Entity> EntityVector;

class EntityManager
{
	public:
		EntityManager();
		
		const EntityVector getSelectedEntity(const sf::FloatRect & selection) const;
		const EntityVector getAll() const;
		
		void add(Entity entity);
		
	private:
		
		EntityVector mAll;
		
		
};

#endif // ENTITYMANAGER_HPP
