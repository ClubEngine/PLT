#ifndef MOVABLEENTITY_HPP
#define MOVABLEENTITY_HPP

#include "Common.hpp"

class MovableEntity : public Entity
{
	public:
		MovableEntity();
		
		void setPosition(float x, float y);
		const sf::Vector2f & getPosition() const;
	
	protected:
		sf::Vector2f mPosition;
};

#endif // MOVABLEENTITY_HPP
