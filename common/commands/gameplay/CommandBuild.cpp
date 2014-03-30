#include "CommandBuild.hpp"

CommandBuild::CommandBuild(const sf::Vector2i &cordinates, const sf::Int32 &buildingType)
    : Command(BUILD), mCordinates(cordinates), mBuildingType(buildingType)
{
}

CommandBuild::CommandBuild(sf::Packet &packet)
	: Command(BUILD)
{
    packet >> mCordinates.x >> mCordinates.y >> mBuildingType;
}

void CommandBuild::specialPackStep(sf::Packet &packet) const
{
    packet << mCordinates.x << mCordinates.y << mBuildingType;
}

void CommandBuild::specialUnpackStep(sf::Packet &packet)
{
}
