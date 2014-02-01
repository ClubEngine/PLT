#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/System.hpp>

typedef sf::Uint32 EntityId;

class Entity
{
	public:
		Entity();
		
		void setPosition(float x, float y);
		const sf::Vector2f & getPosition() const;
		
		const EntityId getId() const;
		
	private:
		sf::Vector2f mPosition;
		EntityId mId;
};

#endif // ENTITY_HPP
