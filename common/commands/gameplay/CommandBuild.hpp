#ifndef COMMANDBUILD_HPP
#define COMMANDBUILD_HPP

#include "../core/Command.hpp"
#include "CommandsType.hpp"

class CommandBuild : public Command
{
	public:
		CommandBuild();
		CommandBuild(sf::Packet & packet);
		
	protected:
		virtual void specialPackStep(sf::Packet &packet) const;
		virtual void specialUnpackStep(sf::Packet &packet);
		
};

#endif // COMMANDBUILD_HPP
