#ifndef COMMANDBUILD_HPP
#define COMMANDBUILD_HPP

#include "../core/Command.hpp"
#include "CommandsType.hpp"

class CommandBuild : public Command
{
	public:
        CommandBuild(const sf::Vector2i &cordinates,  const sf::Int32 &buildingType);
		CommandBuild(sf::Packet & packet);
		
	protected:
		virtual void specialPackStep(sf::Packet &packet) const;
		virtual void specialUnpackStep(sf::Packet &packet);

    private:
        sf::Vector2i mCordinates;
        sf::Int32 mBuildingType;
};

#endif // COMMANDBUILD_HPP
