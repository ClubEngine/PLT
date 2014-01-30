#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/System.hpp>

class Entity
{
	public:
		Entity();
		
		void setPosition(float x, float y);
		const sf::Vector2f & getPosition() const;
		
	private:
		sf::Vector2f mPosition;
};

#endif // ENTITY_HPP
