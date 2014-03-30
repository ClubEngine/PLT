#include "CommandBuild.hpp"

CommandBuild::CommandBuild() 
	: Command(BUILD)
{
}

CommandBuild::CommandBuild(sf::Packet &packet)
	: Command(BUILD)
{
}

void CommandBuild::specialPackStep(sf::Packet &packet) const
{
}

void CommandBuild::specialUnpackStep(sf::Packet &packet)
{
}
