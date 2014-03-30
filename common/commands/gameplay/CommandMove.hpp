#ifndef COMMANDMOVE_HPP
#define COMMANDMOVE_HPP

#include <SFML/System/Vector2.hpp>
#include "../core/Command.hpp"
#include "CommandsType.hpp"

#include "../../entity/Entity.hpp"

class CommandMove : public Command
{
	public:
		CommandMove(const EntityVector &entities, const sf::Vector2f &target);
		CommandMove(sf::Packet & packet);
		
	protected:
		virtual void specialPackStep(sf::Packet &packet) const;
		virtual void specialUnpackStep(sf::Packet &packet);
		
	//private:
	// test
	public:
		std::vector<EntityId> mIds;
		sf::Vector2f mTarget;
};

#endif // COMMANDMOVE_HPP
