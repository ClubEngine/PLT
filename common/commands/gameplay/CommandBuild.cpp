#include "CommandBuild.hpp"

CommandBuild::CommandBuild() 
	: Command(CT_BUILD)
{
}

CommandBuild::CommandBuild(sf::Packet &packet)
	: Command(CT_BUILD)
{
}

void CommandBuild::specialPackStep(sf::Packet &packet) const
{
}

void CommandBuild::specialUnpackStep(sf::Packet &packet)
{
}
