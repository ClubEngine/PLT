#ifndef COMMANDMOVE_HPP
#define COMMANDMOVE_HPP

#include <SFML/System/Vector2.hpp>
#include "../../core/network/Command.hpp"
#include "../../entity/EntityManager.hpp"

class MyCommandFactory;

class CommandMove : public Command
{
	public:
		CommandMove(const EntityVector &entities, const sf::Vector2f &target);
	private:
		std::vector<EntityId> mIds;
		sf::Vector2f mTarget;
		
		friend class MyCommandFactory;
};

#endif // COMMANDMOVE_HPP
