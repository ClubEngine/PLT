#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <vector>
#include <SFML/System.hpp>

typedef sf::Uint32 EntityId;
typedef std::vector<EntityId> EntityIdVector;

class Entity
{
	public:
		Entity();
		
		EntityId getId() const;
		
		virtual ~Entity();
		
	private:
		EntityId mId;
		
		static EntityId stNextId;
};

typedef std::vector<Entity*> EntityVector;

#endif // ENTITY_HPP
